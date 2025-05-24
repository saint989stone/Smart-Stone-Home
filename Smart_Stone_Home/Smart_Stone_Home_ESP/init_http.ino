void init_http(void){
  HTTP.on("/restart", http_restart);        //перезагрузка модуля по запросу
  HTTP.on("/", [](){          //реализация запроса авторизации при загрузке index.html
    if(!HTTP.authenticate(httpUser, httpPass)){
        return HTTP.requestAuthentication();
    }
    String mssg = HTTP.uri();
    fsHandFileRead(mssg);       //запускаем функцию чтения файла index.html
  });
  HTTP.onNotFound(httpReadData);         //обратываем запросы как не найденые страницы
  HTTP.begin();         //запуск HTTP 
}

void httpReadData(){
  String mssg = HTTP.uri();         //получаем строку запроса
  if (mssg == "/loadOnce"){
    String jsonStrgTemp = "";
    serializeJson(lghtKtch, jsonStrg);
    jsonStrg = jsonStrg.substring(0, jsonStrg.length() - 1);
    serializeJson(lghtHall, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }

//Обработка перериодических запросов обновления данных на странице раз в 10 сек.
  else if (mssg == "/loadPerd"){
    String jsonStrgTemp = "";         //формируем строку ответа на запрос 
    serializeJson(swtcGnrl, jsonStrg);
    jsonStrg = jsonStrg.substring(0, jsonStrg.length() - 1);
    
    serializeJson(sttsStts, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    
    serializeJson(clmtKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    
    serializeJson(clmtHall, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    
    serializeJson(scrtKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    
    serializeJson(scrtHall, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    
    serializeJson(fireKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    
    serializeJson(fireHall, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";

    serializeJson(watrKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";

    serializeJson(admrHall, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1, jsonStrgTemp.length() - 1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    
    serializeJson(admrKtch, jsonStrgTemp);
    jsonStrgTemp = "," + jsonStrgTemp.substring(1);
    jsonStrg += jsonStrgTemp;
    jsonStrgTemp = "";
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
//Обработка запросов "Предоставления данных"
  else if (mssg == "/loadswtcGnrl"){
    serializeJson(swtcGnrl, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = ""; 
  }
  else if (mssg == "/loadlghtKtch"){         //функция загрузки данных на страницу в зависимости от активированого lvl1
    serializeJson(lghtKtch, jsonStrg);         //переводим объект json в текстовое представление
    httpSendRsps("text/json", jsonStrg);         //отправляем текстовое представление json
    jsonStrg = "";          //очищаем текстовое представление json
  }
  else if (mssg == "/loadlghtHall"){     
    serializeJson(lghtHall, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
  else if (mssg == "/loadscrtKtch"){
    serializeJson(scrtKtch, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
  else if (mssg == "/loadscrtHall"){
    serializeJson(scrtHall, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
  else if (mssg == "/loadfireKtch"){
    serializeJson(fireKtch, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
  else if (mssg == "/loadfireHall"){
    serializeJson(fireHall, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
  else if (mssg == "/loadwatrKtch"){
    serializeJson(watrKtch, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
  else if (mssg == "/loadadmrKtch"){
    serializeJson(admrKtch, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
  else if (mssg == "/loadadmrHall"){
    serializeJson(admrHall, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
//Обработка запроса "Управления главными выключателями"
  else if (mssg == "/swtcGnrl"){
    for (uint8_t i=0; i < HTTP.args(); i++){          //перебираем имена аргументов полученных в запросе  
      swtcGnrl[String(HTTP.argName(i))] = HTTP.arg(i).toInt();        //изменяем в соответствующем json объекте значение аргументов
    }
    serializeJson(swtcGnrl, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    jsonStrg = "";
  }
//Обработка запросов "Управления" по Serial 
  else if (mssg == "/lghtKtch"){
    for (uint8_t i=0; i < HTTP.args(); i++){          //перебираем имена аргументов полученных в запросе  
      lghtKtch[String(HTTP.argName(i))] = HTTP.arg(i).toInt();        //изменяем в соответствующем json объекте значение аргументов
    }
    serializeJson(lghtKtch, jsonStrg);     //переводим json объект в текстовое представление
    httpSendRsps("text/json", jsonStrg);         //отправляем текстовое представление json объекта
    Serial.print(jsonStrg);       //передаем json объект по Serial
    jsonStrg = "";        //очищаем строку тестового представления json объекта
  }
  else if (mssg == "/scrtKtch"){
    for (uint8_t i=0; i < HTTP.args(); i++){           
      scrtKtch[String(HTTP.argName(i))] = HTTP.arg(i).toInt();        
    }
    serializeJson(scrtKtch, jsonStrg);    
    httpSendRsps("text/json", jsonStrg);         
    Serial.print(jsonStrg);      
    jsonStrg = "";       
  }
  else if (mssg == "/fireKtch"){
    for (uint8_t i=0; i < HTTP.args(); i++){          
      fireKtch[String(HTTP.argName(i))] = HTTP.arg(i).toInt();        
    }
    serializeJson(fireKtch, jsonStrg);     
    httpSendRsps("text/json", jsonStrg);         
    Serial.print(jsonStrg);       
    jsonStrg = "";        
  }
  else if (mssg == "/watrKtch"){
    for (uint8_t i=0; i < HTTP.args(); i++){         
      watrKtch[String(HTTP.argName(i))] = HTTP.arg(i).toInt();      
    }
    serializeJson(watrKtch, jsonStrg);     
    httpSendRsps("text/json", jsonStrg);         
    Serial.print(jsonStrg);       
    jsonStrg = "";        
  }
  else if (mssg == "/admrKtch"){
    for (uint8_t i=0; i < HTTP.args(); i ++){
      admrKtch[String(HTTP.argName(i))] = HTTP.arg(i).toInt();
    }
    serializeJson(admrKtch, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    Serial.print(jsonStrg);
    jsonStrg = "";
  }
//Обработка запросов "Управления" по HTTP
  else if (mssg == "/lghtHall"){
    for (uint8_t i=0; i < HTTP.args(); i++){          //перебираем имена аргументов полученных в запросе  
      lghtHall[String(HTTP.argName(i))] = HTTP.arg(i).toInt();        //изменяем в соответствующем json объекте значение аргументов
    }
    serializeJson(lghtHall, jsonStrg);          //переводим json объект в текстовое представление
    httpSendRsps("text/json", jsonStrg);         //отправляем текстовое представление json объекта на WEB
    httpSendRqst("lghtHall", ipAdHall, jsonStrg, measureJson(lghtHall));          //отправляем тесктовое представление json объекта на ESP контроллера Hall
    jsonStrg = "";        //очищаем строку тестового представления json объекта
  }
  else if (mssg == "/scrtHall"){
    for (uint8_t i=0; i < HTTP.args(); i++){          
      scrtHall[String(HTTP.argName(i))] = HTTP.arg(i).toInt();     
    }
    serializeJson(scrtHall, jsonStrg);          
    httpSendRsps("text/json", jsonStrg);      
    httpSendRqst("scrtHall", ipAdHall, jsonStrg, measureJson(scrtHall));         
    jsonStrg = "";        
  }
  else if (mssg == "/fireHall"){
    for (uint8_t i=0; i < HTTP.args(); i++){          
      fireHall[String(HTTP.argName(i))] = HTTP.arg(i).toInt();        
    }
    serializeJson(fireHall, jsonStrg);          
    httpSendRsps("text/json", jsonStrg);     
    httpSendRqst("fireHall", ipAdHall, jsonStrg, measureJson(fireHall));         
    jsonStrg = "";       
  }
  else if (mssg == "/admrHall"){
    for (uint8_t i=0; i < HTTP.args(); i++){
      admrHall[String(HTTP.argName(i))] = HTTP.arg(i).toInt();
    }
    serializeJson(admrHall, jsonStrg);
    httpSendRsps("text/json", jsonStrg);
    httpSendRqst("admrHall", ipAdHall, jsonStrg, measureJson(admrHall));
  }
//Обработка периодических по времени запросов от других ESP, с содержанием объектов сигнализации (scrt, fire, watr)
  else if (mssg == "/hall"){
    httpHandJson();
    admrMntgHall = 1;         //при получение переодического запроса переводим переменную в 1 для admtMntg
  }
//При остальных запросах   
  else{
    fsHandFileRead(mssg);       //запускаем функцию чтения файлов ajax, hand, jquery, jquery-ui, jquery-ui.structure, json, main, style
  }
}

void httpHandJson(){         //Функция по обработке JSON по HTTP между ESP
  DynamicJsonDocument temp(528);       //создаем временный буфер для хранения временного массива
  DeserializationError error = deserializeJson(temp, HTTP.arg(0));          //считываем инф. из Serial порта парсим во временный объект
  if (error){
    Serial.println(error.c_str());
  }
  else{
    JsonObject obj = temp.as<JsonObject>();
    serializeJson(obj, Serial);
    for (JsonPair p : obj){
      String key = p.key().c_str();
      String loclElem = key.substring(0, 8);
      if (loclElem == "clmtHall"){
        clmtHall[key] = int(p.value());
      }
      else if (loclElem == "lghtHall"){
        lghtHall[key] = int(p.value());
      }
      else if (loclElem == "scrtHall"){
        scrtHall[key] = int(p.value());
      }
      else if (loclElem == "fireHall"){
        fireHall[key] = int(p.value());
      }
    }
  }  
}

void httpSendRsps(String type, String json){         //Функция отправки ответа на запрос
  HTTP.send(200, type, json);
}

void httpSendRqst(String loclElem_SendRqst, String loclElemIP_SendRqst, String jsonStrg_SendRqst, size_t jsonLngh){         //Функция отправки запроса
  const char *loclElemIPCh_SendRqst = loclElemIP_SendRqst.c_str(); 
// Формируем строку запроса следующего вида: 
// POST /lghtHall HTTP/1.1
// Host: 192.168.2.102
// Content-Length: 295
// Content-Type: text/json
// Connection: close
  String rqstStrg = String("POST ") + String("/") + loclElem_SendRqst + String(" ") + 
  String("HTTP/1.1\r\nHost: ") + loclElemIP_SendRqst + 
  String("\r\nContent-Length: ") + jsonLngh + 
  String("\r\nContent-Type: text/json\r\nConnection: keep-alive\r\n\r\n") + jsonStrg_SendRqst;
  if (client.connect(loclElemIPCh_SendRqst, 80)){         //поднимаем соединение с ESP соотвествующего контроллера 
    client.println(rqstStrg);         //отправляем сформированный запрос
  }
  else{
    Serial.println("connect lost");
  }
}
void http_restart(){
  String rest = HTTP.arg("device");         //сохраняем значение аргумента device
  if (rest == "ok"){
    HTTP.send(200, "text/plain", "ok");         //отправляем сообщение на запрос
    ESP.restart();        //вслучае если значение ок перезагружаем модуль
  }            
}
