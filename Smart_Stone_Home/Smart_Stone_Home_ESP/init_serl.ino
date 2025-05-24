void init_serl(){
  Serial.begin(115200);       //инициализация Serial порта
}

//Инициализация функции чтения Serial Port
void serlRead(){
  if (Serial.available()){
    DynamicJsonDocument temp(528);       //создаем временный буфер для хранения временного массива
    DeserializationError error = deserializeJson(temp, Serial);          //считываем инф. из Serial порта парсим во временный объект
    if (error){
      Serial.println(error.c_str());
    }
    else{
      JsonObject obj = temp.as<JsonObject>();
      admrMntgKtch = 1;       //переводим переменную передачи данных в 1;
      for (JsonPair p : obj){
        String key = p.key().c_str();
        String loclElem = key.substring(0 ,8);
        if (loclElem == "clmtKtch"){
          clmtKtch[key] = int(p.value());
        }
        else if (loclElem == "lghtKtch"){
          lghtKtch[key] = int(p.value());
        }
        else if (loclElem == "scrtKtch"){
          scrtKtch[key] = int(p.value());
        }
        else if (loclElem == "fireKtch"){
          fireKtch[key] = int(p.value());
        }
        else if (loclElem == "watrKtch"){
          watrKtch[key] = int(p.value());
        }
      }
    }
  }
}    
