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
     bool tempNotOk=true,SocNotOk=true,ChargeRateNotOk=true;
    tempNotOk = !batteryTempIsOk(temperature,batteryLowerTempLimit,batteryUpperTempLimit);
    if(tempNotOk) 
    {
        cout << "Temperature out of range!\n";
        return false;
    } 
    SocNotOk  = !batterySocIsOk(soc,batteryLowerSocLimit,batteryUpperSocLimit);
    if(SocNotOk)
     {
        cout << "State of Charge out of range!\n";
        return false;
    }
    ChargeRateNotOk       =! batteryChargeRateIsOk(chargeRate,batteryUpperChargeRate);
    if(ChargeRateNotOk) 
    {
        cout << "Charge Rate out of range!\n";
        return false;
    }
 
  return true;
 
}


int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
