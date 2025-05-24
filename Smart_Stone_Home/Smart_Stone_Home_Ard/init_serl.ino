void init_serl(){
  Serial.begin(115200);
  Serial1.begin(115200);
}

//Инициализация функции чтения Serial Port
void serlRead() {
  if (Serial1.available()){
    DynamicJsonDocument doc(512);       //создаем временный буфер для хранения временного массива
    DeserializationError error = deserializeJson(doc, Serial1);          //считываем инф. из Serial порта парсим во временный объект
    if (error){
      Serial1.println(error.c_str());
    }
    else{
      JsonObject obj = doc.as<JsonObject>();
      for (JsonPair p : obj){        //перебираем пары ключ и значение с целью добаления в соответствующий массив
        String key = p.key().c_str();     
        String loclElem = key.substring(0, 8);     //переменая хранения имени массива lghtKtch
        if (loclElem == "clmtKtch"){
          clmtKtch[key] = int(p.value());
        }
        else if (loclElem == "lghtKtch"){
          lghtKtch[key] = int(p.value());     //назначаем соответствующему элементу массива значение
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
        else if (loclElem == "admrKtch"){
          admrKtch[key] = int(p.value());
        }
      }
    }
  }
}
//Инициализация функции отправки Serial Port с периодом по времени модулей Scrt, Fire, Watr c отправкой по времени
void serlSend() { 
  serlSendTime = millis();        //считываем текущее время
  if (serlSendTime > serlSendTimeNext){          //сравниваем текущее время с временем передачи
    String jsonStrgTemp = "";
    serializeJson(clmtKtch, jsonStrg);
    jsonStrg = jsonStrg.substring(0, jsonStrg.length() - 1);
    serializeJson(scrtKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    serializeJson(fireKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    serializeJson(watrKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    Serial1.print(jsonStrg);
    //Serial.println(jsonStrg);
    jsonStrg = "";
    serlSendTimeNext = serlSendTime + serlSendTimePerd;      //получаем время передачи   
  } 
}
//Инициализация функции отправки Serial Port с периодом по времени модулей Scrt, Fire, Watr c отправкой по времени
