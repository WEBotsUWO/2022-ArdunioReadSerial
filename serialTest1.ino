#include<string.h>

char* receivedChars, *token;
int availableBytes;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.write("ayo,wus,poppin");
}

void loop() {
  // put your main code here, to run repeatedly:
  availableBytes = Serial.available();

  //idk if this works but like enjoy
  if (availableBytes > 0){
    receivedChars = malloc(availableBytes);
    Serial.readString().toCharArray(receivedChars, availableBytes);
    
    //tokenizing by ,
    token = strtok(receivedChars, ",");
    while (token != NULL){
      if (token[0] == ','){
        digitalWrite(LED_BUILTIN, HIGH); 
        delay(500);
      }
      digitalWrite(LED_BUILTIN, LOW);
      token = strtok(NULL, ",");
    }
  }
}
