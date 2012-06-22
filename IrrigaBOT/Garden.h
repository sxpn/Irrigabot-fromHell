/* Garden.h library for IrrigaBOT-fromHell
  if code is crap you can give advice here :
  https://github.com/sxpn/Irrigabot-fromHell
  for insults here : /dev/null
  builds an instance of a "garden" with sensors,
  actuators and logging.
  
  Created by sxpn June 22, 2012.
*/


#ifndef Garden_h
#define Garden_h

#include "Arduino.h"

class Sensor //Sensor class
{
  public :
    Sensor (int pinsensor);
    int readsensor();
  private :
  int _pinsensor;
}

class Actuator //actually this class is for electrovalves that open/close after a HIGH state for less than a second 
{
  public :
    Actuator (int pinactuator);
    int openactuator();
    int closeactuator();
    int stateactuator();
    int updatestateactuator();
  private :
    int _pinactuator;
    int _state;

class Garden
{
  public :
    Garden (String configuration);
    Sensor Sensor (int pinsensor);
    Actuator Actuator (int pin actuator);
    
  private :
  String _configuration;
  int _pinsensor;
  int _pinactuator;
}


// the #include statment and code go here...

#endif




