#include <assert.h>
#include <iostream>
using namespace std;

#define batteryLowerTempLimit 0
#define batteryUpperTempLimit 45
#define batteryLowerSocLimit 20
#define batteryUpperSocLimit 80
#define batteryUpperChargeRate 0.8


bool ValLimitCheck(float Val,float LowerLimit,float UpperLimit)
{
     if(Val < LowerLimit || Val > UpperLimit)
     {
          return false;
     }
     else
     {
          return true;
     }
}

bool batteryTempIsOk(float temperature,float LowerTempLimit,float UpperTempLimit)
{
    return ValLimitCheck(temperature,LowerTempLimit,UpperTempLimit);
}

bool batterySocIsOk(float soc,float LowerSocLimit,float UpperSocLimit)
{
  return ValLimitCheck(soc,LowerSocLimit,UpperSocLimit);
}

bool batteryChargeRateIsOk(float chargeRate,float UpperChargeRate)
{
  return !(chargeRate > UpperChargeRate); 
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
