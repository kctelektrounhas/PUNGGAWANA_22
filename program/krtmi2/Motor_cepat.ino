//Motor
void AturMotor(int pwmA, int pwmB, int pwmC, int pwmD, bool HL1, bool HL2, bool HL3, bool HL4, bool HL5, bool HL6, bool HL7, bool HL8) {
  analogWrite(enA, pwmA); analogWrite(enB, pwmB); digitalWrite(a, HL1); digitalWrite(b, HL2); digitalWrite(c, HL3); digitalWrite(d, HL4);
  analogWrite(enC, pwmC); analogWrite(enD, pwmD); digitalWrite(e, HL5); digitalWrite(f, HL6); digitalWrite(g, HL7); digitalWrite(h, HL8);
}
void maju() {
  AturMotor(110, 110, 110, 110,1, 0, 0, 1, 0, 1, 1, 0); 
}
void mundur() {
  AturMotor(110, 110, 110, 110, 0, 1, 1, 0, 1, 0, 0, 1);
}
void kiri() {
  AturMotor(200, 200, 200, 200, 1, 0, 1, 0, 1, 0, 1, 0);
}
void kanan() {
  AturMotor(200, 200, 200, 200, 0, 1, 0, 1, 0, 1, 0, 1);
}
void SerongKiriAtas() {
  AturMotor(255, 255, 255, 255, 1, 0, 0, 0, 0, 0, 1, 0);
}
void SerongKananAtas() {
  AturMotor(255, 255, 255, 255, 0, 0, 0, 1, 0, 1, 0, 0);
}
void SerongKananBawah() {
  AturMotor(255, 255, 255, 255, 0, 1, 0, 0, 0, 0, 0, 1);
}
void SerongKiriBawah() {
  AturMotor(255, 255, 255, 255, 0, 0, 1, 0, 1, 0, 0, 0);
}
void jam() {
  AturMotor(130, 130, 130, 130, 0, 1, 1, 0, 0, 1, 1, 0);
}
void balikjam() {
  AturMotor(130, 130, 130, 130 , 1, 0, 0, 1, 1, 0, 0, 1);
}
void gayaBatu() {
  AturMotor(100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0);
}
void lambat() {
  AturMotor(100, 100, 100, 100, 1, 0, 0, 1, 0, 1, 1, 0);
}
void nosmundur() {
  AturMotor(200, 200, 200, 200,0, 1, 1, 0, 1, 0, 0, 1); 
}
void nosmaju() {
  AturMotor(200, 200, 200, 200,1, 0, 0, 1, 0, 1, 1, 0); 
}
void mutarBebas(){
   AturMotor(200, 200, 200, 200,0, 0, 0, 1, 0, 0, 0, 1);
}



//lambat

//void lambatmaju() {
//  AturMotor(80, 80, 80, 80, 1, 0, 0, 1, 0, 1, 1, 0);
//}
//void lambatmundur() {
//  AturMotor(80, 80, 80, 80, 0, 1, 1, 0, 1, 0, 0, 1);
//}
//void lambatkiri() {
//  AturMotor(80, 80, 80, 80, 1, 0, 1, 0, 1, 0, 1, 0);
//}
//void lambatkanan() {
//  AturMotor(80, 80, 80, 80, 0, 1, 0, 1, 0, 1, 0, 1);
//}
//void LASerongKananAtas() {
//  AturMotor(80, 80, 80, 80, 0, 0, 0, 1, 0, 0, 1, 0);
//}
//void LASerongKiriAtas() {
//  AturMotor(80, 80, 80, 80, 1, 0, 0, 0, 0, 1, 0, 0);
//}
//void LASerongKiriBawah() {
//  AturMotor(80, 80, 80, 80, 0, 0, 1, 0, 0, 0, 0, 1);
//}
//void LASerongKananBawah() {
//  AturMotor(80, 80, 80, 80, 0, 1, 0, 0, 1, 0, 0, 0);
//}
//void lambatjam() {
//  AturMotor(80, 80, 80, 80, 0, 1, 1, 0, 0, 1, 1, 0);
//}
//void lambatbalikjam() {
//  AturMotor(80, 80, 80, 80, 1, 0, 0, 1, 1, 0, 0, 1);
//}
