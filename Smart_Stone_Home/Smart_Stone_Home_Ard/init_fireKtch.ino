void init_fireKtch(){
  pinMode (fireKtchIndcRoom, INPUT);
  pinMode (fireKtchIndcCkng, INPUT);
}

void fireKtchFire(){
  if (fireKtch["fireKtchSwtcSwtc"] == 1){
    if (fireKtch["fireKtchIndcRoom"] == 1){
      int fireKtchIndc = analogRead(fireKtchIndcRoom);
      if (fireKtchIndc > 400){
        fireKtch["fireKtchAlrmBuzz"] = 2;
        fireKtch["fireKtchIndcRoom"] = 2;
        if (fireKtchIndc > 1000){
          fireKtch["fireKtchAlrmBuzz"] = 3;
          fireKtch["fireKtchIndcRoom"] = 3;
        }
      }
    }
    if (fireKtch["fireKtchIndcCkng"] == 1){
      int fireKtchIndc = analogRead(fireKtchIndcRoom);
      if (fireKtchIndc > 400){
        fireKtch["fireKtchAlrmBuzz"] = 2;
        fireKtch["fireKtchAlrmCkng"] = 2;
        if (fireKtchIndc > 1000){
          fireKtch["fireKtchAlrmBuzz"] = 3;
          fireKtch["fireKtchIndcCkng"] = 3;
        }
      }
    }
  }
}
