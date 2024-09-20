#include <Servo.h>
int  valor_limite = 650;
int pos = 0;
const int buzzer = 6;
const int photoresistorPin1 = A1;
const int photoresistorPin2 = A2;
const int photoresistorPin3 = A3;
Servo servo_9;
void setup() {
  Serial.begin(9600); 
  pinMode(8, OUTPUT); 
  pinMode(buzzer, OUTPUT); 
  servo_9.attach(5, 500, 2500);
}

void loop() {
  Serial.println(analogRead(A0));
  int sensorValue1 = analogRead(photoresistorPin1);
  int sensorValue2 = analogRead(photoresistorPin2);
  int sensorValue3 = analogRead(photoresistorPin3);
  Serial.print("Analog Value1: ");
  Serial.println(sensorValue1);
  Serial.print("Analog Value2: ");
  Serial.println(sensorValue2);
  Serial.print("Analog Value3: ");
  Serial.println(sensorValue3);
  delay(500);

  if(analogRead(A0) > valor_limite){ 
    digitalWrite(8, LOW); 
    digitalWrite(7, HIGH); 
    tone(buzzer, 1200);
    delay(500);
  }
  else{ 
    digitalWrite(8, HIGH); 
    digitalWrite(7, LOW); 
    noTone(buzzer);
    delay(500);
    }
  delay (1000);
      if (sensorValue3>21){
        servo_9.write(30); 
       delay(300);  // Wait for 1 second
  
  servo_9.write(90);  // Anticlockwise 30 degrees
  delay(300); 
    }
  else if (sensorValue1>22){
    for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
    }

  }
}