#include <kilolib.h>
#include <stdio.h>

// Constants for motion handling function.
#define STOP 0
#define FORWARD 1
#define LEFT 2
#define RIGHT 3

int current_motion = STOP;
uint32_t last_motion_update = 0;


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
	last_motion_update = kilo_ticks;
}

void loop()
{

	if(kilo_uid != 1)
		{
			if (kilo_ticks < last_motion_update + 64){
				set_color(RGB(1,0,0));
				spinup_motors();
				set_motion(FORWARD);
				
			} 
			
			else if (kilo_ticks >= last_motion_update + 64 && kilo_ticks < last_motion_update + 128)
			{
				
				set_color(RGB(0,1,0));
				set_motion(STOP);
				delay(1000);
			} else if (kilo_ticks == last_motion_update + 128){
				last_motion_update = kilo_ticks;
				for (int i=0; i<1; i++){
					for (int j=0; j<6; j++){
						printf("uid: %d - dist: %d | ", kilo_uid, get_ambientlight());
					}
					printf("\n");
				}
			}
			
				
		}
		
}




int main()
{
   kilo_init();
   kilo_start(setup, loop);
    
   return 0;
}
