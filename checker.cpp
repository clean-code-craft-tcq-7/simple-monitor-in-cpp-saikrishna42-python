#include <assert.h>
#include <iostream>
using namespace std;

#define batteryLowerTempLimit 0
#define batteryUpperTempLimit 45
#define batteryLowerSocLimit 20
#define batteryUpperSocLimit 20
#define batteryUpperChargeRate 0.8


bool batteryTempIsOk(float temperature,float batteryLowerTempLimit,float batteryUpperTempLimit)
{
     if (temperature < batteryLowerTempLimit || temperature > batteryUpperTempLimit)
     {
       return false;
     }
    else
    {
      return true;
    }
}


bool batterySocIsOk(float soc,float batteryLowerSocLimit,float batteryUpperSocLimit)
{
  if(soc < batteryLowerSocLimit || soc > batteryUpperSocLimit)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool batteryChargeRateIsOk(float chargeRate,float batteryUpperChargeRate)
{
  if(chargeRate > batteryUpperChargeRate) 
  {
    return false;
  }
  else
  {
    return true;
  }
}


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
  return batteryTempIsOk(temperature,batteryLowerTempLimit,batteryUpperTempLimit) && 
         batterySocIsOk(soc,batteryLowerSocLimit,batteryUpperSocLimit)            &&
         batteryChargeRateIsOk(chargeRate,batteryUpperChargeRate);
 
}


int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
