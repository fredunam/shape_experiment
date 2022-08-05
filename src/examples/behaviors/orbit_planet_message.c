/*
Ce code doit être amélioré. revoir la trjectoire de l'orbit
Travailler sur les delay() et les distances.

*/



#include <kilolib.h>
#include <stdio.h>

// Constants for orbit control.
#define TOO_CLOSE_DISTANCE 40
#define DESIRED_DISTANCE 60
#define MIDDLE_DISTANCE 50
#define MAX_DISTANCE 80

// Constants for motion handling function.
#define STOP 0
#define FORWARD 1
#define LEFT 2
#define RIGHT 3

int current_motion = STOP;
int distance;
int new_message = 0;
message_t_perso rcvd_message;
int ticks_state_update = 0;
//message_t_perso = rcvd_message;

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
         delay(200);
         set_motors(0, 0);
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
		
		 // Update the motion whenever a message is received.
		 if (new_message == 1)
		 {
		    new_message = 0;
		      
		    // If too close, move forward to get back into orbit.
		    if (distance < MIDDLE_DISTANCE)
		    {
		       set_color(RGB(0, 1, 0));
		       set_motion(RIGHT);
		       delay(500);
		       set_motion(FORWARD);
		       delay(200);
		    }
		    // If not too close, turn left or right depending on distance,
		    // to maintain orbit.
		    else
		    {
		       if (distance < DESIRED_DISTANCE)
		       {
		          set_color(RGB(1, 0, 0));
		          set_motion(RIGHT);
		          
		       } else {
		       		set_color(RGB(1, 1, 0));
		       		set_motion(LEFT);
		       		delay(50);
		       		set_motion(RIGHT);
		       		delay(50);
		       }
		    }
		 }
	
}


/*
 * Messages message_t_perso en provenance de orbit_star_message.c
*/
void message_rx(message_t_perso *msg, distance_measurement_t *dist) {
    rcvd_message = *msg;  //store the incoming message
    new_message = 1;      // set the flag to 1 to indicate that a new message arrived
    distance = estimate_distance(dist);
}

int main()
{
   kilo_init();
   kilo_message_rx = message_rx;
   kilo_start(setup, loop);
    
   return 0;
}
