#include <kilolib.h>
#include <stdio.h>

#define STOP 0
#define FORWARD 1
#define LEFT 2
#define RIGHT 3

int current_motion = STOP;
uint32_t last_motion_update = 0;

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
    if (kilo_ticks > last_motion_update + 64){
        last_motion_update = kilo_ticks;


        int random_number = rand_hard();
        int random_direction = random_number % 4;

        if ((random_direction == 0) || (random_direction == 1))
        {
            set_color(RGB(0, 1, 0));
            set_motion(FORWARD);
        }
        else if (random_direction == 2)
        {
            set_color(RGB(1, 0, 0));
            set_motion(LEFT);
        }
        else if (random_direction == 3)
        {
            set_color(RGB(0, 0, 1));
            set_motion(RIGHT);
        }
    }
    else
    {
        set_color(RGB(1, 1, 1));
        set_motion(STOP);
    }

    // Set the LED green.
    set_color(RGB(0, 1, 0));
    // Spinup the motors to overcome friction.
    spinup_motors();
    // Move straight for 2 seconds (2000 ms).
    set_motors(kilo_straight_left, kilo_straight_right);
    delay(2000);

    // Set the LED red.
    set_color(RGB(1, 0, 0));
    // Spinup the motors to overcome friction.
    spinup_motors();
    // Turn left for 2 seconds (2000 ms).
    set_motors(kilo_turn_left, 0);
    delay(2000);

    // Set the LED blue.
    set_color(RGB(0, 0, 1));
    // Spinup the motors to overcome friction.
    spinup_motors();
    // Turn right for 2 seconds (2000 ms).
    set_motors(0, kilo_turn_right);
    delay(2000);

    // Set the LED off.
    set_color(RGB(0, 0, 0));
    // Stop for half a second (500 ms).
    set_motors(0, 0);
    delay(500);
}

int main()
{
    kilo_init();
    kilo_start(setup, loop);
    
    return 0;
}
