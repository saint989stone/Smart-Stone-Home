void init_tlgm (){
  client.setInsecure();
  //bot.longPoll = 1;        //сохраняет запрос на Telegram открытым в течение заданного количества секунд, если сообщений нет. Это значительно улучшает время отклика бота, но действительно подходит только для проектов. Где начальное взаимодействие исходит от Telegram, так как запросы будут блокировать цикл
}

void tlgm (){
  tlgmReadTime = millis();
  if (tlgmReadTime > tlgmReadTimeNext){          //сравниваем текущее время с временем проверки данных
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    if (numNewMessages){
      tlgmReadData(numNewMessages);
    }
    tlgmReadTimeNext = tlgmReadTime + tlgmReadTimePerd;      //получаем время передачи
  }
  if (tlgmSwtcAlrm == 1){         //проверяем включена ли передача тревожных сообщений
    String tlgmMssgAlrm = sttsMssgAlrm();         //получаем строку тревожного сообщения одновременно проверяя tlgmSendAlrm на тревоги
    if (tlgmSendAlrm == 1){         //проверяем tlgmSendAlrm
      tlgmAlrmTime = millis();
      if (tlgmAlrmTime > tlgmAlrmTimeNext){         //сравниваем текущего времени с временем передачи тревожного сообщения
        tlgmSendData (tlgmMssgAlrm);        //отправляем тревожное сообщение
        tlgmSendAlrm = 0;       //после отправки тревожного сообщения переводим tlgmSendAlrm в выключенное состояние
        tlgmAlrmTimeNext = tlgmAlrmTime + tlgmAlrmTimePerd;       //получаем время передачи следующего тревожного сообщения
      }
    }
  }
}

void tlgmReadData(int numNewMessages){
  for (int i = 0; i < numNewMessages; i++){
    if (bot.messages[i].type == F("callback_query")){       //если тип "callback_query", значит кнопка клавиатуры нажата
      String tlgmMssg = bot.messages[i].text;
      if (tlgmMssg == F("ON")){
        tlgmSwtcAlrm = 1;
        tlgmSendData("Alarm send: On");
      } 
      else if (tlgmMssg == F("OFF")){
        tlgmSwtcAlrm = 0;
        tlgmSendData("Alarm send: Off");
      }
      else if (tlgmMssg == F("status")){
        tlgmSendData(sttsMssgStts());
      }
    } 
    else {
      String chat_id = String(bot.messages[i].chat_id);
      String tlgmMssg = bot.messages[i].text;
      if (tlgmMssg == F("/options")){
      // Keyboard Json - это массив массивов.
      // Размер основного массива - это то, сколько вариантов строк имеет клавиатура
      // Размер вложенных массивов - это то, сколько колоумов имеет эта строка
      // Свойство" текст " - это то, что отображается на клавиатуре
      // Свойство "callback_data" - это текст, который отправляется при нажатии кнопки   
        String tlgmKbrdJson = F("[[{ \"text\" : \"ON\", \"callback_data\" : \"ON\" },{ \"text\" : \"OFF\", \"callback_data\" : \"OFF\" }],");
        tlgmKbrdJson += F("[{ \"text\" : \"status\", \"callback_data\" : \"status\" }],");
        tlgmKbrdJson += F("[{ \"text\" : \"restart\", \"callback_data\" : \"restart\" }]]");
        bot.sendMessageWithInlineKeyboard(chat_id, "StoneSmartHomeTrud", "", tlgmKbrdJson);
      }
      // Когда пользователь впервые использует бота, он посылает команду " / start
      // Так что это хорошее место, чтобы пользователи знали, какие команды доступны
      if (tlgmMssg == F("/start")){
        bot.sendMessage(chat_id, "/options : returns the inline keyboard\n", "Markdown");
      }
      else {
        String tlgmKbrdJson = F("[[{ \"text\" : \"ON\", \"callback_data\" : \"ON\" },{ \"text\" : \"OFF\", \"callback_data\" : \"OFF\" }],");
        tlgmKbrdJson += F("[{ \"text\" : \"status\", \"callback_data\" : \"status\" }],");
        tlgmKbrdJson += F("[{ \"text\" : \"restart\", \"callback_data\" : \"restart\" }]]");
        bot.sendMessageWithInlineKeyboard(chat_id, "StoneSmartHomeTrud\nhttp://192.168.2.101", "", tlgmKbrdJson);        
        //bot.sendMessage(tlgmChId, bot.messages[i].text);
      }
    }
  }
}

void tlgmSendData (String tlgmStrg){
  if (tlgmStrg != ""){
    bot.sendMessage(tlgmChId, tlgmStrg);
  }
}
