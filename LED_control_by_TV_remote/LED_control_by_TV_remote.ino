// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

 
// Define Sensor Pin
const int RECV_PIN = 4;
// Define variable to store last code received
unsigned long lastCode; 

const int LED1 = 7; 
const int LED2 = 6;
 
// Define integer to remember toggle state
int togglestate1 = 0;
int togglestate2 = 0;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;
 


void setup()
{
  // Start the receiver
  irrecv.enableIRIn();
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
}
 
void loop() {
if(irrecv.decode(&results)) //this checks to see if a code has been received
{
 
    if(results.value == 0xFFFFFFFF)   
    {
       // If Repeat then use last code received
       results.value = lastCode;        
    }
 
    switch(results.value){
          case 0xFF708F: //Red Keypad Button
        // Toggle LED1 On or Off
        if(togglestate1==0){
        digitalWrite(LED1, HIGH);
        togglestate1=1;
        }
        else {
        digitalWrite(LED1, LOW);
        togglestate1=0;
        }
        break;
   
          case 0xFF58A7: //Yellow Keypad Button
        // Toggle LED1 On or Off
        if(togglestate2==0){
        digitalWrite(LED2, HIGH);
        togglestate2=1;
        }
        else {
        digitalWrite(LED2, LOW);
        togglestate2=0;
        }
        break;
        
    }
    irrecv.resume(); 
}
    
}
