void init_wifi(){
  WiFi.mode(WIFI_STA);        //вводим esp в режим подключения к точке доступа
  WiFi.hostname(host);         //имя сетевого устройства
  WiFi.begin(wifiSSId.c_str(), wifiPass.c_str());         //инициализация wifi функция c_srt преобразует string в массив указателей char(const char* content)
  while (WiFi.status() != WL_CONNECTED){         //пока соединение не установлено
    delay(500);         //делаем задержку в полсекунды
  }
}
