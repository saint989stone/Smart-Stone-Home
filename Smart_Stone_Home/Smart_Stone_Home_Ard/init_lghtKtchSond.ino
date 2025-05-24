void init_lghtKtchSond(){
  pinMode (lghtKtchSondMcVm, INPUT);
}
void lghtKtchSond(){
  if (lghtKtch["lghtKtchSwtcSond"] == 1){
    for (int i = 0; i < FFT_N; i ++){    //считываем заданное количество отсчетов
      int lghtKtchSondSmpl = analogRead(lghtKtchSondMcVm) - 511;        //считываем показания микрофона и вычитаем отрицательную полу-волну
      if (lghtKtchSondSmpl < 5 && lghtKtchSondSmpl > -5){       //игнлрируем помехи АЦП
        lghtKtchSondSmpl = 0;
      }
      fft_input[i++] = lghtKtchSondSmpl;    //сохраняем действительные значения в четные отсчеты
      fft_input[i] = 0;          //задаем нечетным отсчетам значение 0
      if (Serial1.available()){
        serlRead();
      }
    }
    fft_window();       //функция-окно, повышающая частотное разрешение
    fft_reorder();        //реорганизовываем данные перед запуском FFT
    fft_run();        //обратываем данные в FFT
    fft_mag_log();        //извлекаем данные, обработанные FFT
    if (fft_log_out[freqLowwFftN] > freqLowwLevl){     //если значение низких частот превысило предел
      digitalWrite(lghtKtchLgWR, HIGH);         //зажигаем красный светодиод
    }
    else{
      digitalWrite(lghtKtchLgWR, LOW);        //гасим красный светодиод
    }
    if (fft_log_out[freqMiddFftN] > freqMiddLevl){        //если значение средних частот превысило предел         
      digitalWrite(lghtKtchLgWG, HIGH);       //зажигаем зеленый светодиод
      digitalWrite(lghtKtchLgWW, LOW);        //гасим синий светодиод (фон средних частот)
    }
    else{
      digitalWrite(lghtKtchLgWG, LOW);        //гасим зеленый светодиод
      digitalWrite(lghtKtchLgWW, HIGH);         //зажигаем синий светодиод (фон средних частот)
      //digitalWrite(lghtKtchLghF, HIGH);
      //digitalWrite(lghtKtchLghC, HIGH);
    }
    if (fft_log_out[freqHighFftN] > freqHighLevl){      //если значение высоких частот превысило предел
      digitalWrite(lghtKtchLgWB, HIGH);        //зажигаем синий светодиод
    }
    else{
      digitalWrite(lghtKtchLgWB, LOW);         //зажигаем зеленый светодиод
    }
  }
  else if (lghtKtch["lghtKtchSwtcLghW"] == 0 && lghtKtch["lghtKtchSwtcWtfl"] == 0 && lghtKtch["lghtKtchSwtcSond"] == 0){
    lghtKtchLghWStop();
  }
  else if (lghtKtch["lghtKtchSwtcSwtc"] == 0){
    lghtKtchLghWStop();
  }
}
