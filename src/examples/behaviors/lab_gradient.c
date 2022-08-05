#include <kilolib.h>
#include <stdio.h>

// Constants for motion handling function.
#define STOP 0
#define FORWARD 1
#define LEFT 2
#define RIGHT 3

#define GRADIENT_MAX 255
#define SEED_ID 0

int current_motion = STOP;
int own_gradient = GRADIENT_MAX;
int received_gradient = 0;
int new_msg = 0;
message_t message;

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
	if (kilo_uid == SEED_ID){
		own_gradient = 0;
		printf("%d\n", kilo_uid);
	}
	
	message.type = NORMAL;
	message.data[0] = own_gradient;
	message.crc = message_crc(&message);
}

void loop()
{
	if(kilo_uid != SEED_ID){
		if (new_msg == 1){
			if (own_gradient > received_gradient + 1){
				own_gradient = received_gradient + 1;
				
				message.type = NORMAL;
				message.data[0] = own_gradient;
				message.crc = message_crc(&message);
			}
			
			new_msg = 0;
			
		}
	}
	
	// Set the LED color based on the gradient.
   if (own_gradient == 0)
   {
      set_color(RGB(1, 1, 1)); // White
      printf("kilo_uid : %d, own_gradient : %u\n", kilo_uid, own_gradient);
   }
   else if (own_gradient == 1)
   {
      set_color(RGB(1, 0, 0)); // Red
      printf("kilo_uid : %d, own_gradient : %u\n", kilo_uid, own_gradient);
   }
   else if (own_gradient == 2)
   {
      set_color(RGB(0, 1, 0)); // Green
      printf("kilo_uid : %d, own_gradient : %u\n", kilo_uid, own_gradient);
   }
   else if (own_gradient == 3)
   {
      set_color(RGB(0, 0, 1)); // Blue
      printf("kilo_uid : %d, own_gradient : %u\n", kilo_uid, own_gradient);
   }
   else if (own_gradient == 4)
   {
      set_color(RGB(1, 0, 1)); // Magenta
      printf("kilo_uid : %d, own_gradient : %u\n", kilo_uid, own_gradient);
   }
   else if (own_gradient >= 5)
   {
      set_color(RGB(1, 1, 0)); // Yellow
      printf("kilo_uid : %d, own_gradient : %u\n", kilo_uid, own_gradient);
   }
		
}

message_t *message_tx()
{
   return &message;
}

void message_rx(message_t *m, distance_measurement_t *d)
{
   // Only process this message if the previous one has been processed.
   if (new_msg == 0)
   {
      new_msg = 1;
      received_gradient = m->data[0];
   }
}

int main()
{
   kilo_init();
   kilo_message_rx = message_rx;
   kilo_message_tx = message_tx;
   kilo_start(setup, loop);
    
   return 0;
}
