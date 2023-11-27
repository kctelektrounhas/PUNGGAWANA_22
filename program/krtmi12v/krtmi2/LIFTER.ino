//void pulse(){
//  if(digitalRead (encoderLifB)){
//     pulse_count++;
//  }
//  else {
//    pulse_count++;
//  }
//}

void AturLift(int pwmE, bool HL9, bool HL10) {
  analogWrite(enE, pwmE); digitalWrite(La, HL9); digitalWrite(Lb, HL10);
}
void Lnaik() {
  AturLift(100, 1, 0);
}
void Lturun() {
  AturLift(230, 0, 1);
}
void Lbatu() {
  AturLift(0, 0, 0);
}
