
int analogReadMultiPlexR( int adcpin, byte sensorpin0, byte sensorpin1, byte sensoraddress)
{
  byte pinstate1 = LOW;
  byte pinstate0 = LOW;
  int value = 0;
  pinstate1 = (sensoraddress & 2) >> 1;
  pinstate0 = (sensoraddress & 1);
  digitalWrite(sensorpin1, pinstate1);
  digitalWrite(sensorpin0, pinstate0);
  value = analogRead(adcpin);
  digitalWrite(sensorpin1, LOW);
  digitalWrite(sensorpin0, LOW);
  return(value);
}

int analogReadMultiPlex( int adcpin, byte sensorpin0, byte sensorpin1, byte sensoraddress)
{
  byte pinstate1 = LOW;
  byte pinstate0 = LOW;
  pinstate1 = (sensoraddress & 2) >> 1;
  pinstate0 = (sensoraddress & 1);
  digitalWrite(sensorpin1, pinstate1);
  digitalWrite(sensorpin0, pinstate0);
  return( analogRead(adcpin));
}

