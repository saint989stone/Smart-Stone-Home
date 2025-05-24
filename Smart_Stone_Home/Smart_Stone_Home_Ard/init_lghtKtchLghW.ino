void init_lghtKtchLghW(){
  pinMode(lghtKtchLgWR, OUTPUT);
  pinMode(lghtKtchLgWG, OUTPUT);
  pinMode(lghtKtchLgWB, OUTPUT);
  pinMode(lghtKtchLgWW, OUTPUT);
}
void lghtKtchLghWStop(){
  digitalWrite(lghtKtchLgWR, LOW);
  digitalWrite(lghtKtchLgWG, LOW);
  digitalWrite(lghtKtchLgWB, LOW);
  digitalWrite(lghtKtchLgWW, LOW);
}

void lghtKtchLghW(){
  if (lghtKtch["lghtKtchSwtcLghW"] == 1){
    //Serial.println("Yes");
    analogWrite(lghtKtchLgWR, int(lghtKtch["lghtKtchSldrLgWR"]));
    analogWrite(lghtKtchLgWG, int(lghtKtch["lghtKtchSldrLgWG"]));
    analogWrite(lghtKtchLgWB, int(lghtKtch["lghtKtchSldrLgWB"]));
  }
  else if (lghtKtch["lghtKtchSwtcLghW"] == 0 && lghtKtch["lghtKtchSwtcWtfl"] == 0 && lghtKtch["lghtKtchSwtcMusc"] == 0){
    lghtKtchLghWStop();
  }
  else if (lghtKtch["lghtKtchSwtcSwtc"] == 0){
    lghtKtchLghWStop();
  }
}
