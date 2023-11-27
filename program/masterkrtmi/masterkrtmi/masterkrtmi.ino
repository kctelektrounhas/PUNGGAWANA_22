#include<SPI.h>
int x;

#include <PS2X_lib.h>
PS2X ps2x;
//ps2
int error;
int capit = 0;
int rotasi = 0;
byte type = 0;
byte vibrate = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200 
                   
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)

  while (true) {
    error = ps2x.config_gamepad(13, 11, 10, 12, true, true);
    Serial.println("Error = " + String(error));
    if (error == 0){break;}
    else if (error == 1){Serial.println("No controller found");}
    else if (error > 1){ Serial.println("Controller found but not accepting commands");}
  }
    Serial.println("Found Controller, configured successful");

}

void loop() {
  // put your main code here, to run repeatedly:
  byte Mastersend,Mastereceive;  

  if (error == 1)
    return;

  else { //DualShock Controller
  

    ps2x.read_gamepad(false, vibrate);
    if (ps2x.Button(PSB_PAD_UP)) { //ButtonPressed
      // Serial.print("Up");
      //maju();
      x = 8;
    }
    else if (ps2x.Button(PSB_PAD_RIGHT)) {
      // Serial.print("Right");
    }
    else if (ps2x.Button(PSB_PAD_LEFT)) {
      // Serial.print("LEFT");
      }
    
    else if (ps2x.ButtonPressed(PSB_PAD_DOWN)) {
      // Serial.print("DOWN");
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if ( (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                  //MAJU LEFT
    {
//      Serial.print("Maju");
      

    }
    else if ( (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                 //MUNDUR LEFT
    {
      
    }
    else if ( (ps2x.Analog(PSS_LY) > 60) && (ps2x.Analog(PSS_LY) < 200) && (ps2x.Analog(PSS_LX) > 200))                 //KANAN LEFT
    {
//      Serial.println("Kanan");
    }
    else if ( (ps2x.Analog(PSS_LY) > 60) && (ps2x.Analog(PSS_LY) < 200) && (ps2x.Analog(PSS_LX) < 55))                  //KIRI LEFT
    {
//      Serial.println("Kiri");
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    if ( (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 200) )                  //SERONG KANAN ATAS LEFT
//    {
//      SerongKananAtas();
//      Serial.println("SerongKananAtas");
//    }
//    if ( (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) < 55) )                   //SERONG KIRI ATAS LEFT
//    {
//      SerongKiriAtas();
//      Serial.println("SerongKiriAtas");
//    }
//    if ( (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) < 55) )                  //SERONG KIRI BAWAH LEFT
//    {
//      SerongKiriBawah();
//      Serial.println("SerongKananBawah");
//    }
//    if ( (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 200) )                 //SERONG KANAN BAWAH LEFT
//    {
//      SerongKananBawah();
//      Serial.println("SerongKiriBawah");
//    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if ( (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) > 200))                 //KANAN RIGHT
    {
//      Serial.println("JAM");
    }
    else if ( (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) < 55))                  //KIRI RIGHT
    {
//      Serial.println("BalikJAM");
    }

    else if (ps2x.ButtonPressed(PSB_L1))
    {
      // Serial.print("L1");
    }
    else if (ps2x.ButtonPressed(PSB_L2))
    {
    }
    else if (ps2x.ButtonPressed(PSB_R1))
    {
    //   Serial.print("R1");
    }  
    else if (ps2x.Button(PSB_CROSS))
    {
      // Serial.print("X");
    }
    else if (ps2x.Button(PSB_CIRCLE))
    {
      // Serial.print("O");
    }
    /* MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE 
 MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT MODE LAMBAT*/
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if  (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                  //MAJU LEFT
    {
      // Serial.println("LAMaju");
    }
    else if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158))                 //MUNDUR LEFT
    {
      // Serial.println("LAMundur");
    }                                                                                                                               
    else if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) > 98) && (ps2x.Analog(PSS_LY) < 158) && (ps2x.Analog(PSS_LX) > 200))                 //KANAN LEFT
    {
      // Serial.println("LAKanan");
    }
    else if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_LY) > 98) && (ps2x.Analog(PSS_LY) < 158) && (ps2x.Analog(PSS_LX) < 55))                  //KIRI LEFT
    {
      // Serial.println("LAKiri");
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
    else if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) > 200))                 //KANAN RIGHT
    {
      // Serial.println("LAJAM");
    }
    else if (ps2x.Button(PSB_R2) && (ps2x.Analog(PSS_RY) > 98) && (ps2x.Analog(PSS_RY) < 158) && (ps2x.Analog(PSS_RX) < 55))                  //KIRI RIGHT
    {
      // Serial.println("LABalikJAM");
    }  
    else if(ps2x.ButtonPressed(PSB_SELECT)){
      
      }
    else if(ps2x.ButtonPressed(PSB_START)){
      }
    else{
      x=9;
      }
        
    delay(50);

   
  }
  digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master
  Mastersend = x;    
  SPI.transfer(Mastersend);                        
  //Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
  Serial.print(Mastereceive);Serial.print("\t");Serial.println(Mastersend);
delay(100);

  
}
