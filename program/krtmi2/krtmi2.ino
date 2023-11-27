#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <PS2X_lib.h>
#include <Servo.h>
PS2X ps2x;
Servo servo1;
Servo servo2;

//OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET); 

//ps2
int error;
int capit = 0;
int rotasi = 0;
byte type = 0;
byte vibrate = 0;

//Motor
#define a 22  //Depan 41
#define b 24 //Depan 43
#define c 26  //Depan 45
#define d 28  //Depan47
#define enA 5 //Depan6
#define enB 3 //Depan7

#define e 52  //Belakang40
#define f 50  //Belakang42
#define g 48  //Belakang44
#define h 46  //Belakang46
#define enC 6 //Belakang2
#define enD 7 //Belakang3

//lifter
#define La 42
#define Lb 44
#define enE 2
const int encoderLifA = 18; 
const int encoderLifB = 23; 
long pulse_count;

//LED 
#define LED1 34//LED1
#define LED2 32//LED2

//BUZZ
#define BUZZ 30//BUZZ
void setup()
{

  Serial.begin(57600);
  Serial.println("STRT");
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);

  while (true) {
    error = ps2x.config_gamepad(13, 11, 10, 12, true, true);
    Serial.println("Error = " + String(error));
    if (error == 0){break;}
    else if (error == 1){Serial.println("No controller found");}
    else if (error > 1){ Serial.println("Controller found but not accepting commands");}
  }
    Serial.println("Found Controller, configured successful");
//OLED    
  display.clearDisplay(); /* Clear display */
  display.setTextColor(WHITE);
  display.setTextSize(3); /* Select font size of text. Increases with size of argument. */
  display.setCursor(2,15);
  display.println("WELCOME");
  display.display();

  //Motor
  pinMode(a, OUTPUT);  pinMode(b, OUTPUT);  pinMode(c, OUTPUT);  pinMode(d, OUTPUT);
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);

  pinMode(e, OUTPUT);  pinMode(f, OUTPUT);  pinMode(g, OUTPUT);  pinMode(h, OUTPUT);
  pinMode(enC, OUTPUT); pinMode(enD, OUTPUT);

  pinMode(La, OUTPUT); pinMode(Lb, OUTPUT); pinMode(enE, OUTPUT);

  //encoder lifter
  pinMode(encoderLifA, INPUT_PULLUP);
  pinMode(encoderLifB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderLifA),pulse, RISING);

//Servo
  servo1.attach(35);
  servo2.attach(37);
  servo1.write(0);
  servo2.write(0);

//LED DAN BUZZ
  pinMode(LED1, OUTPUT); pinMode(LED2, OUTPUT); pinMode(BUZZ, OUTPUT);
}

void loop() {

  if (error == 1)
    return;

  else { //DualShock Controller
    gayaBatu();
    Lbatu();

    ps2x.read_gamepad(false, vibrate);
    if (ps2x.ButtonPressed(PSB_PAD_UP)) {
      Serial.print("Up");
      maju();
    }
    if (ps2x.Button(PSB_PAD_RIGHT)) {
      Serial.print("Right");
      kanan();
    }
    if (ps2x.Button(PSB_PAD_LEFT)) {
      Serial.print("LEFT");
      kiri();
      }
    }
    if (ps2x.Button(PSB_PAD_DOWN)) {
      Serial.print("DOWN");
      mundur();
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if ( (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                  //MAJU LEFT
    {
      maju();
      Serial.println("Maju");
    }
    if ( (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                 //MUNDUR LEFT
    {
      mundur();
      Serial.println("Mundur");
    }
    if ( (ps2x.Analog(PSS_LY) > 60) && (ps2x.Analog(PSS_LY) < 200) && (ps2x.Analog(PSS_LX) > 200))                 //KANAN LEFT
    {
      kanan();
      Serial.println("Kanan");
    }
    if ( (ps2x.Analog(PSS_LY) > 60) && (ps2x.Analog(PSS_LY) < 200) && (ps2x.Analog(PSS_LX) < 55))                  //KIRI LEFT
    {
      kiri();
      Serial.println("Kiri");
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if ( (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 200) )                  //SERONG KANAN ATAS LEFT
    {
      SerongKananAtas();
//      Serial.println("SerongKananAtas");
    }
   if ( (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) < 55) )                   //SERONG KIRI ATAS LEFT
    {
      SerongKiriAtas();
//      Serial.println("SerongKiriAtas");
    }
    if ( (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) < 55) )                  //SERONG KIRI BAWAH LEFT
    {
      SerongKiriBawah();
//      Serial.println("SerongKananBawah");
    }
    if ( (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 200) )                 //SERONG KANAN BAWAH LEFT
    {
      SerongKananBawah();
//      Serial.println("SerongKiriBawah");
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if ( (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) > 200))                 //KANAN RIGHT
    {
      jam();
      Serial.println("JAM");
    }
        if ( (ps2x.Analog(PSS_RY) < 55) && (ps2x.Analog(PSS_RX) > 98) && (ps2x.Analog(PSS_RX) < 158))                  //MAJU LEFT
    {
      mutarBebas();
      Serial.println("Maju");
    }
    if ( (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) < 55))                  //KIRI RIGHT
    {
      balikjam();
      Serial.println("BalikJAM");
    }

    if (ps2x.ButtonPressed(PSB_L1))
    {
      Serial.print("L1");
      if (rotasi == 0) {
        servo1.write(0);
        rotasi = 1;
      }
      else {
        servo1.write(90);
        rotasi = 0;
      }
    }
    else if (ps2x.ButtonPressed(PSB_L2))
    {
    }
    if (ps2x.ButtonPressed(PSB_R1))
    {
      Serial.print("R1");
      if (capit == 0) {
        servo2.write(0);
        capit = 1;
       digitalWrite(LED1, HIGH);
       digitalWrite(LED2, HIGH);
       digitalWrite(BUZZ, HIGH);
      }
      else {
        servo2.write(50);
        capit = 0;
       digitalWrite(LED1, LOW);
       digitalWrite(LED2, LOW);
       digitalWrite(BUZZ, LOW);
//       while(pulse_count<=90)
//       {
//        Lnaik();
//       }
//        Lbatu();
//        pulse_count = 0;
      }
    }  
    if (ps2x.Button(PSB_CROSS))
    {
      Serial.print("X");
        Lnaik(); 
    }
    if (ps2x.Button(PSB_CIRCLE))
    {
      Serial.print("O");
        Lturun();
    }

    if(ps2x.ButtonPressed(PSB_SQUARE)){
      //PERSEGI
      //Lnaik();
      while(pulse_count<=80)
       {
        Lnaik();
       }
        Lbatu();
        pulse_count = 0;
    }
    /* MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE 
 MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT*/
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if  (ps2x.Button(PSB_L2) && (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                  //MAJU LEFT
    {
      lambatmaju();
      Serial.println("LAMaju");
    }
    if (ps2x.Button(PSB_L2) && (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                 //MUNDUR LEFT
    {
      lambatmundur();
      Serial.println("LAMundur");
    }                                                                                                                               
    if (ps2x.Button(PSB_L2) && (ps2x.Analog(PSS_LY) > 98) && (ps2x.Analog(PSS_LY) < 158) && (ps2x.Analog(PSS_LX) > 200))                 //KANAN LEFT
    {
      lambatkanan();
      Serial.println("LAKanan");
    }
    if (ps2x.Button(PSB_L2) && (ps2x.Analog(PSS_LY) > 98) && (ps2x.Analog(PSS_LY) < 158) && (ps2x.Analog(PSS_LX) < 55))                  //KIRI LEFT
    {
      lambatkiri();
      Serial.println("LAKiri");
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 200) )                  //SERONG KANAN ATAS LEFT
//    {
//      LASerongKananAtas();
//      Serial.println("SerongKananAtas");
//    }
//    if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) < 55) )                   //SERONG KIRI ATAS LEFT
//    {
//      LASerongKiriAtas();
//      Serial.println("LASerongKiriAtas");
//    }
//    if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) < 55) )                  //SERONG KIRI BAWAH LEFT
//    {
//      LASerongKiriBawah();
//      Serial.println("LASerongKananBawah");
//    }
//    if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 200) )                 //SERONG KANAN BAWAH LEFT
//    {
//      LASerongKananBawah();
//      Serial.println("LASerongKiriBawah");
//
//    }
    if (ps2x.Button(PSB_L2) && (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) > 200))                 //KANAN RIGHT
    {
      lambatjam();
      Serial.println("LAJAM");
    }
    if (ps2x.Button(PSB_L2) && (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) < 55))                  //KIRI RIGHT
    {
      lambatbalikjam();
      Serial.println("LABalikJAM");
    }  
    if(ps2x.ButtonPressed(PSB_SELECT)){
       Serial.println("KCT");
       display.clearDisplay(); /* Clear display */
       display.setTextColor(WHITE);
       display.setTextSize(4); /* Select font size of text. Increases with size of argument. */
       display.setCursor(32,5);
       display.println("KCT");
       display.setTextSize(1);
       display.setCursor(23,40);
       display.println("ELEKTRO TEKNIK");
       display.setCursor(52,50);
       display.println("UNHAS");
       display.display();
      }
     if(ps2x.ButtonPressed(PSB_START)){
      Serial.println("ELEKTRO");
        }
delay(50);
}
