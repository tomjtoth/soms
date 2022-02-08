#include <stdlib.h>
#include <stdio.h>
//#include <ncurses.h>
#include <math.h>
#include <string.h>


#define TOPIC_ALIENS                 (ulong)pow(2,  0)
#define TOPIC_MOVIES                 (ulong)pow(2,  1)
#define TOPIC_GAMING                 (ulong)pow(2,  2)
#define TOPIC_COOKING                (ulong)pow(2,  3)
#define TOPIC_CODING                 (ulong)pow(2,  4)
#define TOPIC_FOODS                  (ulong)pow(2,  5)
#define TOPIC_WORKOUT                (ulong)pow(2,  6)
#define TOPIC_ANIMALS                (ulong)pow(2,  7)
#define TOPIC_FASHION                (ulong)pow(2,  8)
#define TOPIC_FURNITURE              (ulong)pow(2,  9)
#define TOPIC_TV_SHOWS               (ulong)pow(2, 10)
#define TOPIC_SHOPPING               (ulong)pow(2, 11)
#define TOPIC_FAMILY                 (ulong)pow(2, 12)
#define TOPIC_LOVE                   (ulong)pow(2, 13)
#define TOPIC_CHORES                 (ulong)pow(2, 14)
#define TOPIC_EDUCATION              (ulong)pow(2, 15)
#define TOPIC_WORK                   (ulong)pow(2, 16)
#define TOPIC_WEATHER                (ulong)pow(2, 17)
#define TOPIC_HISTORY                (ulong)pow(2, 18)
#define TOPIC_MUSIC                  (ulong)pow(2, 19)
#define TOPIC_VAMPIRES               (ulong)pow(2, 20)
#define TOPIC_COVID                  (ulong)pow(2, 21)
#define TOPIC_CHILDREN               (ulong)pow(2, 22)
#define TOPIC_DIY                    (ulong)pow(2, 23)
#define TOPIC_HOUSES                 (ulong)pow(2, 24)
#define TOPIC_POLITICS               (ulong)pow(2, 25)
#define TOPIC_HEALTH                 (ulong)pow(2, 26)
#define TOPIC_TRAVELING              (ulong)pow(2, 27)
#define TOPIC_HOLIDAYS               (ulong)pow(2, 28)
#define TOPIC_CLEANING               (ulong)pow(2, 29)
#define TOPIC_DRINKING               (ulong)pow(2, 30)
#define TOPIC_PSYCHOLOGY             (ulong)pow(2, 31)
#define TOPIC_LOTTERY                (ulong)pow(2, 32)
#define TOPIC_POVERTY                (ulong)pow(2, 33)
#define TOPIC_EMOTIONS               (ulong)pow(2, 34)
#define TOPIC_MONEY                  (ulong)pow(2, 35)
#define TOPIC_INVESTMENTS            (ulong)pow(2, 36)
#define TOPIC_MOTORSPORT             (ulong)pow(2, 37)
#define TOPIC_BOOKS                  (ulong)pow(2, 38)
#define TOPIC_SERIES                 (ulong)pow(2, 39)
#define TOPIC_SOAP_OPERA             (ulong)pow(2, 40)
#define TOPIC_POLICE_BRUTALITY       (ulong)pow(2, 41)
#define TOPIC_OPERA                  (ulong)pow(2, 42)
#define TOPIC_EATING_OUT             (ulong)pow(2, 43)
#define TOPIC_JOKES                  (ulong)pow(2, 44)
#define TOPIC_PRACTICAL_JOKES        (ulong)pow(2, 45)
#define TOPIC_BULLYING               (ulong)pow(2, 46)
#define TOPIC_PROSTITUTION           (ulong)pow(2, 47)
#define TOPIC_SEX                    (ulong)pow(2, 48)
#define TOPIC_SEX_SLAVES             (ulong)pow(2, 49)
#define TOPIC_LINUX                  (ulong)pow(2, 50)
#define TOPIC_WINDOWS                (ulong)pow(2, 51)
#define TOPIC_APPLE                  (ulong)pow(2, 52)
#define TOPIC_DRIVING                (ulong)pow(2, 53)
#define TOPIC_CARTOONS               (ulong)pow(2, 54)
#define TOPIC_PORN                   (ulong)pow(2, 55)
#define TOPIC_GARDENING              (ulong)pow(2, 56)
#define TOPIC_HYGIENE                (ulong)pow(2, 57)
#define TOPIC_WOMEN                  (ulong)pow(2, 58)
#define TOPIC_MEN                    (ulong)pow(2, 59)
#define TOPIC_INTERNET               (ulong)pow(2, 60)
#define TOPIC_CANDIES                (ulong)pow(2, 61)
#define TOPIC_RELIGION               (ulong)pow(2, 62)
#define TOPIC_MURDER                 (ulong)pow(2, 63)


#define FOOD_SANDWICH                (ulong)pow(2,  0)
#define FOOD_PIZZA                   (ulong)pow(2,  1)
#define FOOD_TORTILLA                (ulong)pow(2,  2)
#define FOOD_FISH                    (ulong)pow(2,  3)
#define FOOD_TURKEY                  (ulong)pow(2,  4)
#define FOOD_PASTA                   (ulong)pow(2,  5)
#define FOOD_HAMBURGER               (ulong)pow(2,  6)
#define FOOD_EGGS                    (ulong)pow(2,  7)
#define FOOD_CHEESE                  (ulong)pow(2,  8)
#define FOOD_FRUITS                  (ulong)pow(2,  9)
#define FOOD_VEGETABLES              (ulong)pow(2, 10)
#define FOOD_CHICKEN                 (ulong)pow(2, 11)
#define FOOD_HAM_CASSAROLE           (ulong)pow(2, 12)
#define FOOD_MACARONI_CASSAROLE      (ulong)pow(2, 13)
#define FOOD_SAUCY_CHICKEN           (ulong)pow(2, 14)
#define FOOD_SAUSAGE                 (ulong)pow(2, 15)
#define FOOD_FISH_SOUP               (ulong)pow(2, 16)
#define FOOD_SAJTOS_TEJFOLOS_TESZTA  (ulong)pow(2, 17)
#define FOOD_BOLOGNESE               (ulong)pow(2, 18)
#define FOOD_SPAGHETTI               (ulong)pow(2, 19)
#define FOOD_BUNDT_CAKE              (ulong)pow(2, 20)
#define FOOD_SUN_FLOWER_SEEDS        (ulong)pow(2, 21)
#define FOOD_RICE                    (ulong)pow(2, 22)
#define FOOD_MEAT                    (ulong)pow(2, 23)
#define FOOD_OAT_MEAL                (ulong)pow(2, 24)
#define FOOD_CHOCOLATE               (ulong)pow(2, 25)
#define FOOD_CANDY                   (ulong)pow(2, 26)
#define FOOD_KEBAB                   (ulong)pow(2, 27)
#define FOOD_SALAD                   (ulong)pow(2, 28)
#define FOOD_JOGHURT                 (ulong)pow(2, 29)
#define FOOD_PIE                     (ulong)pow(2, 30)
#define FOOD_BEANS                   (ulong)pow(2, 31)


#define DRINK_COCA_COLA              (ulong)pow(2,  0)
#define DRINK_BEER                   (ulong)pow(2,  1)
#define DRINK_TOMATO_JUICE           (ulong)pow(2,  2)
#define DRINK_WINE                   (ulong)pow(2,  3)
#define DRINK_MILK                   (ulong)pow(2,  5)
#define DRINK_COCOA                  (ulong)pow(2,  6)
#define DRINK_HOT_CHOCOLATE          (ulong)pow(2,  7)
#define DRINK_WATER                  (ulong)pow(2,  8)
#define DRINK_SODA                   (ulong)pow(2, 12)
#define DRINK_7UP                    (ulong)pow(2, 13)
#define DRINK_COCA_COLA_ZERO         (ulong)pow(2, 14)
#define DRINK_SPARKLING_WINE         (ulong)pow(2, 15)
#define DRINK_MINERAL_WATER          (ulong)pow(2, 16)
#define DRINK_SHOTS                  (ulong)pow(2, 17)
#define DRINK_COCKTAIL               (ulong)pow(2, 18)
#define DRINK_ICE_TEA                (ulong)pow(2, 19)
#define DRINK_TEA                    (ulong)pow(2, 20)
#define DRINK_COFFEE                 (ulong)pow(2, 21)
#define DRINK_SPRITE                 (ulong)pow(2, 22)
#define DRINK_FANTA                  (ulong)pow(2, 23)
#define DRINK_CIDER                  (ulong)pow(2, 24)
#define DRINK_LONG_DRINK             (ulong)pow(2, 25)
#define DRINK_SOUR_MILK              (ulong)pow(2, 26)
#define DRINK_KEFIR                  (ulong)pow(2, 27)
#define DRINK_JAFFA                  (ulong)pow(2, 28)
#define DRINK_MEAD                   (ulong)pow(2, 29)
#define DRINK_TEQUILA                (ulong)pow(2, 30)
#define DRINK_PALINKA                (ulong)pow(2, 31)


#define GENDER_CIS_FEMALE            (ulong)pow(2, 0)
#define GENDER_CIS_MALE              (ulong)pow(2, 1)
#define GENDER_OTHER                 (ulong)pow(2, 2)


#define MAX_SOMS                     100
#define LEVEL_WIDTH                  100
#define LEVEL_HEIGHT                 100


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
    char*          name;
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
        char *line = NULL, 
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
                //if (j>100) //reallocate to 2x size
                if (cell) map[i][j] = cell;
                #ifdef DEBUG
                    printf("cell(%d,%d) = %s\n", i, j, cell);
                #endif
                j++;
                //free(cell);
            }
            i++;
            j=0;
        }
        free(line);
        free(cell);
        free(buffer);
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
    soms[0].name = firstnames[0];
    soms[0].gender = GENDER_CIS_FEMALE;
    soms[0].likes.topics = TOPIC_ALIENS | TOPIC_ANIMALS | TOPIC_CODING | TOPIC_GAMING;

    soms[1].name = firstnames[1];
    soms[1].gender = GENDER_CIS_MALE;
    soms[1].likes.topics = TOPIC_GARDENING | TOPIC_ALIENS | TOPIC_BOOKS;

    //conversation(&soms[0], &soms[1], TOPIC_LINUX);
}

int main() {
    char *map[100][100];
    load_level("levels/level1.csv", map);
    //printf("after loading: %s\n",map[14][0]);
    clear_level(map, 0);
    //printf("after clearing: %s\n",map[14][0]);
/*
    initscr();
    const char *c = "R";
    const char *player = "P";
    curs_set(0);

    mvaddstr(10,10, c);
    
    mvaddstr(11,11, player);
    refresh();
    getch();

    endwin();
*/
    //unsigned long int x = 
    /*
    int i, j;
    for (i=0; i<10;i++){
        people[i].ID = i;
        people[i].name = (char*)malloc(sizeof(char*));
    }
    strcpy(people[0].name, "Tamás Tóth");
    people[0].likes = TOPIC_ALIENS | TOPIC_GAMING | TOPIC_COOKING; // | TOPIC_LAST;
    */


    //strcpy(people[1].name, "Tóth János");
    //strcpy(people[2].name, "Tóthné Nagy Olga");
/*
    for (i=0; i < 3; i++) {
        printf("name: %s\n", people[i].name);
        for (j=0; i<1; j++) {
            if (people[i].parents[j]) {
                printf("%s's parent is: %s\n",people[i].name, people[people[i].parents[j]].name);
            }
        }
    }
*/

    return 0;
}