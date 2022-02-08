#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>
#include "sims.h"


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
    
/// box drawing characters take up 3 code points (?)
/// idk how to make this simpler
/// so I'm using strings instead and memcmp for comparison later
char *map_walls[] ={
    "\U00002500",
    "\U00002501",
    "\U00002502",
    "\U00002503",
    "\U0000250C",
    "\U0000250D",
    "\U0000250E",
    "\U0000250F",
    "\U00002510",
    "\U00002511",
    "\U00002512",
    "\U00002513",
    "\U00002514",
    "\U00002515",
    "\U00002516",
    "\U00002517",
    "\U00002518",
    "\U00002519",
    "\U0000251A",
    "\U0000251B",
    "\U0000251C",
    "\U0000251D",
    "\U0000251E",
    "\U0000251F",
    "\U00002520",
    "\U00002521",
    "\U00002522",
    "\U00002523",
    "\U00002524",
    "\U00002525",
    "\U00002526",
    "\U00002527",
    "\U00002528",
    "\U00002529",
    "\U0000252A",
    "\U0000252B",
    "\U0000252C",
    "\U0000252D",
    "\U0000252E",
    "\U0000252F",
    "\U00002530",
    "\U00002531",
    "\U00002532",
    "\U00002533",
    "\U00002534",
    "\U00002535",
    "\U00002536",
    "\U00002537",
    "\U00002538",
    "\U00002539",
    "\U0000253A",
    "\U0000253B",
    "\U0000253C",
    "\U0000253D",
    "\U0000253E",
    "\U0000253F",
    "\U00002540",
    "\U00002541",
    "\U00002542",
    "\U00002543",
    "\U00002544",
    "\U00002545",
    "\U00002546",
    "\U00002547",
    "\U00002548",
    "\U00002549",
    "\U0000254A",
    "\U0000254B",
    "\U00002550",
    "\U00002551",
    "\U00002552",
    "\U00002553",
    "\U00002554",
    "\U00002555",
    "\U00002556",
    "\U00002557",
    "\U00002558",
    "\U00002559",
    "\U0000255A",
    "\U0000255B",
    "\U0000255C",
    "\U0000255D",
    "\U0000255E",
    "\U0000255F",
    "\U00002560",
    "\U00002561",
    "\U00002562",
    "\U00002563",
    "\U00002564",
    "\U00002565",
    "\U00002566",
    "\U00002567",
    "\U00002568",
    "\U00002569",
    "\U0000256A",
    "\U0000256B",
    "\U0000256C",
    "\U0000256D",
    "\U0000256E",
    "\U0000256F",
    "\U00002570",


    // idk if I'll actually need these, they look weird :D
    "\U00002571",
    "\U00002572",
    "\U00002573",
    "\U00002574",
    "\U00002575",
    "\U00002576",
    "\U00002577",
    "\U00002578",
    "\U00002579",
    "\U0000257A",
    "\U0000257B",
    "\U0000257C",
    "\U0000257D",
    "\U0000257E",
    "\U0000257F"

};

char *map_windows[] ={
    "\U00002504",
    "\U00002505",
    "\U00002506",
    "\U00002507",
    "\U00002508",
    "\U00002509",
    "\U0000250A",
    "\U0000250B",
};

char *map_doors[] = {
    "\U0000254C",
    "\U0000254D",
    "\U0000254E",
    "\U0000254F",
};

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
    for (int i = 0; i< 116; i++) {
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

void set_ncruses(uint state) {
    if (state) {
        initscr();
        curs_set(0);
    } else {
        endwin();
    }
}

int main() {
    //load_level("levels/level1.csv", map);
    //initialize_soms();

    printf("%d\n", collision("a"));
    return 0;
}