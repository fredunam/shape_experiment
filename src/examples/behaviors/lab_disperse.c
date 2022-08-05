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

void setup()
{
   // Initialize an empty message.
   message.type = NORMAL;
   message.crc = message_crc(&message);
}

void loop()
{
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


int main()
{
   kilo_init();
   kilo_message_rx = message_rx;
   kilo_message_tx = message_tx;
   kilo_start(setup, loop);
    
   return 0;
}
