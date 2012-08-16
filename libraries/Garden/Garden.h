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
  //calibration values to be added
}

class Actuator //actually this class is for electrovalves that open/close with a HIGH state on pin for 50ms 
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

class Garden //class for garden parameters sensors and valves in each share the same conf parameters
{
  public :
    Garden (String configuration);
    Sensor Sensor (int pinsensor);
    Actuator Actuator (int pin actuator);
    
  private :
  String _configuration;
  int _pinsensor;
  int _pinactuator;
  //parameters to be added
}


// the #include statment and code go here...

#endif




