void lcdDisplay(){
  if(cycle%textDisplayCycle==0){
    textFlipFlop=!textFlipFlop;
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
  lcd.print("-");
  lcd.print(map(moistureLevel, 0, 255, 0, 99));
  lcd.print("% ");
}

void lcdSolarLevel(bool solarOn){
  lcd.setCursor(6, 1);
  if(solarOn){
    lcd.write(byte(3));
  }
  else{  
    lcd.write(byte(2));
  }
  lcd.print("-");
  lcd.print(map(cycle%solarCycleLength, 0, solarCycleLength, 99, 0));
  lcd.print(" ");
}

void lcdWaterLightSensor(bool sensorTriggered){
  lcd.setCursor(0, 0);
  if(sensorTriggered){
    lcd.print("*");
  }
  else{
    lcd.print(" ");
  }
}

void lcdSolarLightSensor(bool sensorTriggered){
  lcd.setCursor(6, 0);
  if(sensorTriggered){
    lcd.print("*");
  }
  else{
    lcd.print(" ");
  }
}

void lcdText(bool textCycle){
  lcd.setCursor(10, 0);
  if(textCycle){ 
    lcd.write(" BUILD");
    lcd.setCursor(11, 1);
    lcd.write("A BOT");
  }
  else{
    lcd.write("GROW A");
    lcd.setCursor(11, 1);
    lcd.write("PLANT");
  } 
} 