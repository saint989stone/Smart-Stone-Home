void init_clmtKtch(){
  dht.begin();
}

void clmtKtchClmt(){
  float t = dht.readTemperature(); //Измеряем температуру
  float h = dht.readHumidity(); //Измеряем влажность
  clmtKtch["clmtKtchTextTemp"] = round(t); //Округляем значение и записываем в соотвествующий JSON
  clmtKtch["clmtKtchTextHmdt"] = round(h); //Округляем значение и записываем в соотвествующий JSON
}
