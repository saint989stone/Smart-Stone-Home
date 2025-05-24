//Функция плавного изменения цвета
//алгоритм цвета 3 - радужный
//красный в зелёный через жёлтый
//зелёный в синий через бирюзовый
//синий в краный через фиолетовый
void lghtKtchWtfl(){
  int R, G, B = 0;
  if (lghtKtch["lghtKtchSwtcWtfl"] == 1){
    if (millis() - lghtKtchWtflTime >= int(lghtKtch["lghtKtchSldrWtfl"])){
      if (lghtKtchWtflRvrs == false){         //проверяем значения переменной реверсии 
        if (lghtKtchWtflCntr <= 85){
          R = 255 - lghtKtchWtflCntr;
          G = lghtKtchWtflCntr;
          B = 0;
        }
        else if (lghtKtchWtflCntr > 85 && lghtKtchWtflCntr <= 170){
          R = 0;
          G = 255 - lghtKtchWtflCntr;
          B = lghtKtchWtflCntr;
        }
        else if (lghtKtchWtflCntr > 170 && lghtKtchWtflCntr <= 255){
          R = lghtKtchWtflCntr;
          G = 0;
          B = 255 - lghtKtchWtflCntr;
          if (lghtKtchWtflCntr == 255){
            lghtKtchWtflRvrs = true;
          }
        }
        lghtKtchWtflCntr ++;          //прибавляем 1 к счетчику
      }
      else if (lghtKtchWtflRvrs == true){         //проверяем значения переменной реверсии 
        if (lghtKtchWtflCntr <= 85){
           R = 255 - lghtKtchWtflCntr;
           G = lghtKtchWtflCntr;
           B = 0;
           if (lghtKtchWtflCntr == 0){
            lghtKtchWtflRvrs = false;
           }
        }
        else if (lghtKtchWtflCntr > 85 && lghtKtchWtflCntr <= 170){
          R = 0;
          G = 255 - lghtKtchWtflCntr;
          B = lghtKtchWtflCntr;
        }
        else if (lghtKtchWtflCntr > 170 && lghtKtchWtflCntr <= 255){
          R = lghtKtchWtflCntr;
          G = 0;
          B = 255 - lghtKtchWtflCntr;
        }
        lghtKtchWtflCntr --;          //убавляем 1 от счетчика 
      }
      lghtKtchWtflTime += int(lghtKtch["lghtKtchSldrWtfl"]);
      analogWrite(lghtKtchLgWR, R);
      analogWrite(lghtKtchLgWG, G);
      analogWrite(lghtKtchLgWB, B);
    }
  }
  else if (lghtKtch["lghtKtchSwtcLghW"] == 0 && lghtKtch["lghtKtchSwtcWtfl"] == 0 && lghtKtch["lghtKtchSwtcMusc"] == 0){
    lghtKtchLghWStop();     
  }
  else if (lghtKtch["lghtKtchSwtcSwtc"] == 0){
    lghtKtchLghWStop();
  }
}
