
#include
#define inputPin 11
#define outputPin 10
#define inputPin2 13 
#define outputPin2 12
#define my_constant 20

unsigned int sensor_r_value;
unsigned int sensor_l_value;
unsigned int sensor_r_value_last;
unsigned int sensor_l_value_last;
int difference;

void setup(){
  pinMode(inputPin,INPUT);
  pinMode(outputPin,OUTPUT);
  pinMode(inputPin2,INPUT);
  pinMode(outputPin2,OUTPUT);
  OneSheeld.begin();
}

void loop(){
  read_sensors();
  delay(1500);
}

int measure_r(){
  digitalWrite(outputPin, LOW);  // send low pulse for 2s
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); // send high pulse for 10s
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);  // back to low pulse
  int distance = pulseIn(inputPin, HIGH);  // read echo value
  int distance1 = distance/29/2;  // in cm
  return distance1;
}

int measure_l(){
  digitalWrite(outputPin2, LOW);  // send low pulse for 2s
  delayMicroseconds(2);
  digitalWrite(outputPin2, HIGH); // send high pulse for 10s
  delayMicroseconds(10);
  digitalWrite(outputPin2, LOW);  // back to low pulse
  int distance = pulseIn(inputPin2, HIGH);  // read echo value
  int distance2 = distance/29/2;  // in cm
  return distance2;
}

int read_sensors(){
  sensor_r_value = measure_r();
  sensor_l_value = measure_l();

  if (sensor_r_value) {
    TextToSpeech.say("stop now and rotate");
  }
  if (sensor_r_value > 30 && sensor_l_value > 30 && sensor_r_value_last) {
    TextToSpeech.say("Go Forward");
  }
  sensor_r_value_last = sensor_r_value;
  sensor_l_value_last = sensor_l_value;
}
