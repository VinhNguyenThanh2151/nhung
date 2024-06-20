#define BLYNK_TEMPLATE_ID "TMPL6w8ATssfN"
#define BLYNK_DEVICE_NAME "4RL1"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"
WidgetLED LedConnect(V0);
unsigned long timeUpdate=millis();

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
}

void loop() {
  BlynkEdgent.run();
  if(millis()-timeUpdate>1000){
    if(LedConnect.getValue()){
      LedConnect.off();
    }else{
      LedConnect.on();
    }
    timeUpdate=millis();
  }
}
BLYNK_CONNECTED(){
  Blynk.syncAll();
}
BLYNK_WRITE(V1){
  int p=param.asInt();
  digitalWrite(D1,p);
}
BLYNK_WRITE(V2){
  int p=param.asInt();
  digitalWrite(D2,p);
}
BLYNK_WRITE(V3){
  int p=param.asInt();
  digitalWrite(D5,p);
}
BLYNK_WRITE(V4){
  int p=param.asInt();
  digitalWrite(D6,p);
}

