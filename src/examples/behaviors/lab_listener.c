#include <kilolib.h>
#include <stdio.h>

// Constants for motion handling function.
#define STOP 0
#define FORWARD 1
#define LEFT 2
#define RIGHT 3

int current_motion = STOP;

message_t rcvd_message;
int new_message = 0;

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

}

void loop()
{
		if (new_message == 1){
			new_message = 0;
			set_color(RGB(1,0,0));
			delay(100);
			set_color(RGB(0,0,0));
		}
}


void message_rx(message_t *msg, distance_measurement_t *dist)
{
	rcvd_message = *msg;
	new_message = 1;
}

int main()
{
   kilo_init();
   kilo_message_rx = message_rx;
   kilo_start(setup, loop);
    
   return 0;
}
