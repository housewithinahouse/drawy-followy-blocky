void lcdDisplay(){
  if(currentMillis-previousTextMillis>=textAnimationInterval){
    textFlipFlop=!textFlipFlop;
    previousTextMillis = currentMillis;
  }
  lcdSolarLightSensor(solarLightSensorTriggered);
  lcdWaterLightSensor(waterLightSensorTriggered);
  lcdMoistureLevel(waterCycleRunning);
  lcdSolarLevel(solarCycleRunning);
  lcdText(textFlipFlop);
}

void lcdMoistureLevel(bool waterOn){
  lcd.setCursor(0, 1);
  if(waterOn){
    lcd.write(byte(1));   
  }
  else{
    lcd.write(byte(0));
  }
  lcd.print(F("-"));
  lcd.print(map(moistureLevel, 0, 255, 0, 99));
  lcd.print(F("% "));
}

void lcdSolarLevel(bool solarOn){
  lcd.setCursor(6, 1);
  if(solarOn){
    lcd.write(byte(3));
  }
  else{  
    lcd.write(byte(2));
  }
  lcd.print(F("-"));
  lcd.print(map(currentMillis - previousSolarMillis, 0, solarCycleInterval, 99, 0));
  lcd.print(F(" "));
}

void lcdWaterLightSensor(bool sensorTriggered){
  lcd.setCursor(0, 0);
  if(sensorTriggered){
    lcd.print(F("*"));
  }
  else{
    lcd.print(F(" "));
  }
}

void lcdSolarLightSensor(bool sensorTriggered){
  lcd.setCursor(6, 0);
  if(sensorTriggered){
    lcd.print(F("*"));
  }
  else{
    lcd.print(F(" "));
  }
}

void lcdText(bool textCycle){
  lcd.setCursor(10, 0);
  if(textCycle){ 
    lcd.print(F(" BUILD"));
    lcd.setCursor(11, 1);
    lcd.print(F("A BOT"));
  }
  else{
    lcd.print(F("GROW A"));
    lcd.setCursor(11, 1);
    lcd.print(F("PLANT"));
  } 
} 
