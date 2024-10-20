#include <sparki.h> //include Sparki library
void setup(){
}
 
void loop()
{

  sparki.RGB(100,0,0); // Make the LED maximum Red
  delay(500); // wait 0.5 seconds (500 milliseconds)

  sparki.RGB(0,100,0); // Make the LED maximum Green
  delay(500);

  sparki.RGB(0,0,100); // Make the LED maximum Blue
  delay(500);

  sparki.RGB(RGB_WHITE); // Make the LED white (all colors)
  delay(500);

  sparki.RGB(RGB_OFF); // Make the LED white (all colors)
  delay(500);
  sparki.moveForward();
  delay(3000);
  sparki.moveBackward();
  delay(3000);
  sparki.moveRight(15);
  sparki.moveStop();
  delay(1000);
}
