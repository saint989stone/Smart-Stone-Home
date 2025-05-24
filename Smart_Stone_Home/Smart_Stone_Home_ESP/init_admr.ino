void admr(){
  admrRstt();
  admrMntg();
}

void admrRstt(){
  if (admrKtch["admrKtchSwtcSwtc"] == 0){
    ESP.restart();
  }
}
void admrMntg(){
  admrMntgTime = millis();
  if (admrMntgTime > admrMntgTimeNext){          //сравниваем текущее время с временем передачи
    if (admrKtch["admrKtchIndcKtch"] == 1){       //если индикатор находится в состояние Норма
      if (admrMntgKtch == 0){       //в случае если данные не получены за интервал времени admrMntgTimePerd
        admrKtch["admrKtchIndcKtch"] = 3;       //переводим иникатор и Alrm в состояние неисправность
        admrKtch["admrKtchAlrmBuzz"] = 3;
      }
      else if (admrMntgKtch == 1){        //если данные получены за интервал времени admrMntgTimePerd
        admrMntgKtch = 0;         //переводим переменную получения данных в 0 до следующего получения данных
      }
    }
    if (admrHall["admrHallIndcHall"] == 1){
      if (admrMntgHall == 0){
        admrHall["admrHallIndcHall"] = 3;
        admrHall["admrHallAlrmBuzz"] = 3;
      }
      else if (admrMntgHall == 1){
        admrMntgHall = 0;         //переводим переменную передачи данных в 0 до следующего получения данных;
      }
    }
    admrMntgTimeNext = admrMntgTime + admrMntgTimePerd;      //получаем время передачи
  }
}
