#include <kilolib.h>
#include <stdio.h>

message_t_perso message;
// Flag to keep track of message transmission.
int message_sent = 0;

void setup()
{
   // Initialize message:
   // The type is always NORMAL.
   message.type = NORMAL;
   // Some dummy data as an example.
   message.position[0].x = 2;
   message.position[0].y = 5;
   message.position[0].time = 11;
   message.position[0].x = 1;
   message.position[0].y = 4;
   message.position[0].time = 7;
   // It's important that the CRC is computed after the data has been set;
   // otherwise it would be wrong.
   message.crc = message_crc_perso(&message);
}

void loop()
{
   // Blink LED magenta whenever a message is sent.
   if (message_sent == 1)
   {
      // Reset flag so LED is only blinked once per message.
      message_sent = 0;
        
      set_color(RGB(1, 0, 1));
      delay(100);
      //printf("Message envoyé : %d, %d, %d, %d, %d, %d \n", message.inter.pos.x, message.inter.pos.y, message.inter.pos.time, 
      //	message.inter.target.x, message.inter.target.y, message.inter.target.time);
      set_color(RGB(0, 0, 0));
   }
}

message_t_perso *message_tx()
{
   return &message;
}

void message_tx_success()
{
   // Set flag on message transmission.
   message_sent = 1;
}

int main()
{
   kilo_init();
   // Register the message_tx callback function.
   kilo_message_tx = message_tx;
   // Register the message_tx_success callback function.
   kilo_message_tx_success = message_tx_success;
   kilo_start(setup, loop);
    
   return 0;
}
