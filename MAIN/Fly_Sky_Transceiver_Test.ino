#define INPUT_RX_1 2
#define INPUT_RX_2 3
#define INPUT_RX_3 4
#define INPUT_RX_4 5
#define INPUT_RX_5 6
#define INPUT_RX_6 7

/*
RECEIVER TYPE: FS-iA6B
TRANSMITTER TYPE: FS-I6X


The TOP _ ROW is signal 
The 2nd Row is +5 V
The 3rd Row is GND

CH 1 : R - LR -> Right side, Left right direction
CH 2 : L - UD
CH 3 : R - UD
CH 4 : L - LR
CH 5 : LEFT KNOB
CH 6 : RIGHT KNOB
*/

double dutyCycle(int PULSEIN){
  return ((PULSEIN-1480.0)/490); // normalize the value to +-1
}

void setup() {
  Serial.begin(9600);
  pinMode(INPUT_RX_1,INPUT);
  pinMode(INPUT_RX_2,INPUT);
  pinMode(INPUT_RX_3,INPUT);
  pinMode(INPUT_RX_4,INPUT);
  pinMode(INPUT_RX_5,INPUT);
  pinMode(INPUT_RX_6,INPUT);
}

void loop() {

  Serial.print("CH 1 : R - LR : ");
  Serial.print(dutyCycle(pulseIn(INPUT_RX_1,HIGH)));
  Serial.print(" | ");

  Serial.print("CH 2 : L - UD : ");
  Serial.print(dutyCycle(pulseIn(INPUT_RX_2,HIGH)));
  Serial.print(" | ");

  Serial.print("CH 3 : R - UD : ");
  Serial.print(dutyCycle(pulseIn(INPUT_RX_3,HIGH)));
  Serial.print(" | ");

  Serial.print("CH 4 : L - LR : ");
  Serial.print(dutyCycle(pulseIn(INPUT_RX_4,HIGH)));
  Serial.print(" | ");

  Serial.print("CH 5 : LEFT KNOB : ");
  Serial.print(dutyCycle(pulseIn(INPUT_RX_5,HIGH)));
  Serial.print(" | ");

  Serial.print("CH 6 : RIGHT KNOB : ");
  Serial.print(dutyCycle(pulseIn(INPUT_RX_6,HIGH)));
  Serial.print(" | ");

  Serial.println("");
  
}
