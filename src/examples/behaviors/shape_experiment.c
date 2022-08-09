//
// Created by fred on 26/07/22.
//
#include <kilolib.h>
#include <stdio.h>

// Constants for motion handling function.
#define STOP 0
#define FORWARD 1
#define LEFT 2
#define RIGHT 3


int current_motion = STOP;
int new_message = 0;
message_t message;
uint32_t last_state_update = 0;
int column=0, line=0, nbRobots=0, charFile=0, flag=0;
FILE *ptrFile = NULL;
FILE *ptr_w_file = NULL;


typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    float x;
    float y;
};

typedef struct {
    float target_x;
    float target_y;
    int kilo_id;
}ST_Target;
ST_Target liste_target[113];


char charAct;



/**
 *
 * @param file
 * @param ptrColumn
 * @param ptrLine
 */
void sizeFile(FILE *file, int *ptrColumn, int *ptrLine){

//    int charFile=0;
    int column=0, line=0;

    file = fopen("/home/fred/argos3-kilobot/src/examples/shape_files/Shape_U.txt", "r+");

    if (file != NULL){
        //iterates through the file and counts the number of characters and lines
        do {
            charAct = fgetc(file);

            if(charAct == '1' || charAct =='0'){
                charFile++;
            }
            if(charAct == '\n'){
                line++;
            }
        }while (charAct != EOF);

        //column <- number of characters divided by the number of lines plus one ending with EOF
        column = (charFile / line ) + 1;

        *ptrColumn = column;
        *ptrLine = line;

//        printf("nb lines: %d - nb columns: %d - nb characters: %d \n\n", line + 1, column, charFile);

        fclose(file);

    } else {
        printf("sizeFile : unable to open the file\n");
    }
}

/**
 * print toutes les targets dans un fichier "console.txt" et en console
 * @param file un fihier source binaire représentant la forme. Les '0' seront les targets
 * @param w_file un fichier affichant les targets et leurs coordonnées
 * @param ptrColumn le nbre de colonne du fichier source
 * @param ptrLine le nbre de ligne du fichier source
 * @param ptrNbRobots le nbre de robot nécessaire pour réaliser la forme
 */
void coordAll_wp(FILE *file, FILE *w_file, int *ptrColumn, int *ptrLine, int *ptrNbRobots){

    Coordonnees fCoordonnees[*ptrColumn+1][*ptrLine+1];
    float hop = 0.10;
    float x = -1.4;
    float y = -1.5;
    int nbChar = 0;

    file = fopen("/home/fred/argos3-kilobot/src/examples/shape_files/Shape_U.txt", "r+");
    w_file = fopen("/home/fred/argos3-kilobot/src/examples/shape_files/console.txt", "r+");

    if(file != NULL && w_file != NULL){

        do{
            printf("ptrColumn : %d - ptrLine : %d \n",*ptrColumn, *ptrLine);
            printf("-------------------------------------------------------------------\n");
            for ( int i=1; i<= *ptrLine; i++){
                for( int j=1; j <= *ptrColumn; j++){
                    charAct = fgetc(file);
                    //printf("%c ", charAct);
                    if(charAct != '\n'){
                        if (charAct == '0'){
                            fCoordonnees[i][j].x = x;
                            fCoordonnees[i][j].y = y;
                            *ptrNbRobots = *ptrNbRobots + 1;
                            printf("i = %d   j = %d : [%.2f, %.2f] \n ", i, j, fCoordonnees[i][j].x, fCoordonnees[i][j].y);
                            //fprintf(w_file,"i = %d   j = %d : [%.2f, %.2f] \n", i, j, fCoordonnees[i][j].x, fCoordonnees[i][j].y);
//                            fprintf(w_file,"<target id=\"%d\" position=\"%.5f, %.5f\" />\n",nbChar, fCoordonnees[i][j].x, fCoordonnees[i][j].y);
                            liste_target[nbChar].target_x = fCoordonnees[i][j].x;
                            liste_target[nbChar].target_y = fCoordonnees[i][j].y;
                            nbChar ++;
                        }
                        else {
                            fCoordonnees[i][j].x = 10.00;
                            fCoordonnees[i][j].y = 10.00;
                        }
                    } else {
                        fCoordonnees[i][j].x = 50.00;
                        fCoordonnees[i][j].y = 50.00;
                    }
//                    if((fCoordonnees[i][j].x != 50.00 && fCoordonnees[i][j].y != 50.00) || (fCoordonnees[i][j].x != 10.00 && fCoordonnees[i][j].y != 10.00)){
//                        printf("[%.2f, %.2f] | ", fCoordonnees[i][j].x, fCoordonnees[i][j].y);
//                    }
                    y = y + hop;
                }
                y = -1.5;
                x = x + hop;
            }
        }while (charAct != EOF);
        //fprintf(w_file,"nbChar : %d ", nbChar);
        fclose(file);
        fclose(w_file);
    } else {
        printf(" coordAll_wp : unable to open the file");

    }
    printf("\n");
}




// Function to handle motion.
void set_motion(int new_motion)
{
    // Only take an action if the motion is being changed.
    if (current_motion != new_motion)
    {
        current_motion = new_motion;

        if (current_motion == STOP)
        {
            set_motors(0, 0);
        }
        else if (current_motion == FORWARD)
        {
            spinup_motors();
            set_motors(kilo_straight_left, kilo_straight_right);
        }
        else if (current_motion == LEFT)
        {
            spinup_motors();
            set_motors(kilo_turn_left, 0);
        }
        else if (current_motion == RIGHT)
        {
            spinup_motors();
            set_motors(0, kilo_turn_right);
        }
    }
}


void setup(){
    kilo_init();
    // Calls a function that defines the number of rows and columns in the input file
    // Initialize an empty message.
    message.type = NORMAL;
    message.crc = message_crc(&message);
    if (flag == 0) {
        sizeFile(ptrFile, &column, &line);
        printf("In setup: nb lines: %d - nb columns: %d - nb characters: %d \n\n", line, column, charFile);
        coordAll_wp(ptrFile, ptr_w_file, &column, &line, &nbRobots);
        flag = 1;
        printf("flag = %d \n", flag);
    }
}


void loop(){


//    if (kilo_ticks >= 1 && kilo_ticks < 2){
//        FILE *ptrFile = NULL;
//        // Calls a function that defines the number of rows and columns in the input file
//        sizeFile(ptrFile, &column, &line);
//        printf("****************************************************************************************\n\n");
//
//        // Calls a function that determines the orthogonal coordinates of the characters in the parameter file
//        coordAll_wp(ptrFile, &column, &line, &nbRobots);
//        printf("\n\nNous auront besoin de %d robots pour faire cette belle forme\n", nbRobots);
//    }

      if( kilo_ticks > (last_state_update + 32)){
        last_state_update = kilo_ticks;

        if(new_message == 1){

            new_message = 0;

            int rand_number = rand_hard();
            int rand_direction = (rand_number % 4);

            if ((rand_direction == 0) || (rand_direction == 1)){
                set_color(RGB(1,0,0));
                set_motion(FORWARD);
            } else if (rand_direction == 2) {
                set_color(RGB(0,1,0));
                set_motion(RIGHT);
            } else if (rand_direction == 3){
                set_color(RGB(0,0,1));
                set_motion(LEFT);
            }
        }
        else {
            set_color(RGB(0,0,0));
            set_motion(STOP);
        }
    }
}

void message_rx(message_t *m, distance_measurement_t *d)
{
    new_message = 1;
}

message_t *message_tx()
{
    return &message;
}

int main(){

    kilo_message_rx = message_rx;
    kilo_message_tx = message_tx;
    kilo_start(setup, loop);

    return 0;
}


