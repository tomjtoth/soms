#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>
#include "sims.h"


char* genders[] = {
    "female",
    "male",
    "etc"
};


char* surnames[] = {
    "Huhtanen",
    "Tóth",
    "Kovács",
    "Patócs",
    "Varga",
    "Renlund",
};


char* firstnames[] = {
    "Hanna",
    "Tamás",
    "Máté",
    "Bálint",
    "Zoltán",
    "Attila",
    "János",
    "Mihály"
};


struct Likes {
    ulong          topics;
    ulong          drinks;
    ulong          foods;
};


struct Som {
    ushort         ID;
    char*          firstnames;
    char*          surnames;
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


void load_level(const char* level, char *map[LEVEL_HEIGHT][LEVEL_WIDTH]) {
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
    printf("c as char in collision function: %s\n", subject);
    printf("c as unsigned long in collision function: %lu\n", (unsigned long)subject);
    switch ((unsigned long )*subject) {
        case 0x2504u ... 0x250Bu:
        case 0x254Cu ... 0x254Fu:
            return 0;
       //break;
        /*case 0x2500u ... 0x257Fu:
            return 0;
        */
        default:
            return 1;
        break;
    }
}

void initialize_soms(){
    soms[0].firstnames = firstnames[0];
    soms[0].gender = GENDER_CIS_FEMALE;
    soms[0].likes.topics = TOPIC_ALIENS | TOPIC_ANIMALS | TOPIC_CODING | TOPIC_GAMING;

    soms[1].firstnames = firstnames[1];
    soms[1].gender = GENDER_CIS_MALE;
    soms[1].likes.topics = TOPIC_GARDENING | TOPIC_ALIENS | TOPIC_BOOKS;

    //conversation(&soms[0], &soms[1], TOPIC_LINUX);
}

void set_ncruses(uint state) {
    if (state) {
        initscr();
        curs_set(0);
    } else {
        endwin();
    }
}

int main() {
    char *map[100][100];
    load_level("levels/level1.csv", map);
    initialize_soms();

    return 0;
}