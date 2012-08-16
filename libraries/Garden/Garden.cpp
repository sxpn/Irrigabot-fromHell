/* Garden.h library for IrrigaBOT-fromHell
  if code is crap you can give advice here :
  https://github.com/sxpn/Irrigabot-fromHell
  for insults here : /dev/null
  builds an instance of a "garden" with sensors,
  actuators and logging.
  
  Created by sxpn June 22, 2012.
*/

#include "Arduino.h"
#include "Garden.h"

Garden::Garden(String configuration)
{
 //constructor read configuration string and creates sensors and actuators 
 //this will be done by a parser yet to be written
 //WORK IN PROGRESS configuration file structure to be defined first
}

Sensor::Sensor(int pinsensor)
{
  _pinsensor = pinsensor ;
}

int Sensor::readsensor()
{
  return (analogRead(_pinsensor));
}

Actuator::Actuator(int pinactuator)
{
  pinMode(pinactuator, OUTPUT);
  _pinactuator = pinactuator;
}

/*Electrovalve control function
  to avoid power loss problems while E.V. is open, the state of the electrovalve will be saved to sd card
  a manual override "all valve closed" is to be added in case of human intervation to close the valves*/


int Actuator::openactuator() //open the electrovalve
{
  if (_state == 0 )                   //verify that the electrovalve is closed
  {
    digitalWrite(_pinactuator, HIGH); //impulse to open the electrovalve
    _state = 1 ;    // change state of electrovalve to open
    delay (50);
    digitalWrite(_pinactuator, LOW); //end impulse
    return (0);
  }
  else                                //if valve is already open !! OMG 
  {
    return (-1);                      // returns error
  }
}

int Actuator::closeactuator() //close the electrovalve
{
  if (_state == 1 )                   //verify that the electrovalve is open
  {
    digitalWrite(_pinactuator, HIGH); //impulse to close the electrovalve
    _state = 0 ;                      // change state of electrovalve to close
    delay (50);
    digitalWrite(_pinactuator, LOW); //end impulse
    return (0);
  }
  else                                //if valve is already closed !! OMG 
  {
    return (-1);                      // does nothing and returns error
  }
}

int Actuator::stateactuator(); //reads the state of the actuator from memory , from sd card in the future
{
  return (_state);             // returns the value corresponding to the state
}

int Actuator::updatestateactuator();
{
  //updates the state of the actuator on the sd card 
  //WORK IN PROGRESS configuration file structure to be defined first
}

