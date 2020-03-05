/*
**
  Welcome for any question in my github account 
  https://github.com/tahajadid/
*/
 
/*  We are using the L293N Module for controling the motors */
//Motor A
const int motorPin1D  = 5;  // The PIN 5 (PWM)
const int motorPin2D  = 6;  // The PIN 6 (PWM)
//Motor B
const int motorPin1G  = 10; // The PIN 10 (PWM)
const int motorPin2G  = 9;  // The PIN 9 (PWM)
const int short_v= 65; // slow speed
const int long_v= 120; // normal speed
const int normal= 190; // high speed

char Incoming_value = 0;                //Variable for storing Incoming_value
void setup() 
{
    pinMode(motorPin1D, OUTPUT); // All the pins are OUTPUT
    pinMode(motorPin2D, OUTPUT);
    pinMode(motorPin1G, OUTPUT);
    pinMode(motorPin2G, OUTPUT);
    Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  
}
void loop()
{
  /* Read the carac from the phone ("Return of the Bluetooth Module HC-05")*/
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        //New line 
    if(Incoming_value == '1')    {
      digitalWrite(motorPin1D, LOW);
    analogWrite(motorPin2D, normal);
    digitalWrite(motorPin1G, LOW);
    analogWrite(motorPin2G, normal);

    }
    else if(Incoming_value == '0')  {
      analogWrite(motorPin1D, normal);
    digitalWrite(motorPin2D, LOW);
    analogWrite(motorPin1G, normal);
    digitalWrite(motorPin2G, LOW);
    }
    else if(Incoming_value == 'l')  {
      digitalWrite(motorPin1D, LOW);
    analogWrite(motorPin2D, long_v);
    digitalWrite(motorPin1G, LOW);
    analogWrite(motorPin2G, normal);
    }
    else if(Incoming_value == 'r')  {
      digitalWrite(motorPin1D, LOW);
    analogWrite(motorPin2D, normal);
    digitalWrite(motorPin1G, LOW);
    analogWrite(motorPin2G, long_v);
    }
    else if(Incoming_value == 'd')  {
      digitalWrite(motorPin1D, LOW);
    analogWrite(motorPin2D, normal);
    digitalWrite(motorPin1G, LOW);
    analogWrite(motorPin2G, short_v);
    }
    else if(Incoming_value == 'u')  {
    digitalWrite(motorPin1D, LOW);
    analogWrite(motorPin2D, short_v);
    digitalWrite(motorPin1G, LOW);
    analogWrite(motorPin2G, normal);
    }
    else if(Incoming_value == 's')  {
    digitalWrite(motorPin1D, LOW);
    digitalWrite(motorPin2D, LOW);
    digitalWrite(motorPin1G, LOW);
    digitalWrite(motorPin2G, LOW);
    }
  }
      
    // Waiting 60 ms won't hurt any one
    delay(30);
}                 
