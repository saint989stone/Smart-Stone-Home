void init_json(){
  /* Выделяем память размером буфера 200 байт
   *  StaticJsonBuffer выделяет память в стеке, ее можно заменить 
   *  на DynamicJsonBuffer, которая размещается в куче.
   */
  //StaticJsonBuffer<200> jsonBuffer;
  //JsonObject& jsonObject = jsonBuffer.createObject();
  //создаем в объекте значения пар ключа и значения
  swtcGnrl["swtcGnrlclmtSwtc"] = 0;
  swtcGnrl["swtcGnrllghtSwtc"] = 0;
  swtcGnrl["swtcGnrlscrtSwtc"] = 0;
  swtcGnrl["swtcGnrlfireSwtc"] = 0;
  swtcGnrl["swtcGnrlwatrSwtc"] = 0;
  swtcGnrl["swtcGnrladmrSwtc"] = 1;
  
  sttsStts["sttsSttsTextTemp"] = 0;
  sttsStts["sttsSttsTextHmdt"] = 0;
  
  clmtKtch["clmtKtchSwtcSwtc"] = 0;
  clmtKtch["clmtKtchTextTemp"] = 0;
  clmtKtch["clmtKtchTextHmdt"] = 0;
  
  clmtHall["clmtHallSwtcSwtc"] = 0;
  clmtHall["clmtHallTextTemp"] = 0;
  clmtHall["clmtHallTextHmdt"] = 0;
  
  lghtKtch["lghtKtchSwtcSwtc"] = 0;
  lghtKtch["lghtKtchSwtcLghW"] = 0;
  lghtKtch["lghtKtchSwtcWtfl"] = 0;
  lghtKtch["lghtKtchSwtcSond"] = 0;
  lghtKtch["lghtKtchSwtcLghT"] = 0;
  lghtKtch["lghtKtchSwtcLghF"] = 0;
  lghtKtch["lghtKtchSwtcLghC"] = 0;
  lghtKtch["lghtKtchSwtcNgSg"] = 0;
  lghtKtch["lghtKtchSldrLgWR"] = 0;
  lghtKtch["lghtKtchSldrLgWG"] = 0;
  lghtKtch["lghtKtchSldrLgWB"] = 0;
  lghtKtch["lghtKtchSldrLgWW"] = 0;
  lghtKtch["lghtKtchSldrWtfl"] = 0;
  
  lghtHall["lghtHallSwtcSwtc"] = 0;
  lghtHall["lghtHallSwtcLghW"] = 0;
  lghtHall["lghtHallSwtcLgTV"] = 0;
  lghtHall["lghtHallSwtcWtfl"] = 0;
  lghtHall["lghtHallSwtcSond"] = 0;
  lghtHall["lghtHallSwtcGrld"] = 0;
  lghtHall["lghtHallSwtcNgSg"] = 0;
  lghtHall["lghtHallSldrLgWR"] = 0;
  lghtHall["lghtHallSldrLgWG"] = 0;
  lghtHall["lghtHallSldrLgWB"] = 0;
  lghtHall["lghtHallSldrLgWW"] = 0;
  lghtHall["lghtHallSldrLgTR"] = 0;
  lghtHall["lghtHallSldrLgTG"] = 0;
  lghtHall["lghtHallSldrLgTB"] = 0;
  lghtHall["lghtHallSldrLgTW"] = 0;
  lghtHall["lghtHallSldrWtfl"] = 0;
  
  scrtKtch["scrtKtchSwtcSwtc"] = 0;
  scrtKtch["scrtKtchAlrmBuzz"] = 0;
  scrtKtch["scrtKtchIndcWndw"] = 0;
  scrtKtch["scrtKtchIndcEntc"] = 0;
  
  scrtHall["scrtHallSwtcSwtc"] = 0;
  scrtHall["scrtHallAlrmBuzz"] = 0;
  scrtHall["scrtHallIndcBalc"] = 0;
  scrtHall["scrtHallIndcRoom"] = 0;
  
  fireKtch["fireKtchSwtcSwtc"] = 0;
  fireKtch["fireKtchAlrmBuzz"] = 0;
  fireKtch["fireKtchIndcRoom"] = 0;
  fireKtch["fireKtchIndcCkng"] = 0;
  
  fireHall["fireHallSwtcSwtc"] = 0;
  fireHall["fireHallAlrmBuzz"] = 0;
  fireHall["fireHallIndcRoom"] = 0;
  
  watrKtch["watrKtchSwtcSwtc"] = 0;
  watrKtch["watrKtchAlrmBuzz"] = 0;
  watrKtch["watrKtchIndc1111"] = 0;
  watrKtch["watrKtchIndc2222"] = 0;

  admrHall["admrHallSwtcSwtc"] = 1;
  admrHall["admrHallAlrmBuzz"] = 1;
  admrHall["admrHallIndcHall"] = 1;

  admrKtch["admrKtchSwtcSwtc"] = 1;
  admrKtch["admrKtchAlrmBuzz"] = 1;
  admrKtch["admrKtchIndcKtch"] = 1;
}
     
