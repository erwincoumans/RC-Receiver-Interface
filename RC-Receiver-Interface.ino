//use with Teensy 3.2, set USB Type as Fligh Sim Controls + Joystick

#include "./include/Receiver.h"
#include "./include/PWM_Receiver.h"

PWMReceiver pwmReceiver(19, 20, 21, 22);

uint16_t channels[4] = { 0 };

void setup() {
    Serial.begin(115200);
}

void loop() {
    pwmReceiver.update(channels);
    for (int index = 0; index < 4; index++) {
        //Serial.print(channels[index]);
        //Serial.print("\t");
    }

  Joystick.X(512);//channels[0]);//analogRead(0));
  Joystick.Y(channels[1]);//forward accelerate/velocity
  Joystick.Z(512);
  Joystick.Zrotate(channels[0]);//steering

  Joystick.slider(512);//channels[1]);

  Joystick.sliderLeft(512);//channels[1]);
  Joystick.sliderRight(512);//channels[1]);

//button '4' (called 5) on
  Joystick.button(5, channels[2]<200? 1 : 0);

//button '5' (called 6) on
  Joystick.button(6, channels[2]>500? 1 : 0);
  
    delay(50);
}
