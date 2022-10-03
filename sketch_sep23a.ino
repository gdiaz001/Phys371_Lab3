

// our potentiometer will go to Analog Input 2
  const int PotInputPin = A2;

 // our digital PWN output is set to Digital Out 9
  const int outPin = 9;

  
 // we start with an output of 0 and declare this variable as an integer
  int outputLevel=0;
  
void setup() {
   Serial.begin(9600);
    //define the pin mode for the digital output
    pinMode(outPin, OUTPUT);
}

void loop() {
    int potValue = analogRead(A2);

    // use the map() function to scale the potentiometer input from 0-1023 to 0-255
    outputLevel = map(potValue,0,1023,0,255);

    // write the outputLevel variable to our digital output pin
    analogWrite(outPin, outputLevel);

    // The function analogRead() will
  // read the input on analog pin 1:
  // that value is stored in an integer variable called sensorValue
  
  int sensorValue = analogRead(A1);

  unsigned long timer = millis()/200; 
  
  // The following line will send that variable to the
  // serial connection and print the measured value
  // in a range of 0 to 1023 where 0 is 0 Volts and 1023 is equal 5 Volts
    
  Serial.print(timer); 
  Serial.print(" , ");
  Serial.print(potValue); 
  Serial.print(" , "); 
  Serial.println(sensorValue);

  // We don't need a lot of measurements, so the delay function
  // will insert a 1000 millisecond (1.0 second) delay between each
  // loop. 

    delay(200);
}
