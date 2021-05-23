//*** ACS712 Current Sensor Interfacing with Arduino ***///
//*** ElektronicsGarage ***//
//*** Fayyaz Hussain ***//
//*** Date: 22 June, 2021 ***//
//*** www.elektronicsgarage1.blogspot.com ***//

// variables //
int ofset = 512; // sensor offset 2.5v
int acs = 66;  //use 100mv/A for 20B, 185mv/A for 5B and 66mv/A for 30B
double unitval = 0 ; // acs / 4.883 
double I=0; 
int val=0;
int led =13;

// Setup values //
void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
unitval = acs/4.883;// factor value for Current calculation  
}
  // Main loop, to run repeatedly:
void loop() {
val = analogRead(A1); // Read Analog value
val = val-ofset; // offset of sensor minus
I = val/unitval; // final Current value 

Serial.println(I); //you can Print on LCD also
}
