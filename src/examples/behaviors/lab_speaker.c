#include <kilolib.h>
#include <stdio.h>

// Constants for motion handling function.
#define STOP 0
#define FORWARD 1
#define LEFT 2
#define RIGHT 3

int current_motion = STOP;


message_t transmit_msg;
int message_sent = 0;

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
	transmit_msg.type = NORMAL;
	transmit_msg.data[0] = 0;
	transmit_msg.crc = message_crc(&transmit_msg);
}

void loop()
{
		if (message_sent == 1){
			message_sent = 0;
			set_color(RGB(0,1,0));
			delay(100);
			set_color(RGB(0,0,0));
		}
}


message_t *message_tx()
{
	return &transmit_msg;
}

void message_tx_success()
{
	message_sent = 1;
}


int main()
{
   kilo_init();
   kilo_message_tx = message_tx;
   kilo_message_tx_success = message_tx_success;
   kilo_start(setup, loop);
    
   return 0;
}