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

bool battery_Temp_SOCIsOk(float value,float LowerLimit,float UpperLimit)
{
    return ValLimitCheck(value,LowerLimit,UpperLimit);
}



bool batteryChargeRateIsOk(float chargeRate,float UpperChargeRate)
{
  return !(chargeRate > UpperChargeRate); 
}

string debugMessge(bool debug,string Message)
{
    if(debug)
    {
        cout<<Message;
        return Message;
    }
    return "No error";
}

bool batteryIsOk(float temperature,float LowerTempLimit,float UpperTempLimit,
                 float soc, float LowerSocLimit,float UpperSocLimit,
                 float chargeRate,float UpperChargeRate) {
     bool tempOk=false,SocOk=false,ChargeRateOk=false;
    tempOk = battery_Temp_SOCIsOk(temperature,LowerTempLimit,UpperTempLimit);
    SocOk  = battery_Temp_SOCIsOk(soc,LowerSocLimit,UpperSocLimit);
    ChargeRateOk       = batteryChargeRateIsOk(chargeRate,UpperChargeRate);
 
    debugMessge(!tempOk,"Temperature out of range!\n");
    debugMessge(!SocOk,"State of Charge out of range!\n");
    debugMessge(!ChargeRateOk,"Charge Rate out of range!\n");
  
  return tempOk&&SocOk&&ChargeRateOk;
 
}



