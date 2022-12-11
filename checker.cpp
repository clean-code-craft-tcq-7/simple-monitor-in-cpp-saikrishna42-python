#include "checker.hpp"


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

bool batteryIsOk(float temperature,float LowerTempLimit,float UpperTempLimit,
                 float soc, float LowerSocLimit,float UpperSocLimit,
                 float chargeRate,float UpperChargeRate) {
     bool tempOk=false,SocOk=false,ChargeRateOk=false,SocNotOk=false;
    tempOk = batteryTempIsOk(temperature,LowerTempLimit,UpperTempLimit);
    SocOk  = batterySocIsOk(soc,LowerSocLimit,UpperSocLimit);
     
    ChargeRateOk       = batteryChargeRateIsOk(chargeRate,UpperChargeRate);
    debugMessge(!tempOk,"Temperature out of range!\n");
     SocNotOk=tempOk&&!SocOk;
    debugMessge(SocNotOk,"State of Charge out of range!\n");
    debugMessge(!ChargeRateOk,"Charge Rate out of range!\n");
  
  return tempOk&&SocOk&&ChargeRateOk;
 
}



