#include <NanitLib.h>
byte buzz = P4_2;
void setup() {  
  Nanit_Base_Start();  
  GET_NANIT.getBataryVoltage();  
  pinMode(buzz, OUTPUT);  
}
  
  void loop() {  
    tone(buzz, 200);  
    delay(1000);  
    tone(buzz, 400);  
    delay(1000);  
    tone(buzz, 600);  
    delay(1000);  
    tone(buzz, 800);  
    delay(1000);  
    tone(buzz, 1000);  
    delay(1000); 
  }