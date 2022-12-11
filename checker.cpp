#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) {
 /* if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    return false;
  } else if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    return false;
  } else if(chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    return false;
  }*/
  return batteryTempIsOk(temperature)&&batterySocIsOk(soc)&&batteryChargeRateIsOk(chargeRate);
 
}

bool batteryTempIsOk(float temperature)
{
     if (temperature < 0 || temperature > 45)
     {
       return false;
     }
    else
    {
      return true;
    }
}


bool batterySocIsOk(float soc)
{
  if(soc < 20 || soc > 80)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool batteryChargeRateIsOk(float chargeRate)
{
  if(chargeRate > 0.8) 
  {
    return false;
  }
  else
  {
    return true;
  }
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
