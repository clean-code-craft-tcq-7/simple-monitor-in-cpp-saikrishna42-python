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

void debugMessge(bool debug,string Message)
{
    if(debug)
    {
        cout<<Message;
    }
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
     bool tempOk=false,SocOk=false,ChargeRateOk=false;
    tempOk = batteryTempIsOk(temperature,batteryLowerTempLimit,batteryUpperTempLimit);
    SocOk  = batterySocIsOk(soc,batteryLowerSocLimit,batteryUpperSocLimit);
    ChargeRateOk       = batteryChargeRateIsOk(chargeRate,batteryUpperChargeRate);
    debugMessge(!tempOk,"Temperature out of range!\n");
    debugMessge(!SocOk,"State of Charge out of range!\n");
    debugMessge(!ChargeRateOk,"Charge Rate out of range!\n");
  
  return tempOk&&SocOk&&ChargeRateOk;
 
}



int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
