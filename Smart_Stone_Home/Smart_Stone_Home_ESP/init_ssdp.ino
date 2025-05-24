void init_ssdp(void){
  HTTP.on("/status.xml", HTTP_GET, [](){          //задаем страницу описания устройства
    SSDP.schema(HTTP.client());
  });
  SSDP.setDeviceType("upnp:rootdevice");          //задается тип устройства
  SSDP.setSchemaURL("status.xml");          //указываем страницу с описанием устройства
  SSDP.setHTTPPort(80);               //задаем на каком HTTP порту работает страница
  SSDP.setName(ssdp);         //задаем имя устройства
  SSDP.setSerialNumber("001");        //серийный номер устройства
  SSDP.setURL("/");         //адрес страницы по которому можно обращаться
  SSDP.setModelName("esp_web_server");          //название модели устройства
  SSDP.setModelURL("");           //адрес модели
  SSDP.setManufacturer("Stone");          //название производителя
  SSDP.setManufacturer("");           //адрес производителя
  SSDP.begin();         //старт протокола
   
}
