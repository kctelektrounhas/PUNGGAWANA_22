#include<SPI.h>
volatile boolean received;
volatile byte Slavereceived,Slavesend;
int x;

const int pEchAR1 = 2; //2 for Arduino Uno Board
const int pEchBR1 = 3; //3 for Arduino Uno Board

volatile long countPulsesR1 = 0;
const int TimeSamplingR1 = 30; //ms
unsigned long lastTimeR1 = 0;

const int enaR = 9;
const int inaR = 7;
const int inbR = 6;

float kpR1 = 0.1; //1.1
float kiR1 = 0.001; //0.009 UNTUK 250 RPM
float kdR1 = 0.0009; //1

#define speed 300
#define maxpwm 255
//#define maxpwmR 255
#define maxrpm 1000
float rpmR1;
int spR1;
float errorR1;
float errorR11;
float errorIR1;
float outR1;

void setup() {
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
}
ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(pEchAR1, INPUT_PULLUP);
  pinMode(pEchBR1, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pEchAR1), ISR_Encoder_AR1, CHANGE); //CHANGE --> low to high & high to low
  attachInterrupt(digitalPinToInterrupt(pEchBR1), ISR_Encoder_BR1, CHANGE);

  pinMode (enaR, OUTPUT);
  pinMode (inaR, OUTPUT);
  pinMode (inbR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  
  if(received){
    if(Slavereceived == 8){
      Serial.print("rpmR1: "); Serial.print("\t"); Serial.print(rpmR1); Serial.print("\t"); Serial.print("Out: "); Serial.print(outR1); Serial.print("\t"); Serial.print(spR1); Serial.println("\t");

      digitalWrite(inaR, LOW);
      digitalWrite(inbR, HIGH);
      analogWrite(enaR, 100);
    }
    if(Slavereceived == 9){
      digitalWrite(inaR, LOW);
      digitalWrite(inbR, LOW);
      analogWrite(enaR, 0);
    }
    
    x = 20;
    Slavesend=x;                             
    SPDR = Slavesend;                           //Sends the x value to master via SPDR 
    Serial.print(Slavereceived);Serial.print("\t");Serial.println(Slavesend);
    delay(100);
    }
  

  unsigned long currentTimeR1 = millis();
  float deltaTimeR1 = currentTimeR1 - lastTimeR1;
  if(deltaTimeR1>=TimeSamplingR1){
    float freqSignalR1 = (float)countPulsesR1/(deltaTimeR1/1.0e3); //(deltaTime/1.0e3) --> convert ms to s
    countPulsesR1 = 0;
    rpmR1 = freqSignalR1 * 60.0 / 396; //897.6 = p*4*N; p=step-up gear ratio (20.4) ratio; N=pulses per revolution (11) 408 untuk motor lama
    lastTimeR1 = currentTimeR1;
  }
//
  spR1 = 300;
  errorR1 = spR1 - rpmR1;
  if (outR1<maxpwm && outR1>-maxpwm) {
    errorIR1 += errorR1;
  }
  else {
    errorIR1 = 0;
  }
  if (spR1==0) {errorIR1 = 0;}

  outR1 = (kpR1*errorR1) + (kiR1*errorIR1) + (kdR1*(errorR1 - errorR11));
  errorR11 = errorR1;
  outR1 = constrain(outR1, 0, maxpwm);
}

//

void ISR_Encoder_AR1(){
  bool chAR1 = digitalRead(pEchAR1);
  bool chBR1 = digitalRead(pEchBR1);
  
  if(chAR1 == HIGH){
    if(chBR1 == HIGH){
      countPulsesR1++;
    }else{
      countPulsesR1++;
    }
  }else{
    if(chBR1 == HIGH){
      countPulsesR1++;
    }else{
      countPulsesR1++;
    }
  }
}

void ISR_Encoder_BR1(){
  bool chAR1 = digitalRead(pEchAR1);
  bool chBR1 = digitalRead(pEchBR1);
  
  if(chBR1 == HIGH){
    if(chAR1 == HIGH){
      countPulsesR1++;
    }else{
      countPulsesR1++;
    }
  }else{
    if(chAR1 == HIGH){
      countPulsesR1++;
    }else{
      countPulsesR1++;
    }
  }
}
