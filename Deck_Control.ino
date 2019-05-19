#include <SoftwareSerial.h>

//Relays are normally closed
#define sensor1 A1
#define sensor2 A2
#define sensor3 A3
#define sensor4 A4
#define lightsLed A0
#define lightsBtn 11
#define lightsRelay 7
#define waterLed 13
#define waterBtn 12
#define waterRelay 5
#define TX 9
#define RX 10
boolean lightsState = LOW;
boolean waterState = LOW;
boolean lightsBtnState = LOW;
boolean waterBtnState = LOW;

#define LightsOn '1'
#define LightsOff '2'
#define WaterfallOn '3'
#define WaterfallOff '4'
#define Query '9'


SoftwareSerial Genotronex(RX, TX);
char bluetoothData;

void setup() {
  pinMode(lightsBtn, INPUT);
  pinMode(waterBtn, INPUT);
  pinMode(lightsLed, OUTPUT);
  pinMode(waterLed, OUTPUT);
  pinMode(lightsRelay, OUTPUT);
  pinMode(waterRelay, OUTPUT);
  Serial.begin(9600);
  
  Genotronex.begin(9600);
  Genotronex.println("Hello");
}

boolean debounce(boolean state, int btn){
  boolean currentState = digitalRead(btn);
  if (state != currentState){
    delay(10);
    currentState = digitalRead(btn);
  }
  return currentState;
}

void loop() {
  if(Genotronex.available()){
    bluetoothData = Genotronex.read();
  }
  
  switch(bluetoothData){
    case LightsOn:
      lightsState = HIGH;
      break;
    case LightsOff:
      lightsState = LOW;
      break;
    case WaterfallOn:
      waterState = HIGH;
      break;
    case WaterfallOff:
      waterState = LOW;
      break;
    case Query:
      Genotronex.print(lightsState);
      Genotronex.print(" ");
      Genotronex.print(waterState);
      Genotronex.print(" ");
      Genotronex.print(analogRead(sensor1));
      Genotronex.print(" ");
      Genotronex.print(analogRead(sensor2));
      Genotronex.print(" ");
      Genotronex.print(analogRead(sensor3));
      Genotronex.print(" ");
      Genotronex.print(analogRead(sensor4));
      Genotronex.print(" ");
      break;
  }
  
  //listen for lightsBtn press (lights)
  if (debounce(lightsBtnState, lightsBtn) == HIGH && lightsBtnState == LOW){
    lightsState = !lightsState;
    lightsBtnState = !lightsBtnState;
  }
  if (debounce(lightsBtnState, lightsBtn) == LOW && lightsBtnState == HIGH){
    lightsBtnState =  !lightsBtnState;
  }
  
  //listen for waterBtn press (waterfall)
  if (debounce(waterBtnState, waterBtn) == HIGH && waterBtnState == LOW){
    waterState = !waterState;
    waterBtnState = !waterBtnState;
  }
  if (debounce(waterBtnState, waterBtn) == LOW && waterBtnState == HIGH){
    waterBtnState =  !waterBtnState;
  }
  
  digitalWrite(lightsLed, lightsState);
  digitalWrite(waterLed, waterState);
  digitalWrite(lightsRelay, !lightsState);
  digitalWrite(waterRelay, !waterState);
  
  bluetoothData = '0';

}
