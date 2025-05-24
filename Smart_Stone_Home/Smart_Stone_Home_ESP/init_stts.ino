void stts(){
  sttsStts["sttsSttsTextTemp"] = sttsTextSum2 (clmtKtch["clmtKtchTextTemp"], clmtHall["clmtHallTextTemp"]);
  sttsStts["sttsSttsTextHmdt"] = sttsTextSum2 (clmtKtch["clmtKtchTextHmdt"], clmtHall["clmtHallTextHmdt"]);
}

int sttsTextSum2 (int sttsTex1, int sttsTex2){
  return round ((sttsTex1 + sttsTex2) / 2);
}

String sttsMssgStts (){
  String sttsMssgSttsStrg = "SmartStoneHomeTrud\nhttp://192.168.2.101";

  sttsMssgSttsStrg += "\n\n Kitchen temperature: " + String(int(clmtKtch["clmtKtchTextTemp"])) + "°C";          //Подготовка сообщения статуса блок Климата Температура
  sttsMssgSttsStrg += "\n Hall temperature: " + String(int(clmtHall["clmtHallTextTemp"])) + "°C";
  sttsMssgSttsStrg += "\n Kitchen humidity: " + String(int(clmtKtch["clmtKtchTextHmdt"])) + "%";          //Подготовка сообщения статуса блок Климата Влажность
  sttsMssgSttsStrg += "\n Hall humidity: " + String(int(clmtHall["clmtHallTextHmdt"])) + "%";

  sttsMssgSttsStrg += sttsHandStrg("\n\n Alarm send: ", tlgmSwtcAlrm);
  
  sttsMssgSttsStrg += sttsHandStrg("\n\n Kitchen security: ", scrtKtch["scrtKtchAlrmBuzz"]);          //Подготовка сообщения статуса блок Охранная сигнализация
  sttsMssgSttsStrg += sttsHandStrg("\n Hall security: ", scrtHall["scrtHallAlrmBuzz"]);

  sttsMssgSttsStrg += sttsHandStrg("\n\n Kitchen fire: ", fireKtch["fireKtchAlrmBuzz"]);          //Подготовка сообщения статуса блок Пожарная сигнализация
  sttsMssgSttsStrg += sttsHandStrg("\n Hall fire: ", fireHall["fireHallAlrmBuzz"]);

  sttsMssgSttsStrg += sttsHandStrg("\n\n Kitchen water: ", watrKtch["watrKtchAlrmBuzz"]);         //Подготовка сообщения статуса блока Протечка
  
  sttsMssgSttsStrg += sttsHandStrg("\n\n Kitchen connect: ", admrKtch["admrKtchAlrmBuzz"]);         //Подготовка сообщения статуса блок Доступности устройств
  sttsMssgSttsStrg += sttsHandStrg("\n Hall connect: ", admrHall["admrHallAlrmBuzz"]);
  return sttsMssgSttsStrg;
}

String sttsMssgAlrm (){       //Функция формирования переодической передачи Тревожных сообщений
  String sttsMssgAlrmStrg = "SmartStoneHomeTrud\nhttp://192.168.2.101\n";
  
  if (scrtKtch["scrtKtchAlrmBuzz"] == 2 || scrtKtch["scrtKtchAlrmBuzz"] == 3){
    sttsMssgAlrmStrg += sttsHandStrg("\nKitchen security: ", scrtKtch["scrtKtchAlrmBuzz"]);
    tlgmSendAlrm = 1;
  }
  if (scrtHall["scrtHallAlrmBuzz"] == 2 || scrtHall["scrtHallAlrmBuzz"] == 3){
    sttsMssgAlrmStrg += sttsHandStrg("\nHall security: ", scrtHall["scrtHallAlrmBuzz"]);
    tlgmSendAlrm = 1;
  }
  if (fireKtch["fireKtchAlrmBuzz"] == 2 || fireKtch["fireKtchAlrmBuzz"] == 3){
    sttsMssgAlrmStrg += sttsHandStrg("\nKitchen fire: ", fireKtch["fireKtchAlrmBuzz"]);
    tlgmSendAlrm = 1;
  }
  if (fireHall["fireHallAlrmBuzz"] == 2 || fireHall["fireHallAlrmBuzz"] == 3){
    sttsMssgAlrmStrg += sttsHandStrg("\nHall fire: ", fireHall["fireHallAlrmBuzz"]);
    tlgmSendAlrm = 1;
  }
  if (watrKtch["watrKtchAlrmBuzz"] == 2 || watrKtch["watrKtchAlrmBuzz"] == 3){
    sttsMssgAlrmStrg += sttsHandStrg("\nKitchen water: ", watrKtch["watrKtchAlrmBuzz"]);
    tlgmSendAlrm = 1;
  }
  if (admrKtch["admrKtchAlrmBuzz"] == 2 || admrKtch["admrKtchAlrmBuzz"] == 3){
    sttsMssgAlrmStrg += sttsHandStrg("\nKitchen connect: ", admrKtch["admrKtchAlrmBuzz"]);
    tlgmSendAlrm = 1;
  }
  if (admrHall["admrHallAlrmBuzz"] == 2 || admrHall["admrHallAlrmBuzz"] == 3){
    sttsMssgAlrmStrg += sttsHandStrg("\nHall connect: ", admrHall["admrHallAlrmBuzz"]);
    tlgmSendAlrm = 1;
  }
  return sttsMssgAlrmStrg;
}

String sttsHandStrg (String sttsHandStrgMssg, int sttsHandStrgAlrm){
  if (sttsHandStrgAlrm == 0){
    sttsHandStrgMssg += "Off";
  }
  if (sttsHandStrgAlrm == 1){
    sttsHandStrgMssg += "Normal";
  }
  else if (sttsHandStrgAlrm == 2){
    sttsHandStrgMssg += "Alarm";
  }
  else if (sttsHandStrgAlrm == 3){
    sttsHandStrgMssg += "Fault";
  }
  return sttsHandStrgMssg;
}
