#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266SSDP.h>
#include <FS.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#define tlgmBtkn "_"         //токен telegram bot`a SmartStoneHomeTrudBot

ESP8266WebServer HTTP(80);          //инициализация web server по протоколу http на порту 80
File fsUploadFile;          //инициализация объекта файловой системы
WiFiClientSecure client;        //cоздаём объект для работы с удалёнными хостами
UniversalTelegramBot bot(tlgmBtkn, client);         //инициализация Telegram Bot
       
const size_t cpctSwtcGnrl = JSON_OBJECT_SIZE(5);
const size_t cpctSttsStts = JSON_OBJECT_SIZE(2);
const size_t cpctClmtKtch = JSON_OBJECT_SIZE(3);
const size_t cpctClmtHall = JSON_OBJECT_SIZE(3);
const size_t cpctLghtKtch = JSON_OBJECT_SIZE(13);
const size_t cpctLghtHall = JSON_OBJECT_SIZE(16);
const size_t cpctScrtKtch = JSON_OBJECT_SIZE(4);
const size_t cpctScrtHall = JSON_OBJECT_SIZE(4);
const size_t cpctFireKtch = JSON_OBJECT_SIZE(4);
const size_t cpctFireHall = JSON_OBJECT_SIZE(3);
const size_t cpctWatrKtch = JSON_OBJECT_SIZE(4);
const size_t cpctAdmrHall = JSON_OBJECT_SIZE(3);
const size_t cpctAdmrKtch = JSON_OBJECT_SIZE(3);

DynamicJsonDocument swtcGnrl(cpctSwtcGnrl);
DynamicJsonDocument sttsStts(cpctSttsStts);
DynamicJsonDocument clmtKtch(cpctClmtKtch);
DynamicJsonDocument clmtHall(cpctClmtHall);
DynamicJsonDocument lghtKtch(cpctLghtKtch);
DynamicJsonDocument lghtHall(cpctLghtHall);
DynamicJsonDocument scrtKtch(cpctScrtKtch);
DynamicJsonDocument scrtHall(cpctScrtHall);
DynamicJsonDocument fireKtch(cpctFireKtch);
DynamicJsonDocument fireHall(cpctFireHall);
DynamicJsonDocument watrKtch(cpctWatrKtch);
DynamicJsonDocument admrHall(cpctAdmrHall);
DynamicJsonDocument admrKtch(cpctAdmrKtch);

String jsonStrg = "";          //текстовое представление объекта json

int admrMntgHall = 0;         //переменные передачи данных
int admrMntgKtch = 0;

unsigned long admrMntgTime = 0; 
unsigned long admrMntgTimeNext = 50000;         //переменные Текущего времени и Времени передачи, когда будет производится мониторинг
unsigned long admrMntgTimePerd = 300000;         //период передачи данных по serial складывается с Текущим временем получается Время передачи

unsigned long tlgmReadTime = 0;
unsigned long tlgmReadTimeNext = 0;         //переменные Текущего времени и Времени проверки, когда будет производится проверка получения сообщения
unsigned long tlgmReadTimePerd = 7000;          //период проверки новых сообщений
unsigned long tlgmAlrmTime = 0;
unsigned long tlgmAlrmTimeNext = 0;       //переменные Текущего времени и Времени проверки, когда будет производится отправка тревожных сообщений
unsigned long tlgmAlrmTimePerd = 100000;        //период отправки тревожных сообщений 

String wifiSSId = "__";         //имя wifi сети
String wifiPass = "__";        //пароль wifi сети
String host = "esp_web_server";         //имя hostname
String ssdp = "esp_web_server";          //имя ssdp

String ipAdHall = "__";     //ip адрес ESP Hall

String tlgmChId = "__";      //chat_id чата с telegram bot SmartStoneHomeTrud
int tlgmSwtcAlrm = 1;         //переменная вкл. и выкл. тревожных сообщений
int tlgmSendAlrm = 0;         //переменная отправки сообщений в случае тревоги

const char* httpUser = "admin";         //логин от страницы
const char* httpPass = "123";         //пароль от страницы

void setup() {
  init_serl();
  init_fs();         
  init_wifi();      //инициализация wifi
  init_ssdp();          //инициализация ssdp
  init_json();
  init_http();          //инициализация web server`a
  init_tlgm();
}

void loop() {
  while (!Serial.available()){
    stts();
    admr();
    tlgm();
    HTTP.handleClient();        //слушаем порт HTTP
    delay(1);
  }
  while (Serial.available()){
    serlRead();
  }
}
