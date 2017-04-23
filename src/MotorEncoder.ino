#include <Encoder.h>
#include <TimerOne.h>

int position;
//Encoder encoder;
void setup()
{
  encoder.Timer_init();
  Serial.begin(9600);
  position = 0;
}
void loop()
{
  if (encoder.rotate_flag ==1)
  {
    if (encoder.direct==0)
    {
      Serial.println("backward rotated!");
      if(position == 360){position = 0;}
      if(position == 0){
          position = 360 - position - 18;
      }else{
        position = position - 18;
      }
      Serial.println(position);
    }
     else{
      Serial.println("forward rotated!");
      position = position + 18;
      if(position == 360){position = 0;}
      Serial.println(position);

    }
    encoder.rotate_flag =0;
  }
 }
