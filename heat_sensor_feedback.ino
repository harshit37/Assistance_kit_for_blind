float temp; 
int tempPin = A0; //arduino pin used for temperature sensor
int tempMin = 25;   // the temperature to start the buzzer
int tempMax = 70;   
int mot = 6;       // the pin where mot is connected
int motSpeed = 0;

void setup() {
 pinMode(mot, OUTPUT);
 pinMode(tempPin, INPUT);
 Serial.begin(9600);
}
void loop() {
  temp = analogRead(tempPin);
  temp = (temp *5.0*100.0)/1024.0; 
  Serial.println(temp);
  delay(1000);        // delay in between reads for stability
  if(temp < tempMin) {   // if temp is lower than minimum temp
       motSpeed = 0;      // mot is not spinning
       digitalWrite(mot, LOW);
   } 
   if((temp >= tempMin) && (temp <= tempMax))  //if temperature is higher than the minimmum range
   { 
       motSpeed = map(temp, tempMin, tempMax, 32, 255); // the actual speed of mot
       analogWrite(mot, motSpeed);  // spin the mot at the motSpeed speed
   } 
}
