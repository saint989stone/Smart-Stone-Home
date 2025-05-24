#include <ArduinoJson.h>  //подлючаем библиотеку ArduinoJson 6.13 ссылка на проект https://arduinojson.org/
#include "DHT.h"  //подключаем библиотеку по работе с датчиком температуры и влажности DHT-22

#define LOG_OUT 1 //включаем фун. для логарифмических формата
#define FFT_N 256 //задаем количество выходных отсчетов

#include <FFT.h>  //подключаем библиотеку FFT - быстрое преобразование Фурье http://wiki.amperka.ru/_media/slot-box:light-show:fft.zip

#define lghtKtchLgWR 2  //пины светодиодов
#define lghtKtchLgWG 3
#define lghtKtchLgWB 4
#define lghtKtchLgWW 5

#define lghtKtchSondMcVm A1 //пины микрофона

#define lghtKtchNgSgLght A3 //пин фоторезистора Ночного Режима   

#define scrtKtchIndcWndw A4 //пин датчика движения Scrt направленный на окно
#define scrtKtchIndcEntc A5 //пин датчика движения Scrt направленный на проход из корридора

#define fireKtchIndcRoom A6 //пин датчика газа Fire направленный на окно
#define fireKtchIndcCkng A7 //пин датчика газа Fire направленный на печку

#define clmtKtchText A8 //пин датчика температуры и влажности clmt

#define freqLowwFftN 2  //распределяем номера отчетов по частотам
#define freqMiddFftN 30 //весь диапазон FFT_N / 2
#define freqHighFftN 60

#define freqLowwLevl 38 //уровни Частот FFT
#define freqMiddLevl 18
#define freqHighLevl 15

DHT dht(clmtKtchText, DHT22); //инициализация датчика Температуры и Влажности 

const size_t cpctClmtKtch = JSON_OBJECT_SIZE(3);  //задаем размер для каждого json массива
const size_t cpctLghtKtch = JSON_OBJECT_SIZE(13); //ссылка https://arduinojson.org/v6/assistant/    
const size_t cpctScrtKtch = JSON_OBJECT_SIZE(4);     
const size_t cpctFireKtch = JSON_OBJECT_SIZE(4);
const size_t cpctWatrKtch = JSON_OBJECT_SIZE(4);
const size_t cpctAdmrKtch = JSON_OBJECT_SIZE(3);

DynamicJsonDocument clmtKtch(cpctClmtKtch); //создаем json массив из массива данных в init_json
DynamicJsonDocument lghtKtch(cpctLghtKtch);         
DynamicJsonDocument scrtKtch(cpctScrtKtch);
DynamicJsonDocument fireKtch(cpctFireKtch);
DynamicJsonDocument watrKtch(cpctWatrKtch);
DynamicJsonDocument admrKtch(cpctAdmrKtch);

String jsonStrg = ""; 
//SoftwareSerial serl_esp(4, 5);

//bool serlSendLghtHall = false;          //переменная вкл/выкл передачи json по Serial
bool serlSendLghtKtch = false;
unsigned long serlSendTime, serlSendTimeNext;         //переменные Текущего времени и Времени передачи, когда будет произведена передача данных по serial
unsigned int serlSendTimePerd = 5000;         //период передачи данных по serial складывается с Текущим временем получается Время передачи

int lghtKtchWtflCntr = 0;     //счетчик Функции плавного изменения цвета изменяется от 0 до 255
uint32_t lghtKtchWtflTime = 0;          //переменная хранения времени 
bool lghtKtchWtflRvrs = false;          //переменная для обратного изменения цвета функции водопад

void setup() {
  init_serl();
  init_json();
  init_scrtKtch();
  init_fireKtch();
  init_clmtKtch();
  init_lghtKtchLghW();
  init_lghtKtchSond();  
}

void loop() {
  scrtKtchScrt();
  fireKtchFire();
  clmtKtchClmt();
  lghtKtchLghW();
  lghtKtchWtfl();
  lghtKtchSond();
  admrKtchAdmr();
  serlRead();
  serlSend();
}
