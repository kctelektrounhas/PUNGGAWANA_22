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
//void BUTjampadcep(){
//  AturMotor(150, 150, 150, 150, 0, 1, 1, 0, 0, 1, 1, 0);
//}
//void BUTbalikjampadcep(){
//  AturMotor(150, 150, 150, 150, 1, 0, 0, 1, 1, 0, 0, 1);
//}
//void BUTmajupadcep(){
//  AturMotor(150, 150, 150, 150, 1, 0, 0, 1, 0, 1, 1, 0);
//}


//BUTTON TERTEKAN
void BUTmaju() {
  AturMotor(255, 255, 255, 255,1, 0, 0, 1, 0, 1, 1, 0); 
}
void BUTmundur() {
  AturMotor(255, 255, 255, 255, 0, 1, 1, 0, 1, 0, 0, 1);
}
void BUTkiri() {
  AturMotor(200, 200, 200, 200, 1, 0, 1, 0, 1, 0, 1, 0);
}
void BUTkanan() {
  AturMotor(200, 200, 200, 200, 0, 1, 0, 1, 0, 1, 0, 1);
}
void BUTSerongKiriAtas() {
  AturMotor(255, 255, 255, 255, 1, 0, 0, 0, 0, 0, 1, 0);
}
void BUTSerongKananAtas() {
  AturMotor(255, 255, 255, 255, 0, 0, 0, 1, 0, 1, 0, 0);
}
void BUTSerongKananBawah() {
  AturMotor(255, 255, 255, 255, 0, 1, 0, 0, 0, 0, 0, 1);
}
void BUTSerongKiriBawah() {
  AturMotor(255, 255, 255, 255, 0, 0, 1, 0, 1, 0, 0, 0);
}
void BUTjam() {
  AturMotor(200, 200, 200, 200, 0, 1, 1, 0, 0, 1, 1, 0);
}
void BUTbalikjam() {
  AturMotor(200, 200, 200, 200, 1, 0, 0, 1, 1, 0, 0, 1);
}
void BUTgayaBatu() {
  AturMotor(100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0);
}
void BUTlambat() {
  AturMotor(100, 100, 100, 100, 1, 0, 0, 1, 0, 1, 1, 0);
}
void BUTnosmundur() {
  AturMotor(200, 200, 200, 200,0, 1, 1, 0, 1, 0, 0, 1); 
}
void BUTnosmaju() {
  AturMotor(200, 200, 200, 200,1, 0, 0, 1, 0, 1, 1, 0); 
}
void BUTmutarBebas(){
   AturMotor(200, 200, 200, 200,0, 0, 0, 1, 0, 0, 0, 1);
}
void BUTjampad(){
  AturMotor(150, 150, 150, 150, 0, 1, 1, 0, 0, 1, 1, 0);
}
void BUTbalikjampad(){
  AturMotor(150, 150, 150, 150, 1, 0, 0, 1, 1, 0, 0, 1);
}
void BUTmajupad(){
  AturMotor(150, 150, 150, 150, 1, 0, 0, 1, 0, 1, 1, 0);
}
