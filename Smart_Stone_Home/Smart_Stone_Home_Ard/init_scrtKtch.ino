void init_scrtKtch(){
  pinMode (scrtKtchIndcWndw, INPUT_PULLUP);
  pinMode (scrtKtchIndcEntc, INPUT_PULLUP);
}
void scrtKtchScrt(){
  if (scrtKtch["scrtKtchSwtcSwtc"] == 1){         //проверяем swtc охранной сигнализации
    if (scrtKtch["scrtKtchIndcWndw"] == 1){         //проверяем статус индикатора если Indc статус Взят
      int scrtKtchIndc = analogRead(scrtKtchIndcWndw);      //считываем значение Pin
      if (scrtKtchIndc > 500){        //если значение больше 500 
        scrtKtch["scrtKtchAlrmBuzz"] = 2;       //переводим значения Alrm в статус Тревоги
        scrtKtch["scrtHallIndcWndw"] = 2;
        if (scrtKtchIndc > 1000){     //если значение больше 1000
          scrtKtch["scrtKtchAlrmBuzz"] = 3;         //переводим значения Alrm в статус Неисправность
          scrtKtch["scrtKtchIndcBalc"] = 3;         //переводим значение Indc в статус Неисправность
        }
      }
    }
    if (scrtKtch["scrtKtchIndcEntc"] == 1){
      int scrtKtchIndc = analogRead(scrtKtchIndcEntc);
      if (scrtKtchIndc > 500){
        scrtKtch["scrtKtchAlrmBuzz"] = 2;
        scrtKtch["scrtKtchIndcEntc"] = 2;
        if (scrtKtchIndc > 1000){
          scrtKtch["scrtKtchAlrmBuzz"] = 3;
          scrtKtch["scrtKtchIndcEntc"] = 3;      
        }
      }
    }
  }
}
