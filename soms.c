#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>
#include "sims.h"
#include "map_blocks.c"
#include "quality_of_life.c"


char *genders[] = {
    "female",
    "male",
    "etc"
};


char *surnames[] = {
    "Huhtanen",
    "Tóth",
    "Kovács",
    "Patócs",
    "Varga",
    "Renlund",
};


char *firstnames[] = {
    "Hanna",
    "Tamás",
    "Máté",
    "Bálint",
    "Zoltán",
    "Attila",
    "János",
    "Mihály"
};

char *map[100][100];


struct Likes {
    ulong          topics;
    ulong          drinks;
    ulong          foods;
};


struct Som {
    ushort         ID;
    char           *firstnames;
    char           *surnames;
    ushort         gender;
    ushort         age;
    struct Likes   likes;
    ushort         health;
    short          relationships[MAX_SOMS];
    
    // needs
    ushort         hunger;
    ushort         energy;
    ushort         social;
    ushort         hygiene;
    ushort         bladder;
    ushort         fun;
};


struct Som soms[MAX_SOMS];


void modify_relationship(struct Som *s1, struct Som *s2, short modifier) {
    s1->relationships[s2->ID] = s2->relationships[s1->ID] += modifier;
}


void conversation(struct Som *s1, struct Som *s2, ulong topic) {
    // get a random topic between 0-63
    if (!topic) topic = random() % 63;

    // if both likes OR both hates the topic
    if ((s1->likes.topics & topic) && (s2->likes.topics & topic)
    || !(s1->likes.topics & topic) && !(s2->likes.topics & topic)) {
        modify_relationship(s1, s2,  1);
    } else {
        modify_relationship(s1, s2, -1);
    }
}


void aging() {
    for (int i = 0; i < MAX_SOMS; i++) {

        if (!soms[i].health) continue;

        if (++soms[i].age >= 100) soms[i].health--;
        if (--soms[i].hunger <= 0) soms[i].health--;
        if (--soms[i].energy <= 0) soms[i].health--;
        --soms[i].hygiene;
    }
}


void clear_level(char *map[LEVEL_HEIGHT][LEVEL_WIDTH], int rows){
    if (rows == 0) rows = LEVEL_HEIGHT;
    for (int i = 0; i < LEVEL_HEIGHT && i <= rows; i++) {
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            map[i][j] = NULL;
        }
    }
}


void load_level(const char* level) {
    FILE *fp = fopen(level, "r");
    ulong len = 0;
    char *buffer = NULL;

    if (fp) {
        fseek(fp,0,SEEK_END);
        len = ftell(fp);

        fseek(fp, 0, SEEK_SET);
        buffer = malloc(len+1);
        if (buffer) {
            fread(buffer, 1, len, fp);
        }
        fclose (fp);
    }

    if (buffer) {
        char *original_buffer = buffer,
                        *line = NULL,
                        *cell = NULL;
        int i = 0, 
            j = 0;

        #ifdef DEBUG
            printf("parsing %s into a 100x100 array\n", level);
        #endif

        while ((line = strsep(&buffer, "\n")) != NULL) {
            while ((cell = strsep(&line, ",")) != NULL) {
                if (j == 0 && strcmp(cell, "##map starts below##") == 0) {
                    #ifdef DEBUG
                        printf("resetting row=0, because encountered \"%s\"\n", cell);
                    #endif
                    clear_level(map, i);
                    i = 0;
                    continue;
                }

                //if (j>100) //TODO: reallocate to 2x size
                
                if (cell) map[i][j] = cell;
                #ifdef DEBUG
                    printf("cell(%d,%d) = %s\n", i, j, cell);
                #endif
                j++;
            }
            i++;
            j=0;
        }
        free(original_buffer);
    }
}


int collision(char *subject) {
    for (int i = 0; i< ArrLen(map_walls); i++) {
        if (strcmp(subject, map_walls[i]) == 0) return 1;
    }
    return 0;
}

void initialize_soms(){
    // soms[0] shall be the player 
    for (int i = 1; i < MAX_SOMS; i++) {
        // RAND_MAX is not large enough, will have expand on this one
        soms[i].likes.topics = rand();
        
    }
    soms[0].firstnames = firstnames[0];
    soms[0].gender = GENDER_CIS_FEMALE;
    soms[0].likes.topics = TOPIC_ALIENS | TOPIC_ANIMALS | TOPIC_CODING | TOPIC_GAMING;
}

void set_ncurses(uint state) {
    if (state) {
        initscr();
        curs_set(0);
    } else {
        endwin();
    }
}

void print_map(){
    for (int i = 0; i < ArrLen(map); i++) {
        for (int j = 0; j < ArrLen(map[i]); j++) {
            if ((map[i][j] != NULL) != 0)  {
                mvaddstr(i, j, map[i][j]);
                fprintf(stderr, "adding %s at %d,%d\n",map[i][j], i, j);
            }
        }
    }
    refresh();
}


int main() {
    load_level("levels/level1.csv");
    set_ncurses(1);
    print_map();
    //initialize_soms();
    getch();
    set_ncurses(0);
    printf("length of map is %lux%lu\n", ArrLen(map), ArrLen(map[0]));
    printf("%s\n", map[0][0]);

    return 0;
}