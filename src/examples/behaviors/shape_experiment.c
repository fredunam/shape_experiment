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
int column=0, line=0, nbRobots=0;
int flag = 1;


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

char charAct;

void sizeFile(FILE *file, int *ptrColumn, int *ptrLine){

    int charFile=0;
    int column=0, line=0, nbRobots=0;

    file = fopen("/home/fred/argos3-kilobot/src/examples/shape_files/u_letter.txt", "r+");

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
        column = charFile / (line + 1);

        *ptrColumn = column;
        *ptrLine = line + 1;

        printf("nb lines: %d - nb columns: %d - nb characters: %d \n\n", line + 1, column, charFile);

        fclose(file);

    } else {
        printf("sizeFile : unable to open the file");
    }
}


void coordAll_wp(FILE *file, int *ptrColumn, int *ptrLine, int *ptrNbRobots){

    Coordonnees fCoordonnees[*ptrColumn+1][*ptrLine+1];
    float hop = 0.10;
    float x = -1.5;
    float y = -1.5;

    file = fopen("/home/fred/argos3-kilobot/src/examples/shape_files/u_letter.txt", "r+");

    if(file != NULL){

        do{
            for ( int i=0; i< *ptrLine; i++){
                for( int j=0; j <= *ptrColumn; j++){
                    charAct = fgetc(file);
                    printf("%c ", charAct);
                    if(charAct != '\n'){
                        if (charAct == '0'){
                            fCoordonnees[i][j].x = x;
                            fCoordonnees[i][j].y = y;
                            *ptrNbRobots = *ptrNbRobots + 1;
                        }
//                        else {
//                            fCoordonnees[i][j].x = 10.0;
//                            fCoordonnees[i][j].y = 10.0;
//                        }
//                    } else {
//                        fCoordonnees[i][j].x = 50.0;
//                        fCoordonnees[i][j].y = 50.0;
                    }
                    if((fCoordonnees[i][j].x != 50.0 && fCoordonnees[i][j].y != 50.0) || (fCoordonnees[i][j].x != 10.0 && fCoordonnees[i][j].y != 10.0)){
                        printf("[%.2f, %.2f] | ", fCoordonnees[i][j].x, fCoordonnees[i][j].y);
                    }
                    x = x + hop;
                }
                x = -1.5;
                y = y + hop;
            }
        }while (charAct != EOF);

        fclose(file);
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
}


void loop(){


    if (kilo_ticks == 1){
        FILE *ptrFile = NULL;
        // Calls a function that defines the number of rows and columns in the input file
        sizeFile(ptrFile, &column, &line);
        printf("****************************************************************************************\n\n");

        // Calls a function that determines the orthogonal coordinates of the characters in the parameter file
        coordAll_wp(ptrFile, &column, &line, &nbRobots);
        printf("\n\nNous auront besoin de %d robots pour faire cette belle forme\n", nbRobots);
        flag = 0;
    }

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


