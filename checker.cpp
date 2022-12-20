#include "checker.hpp"

using namespace battery;

 const float Tempature::batteryLowerTempLimit=0;
 const float Tempature::batteryUpperTempLimit=45;

 const float  SOC::batteryLowerSocLimit=20;
 const float  SOC::batteryUpperSocLimit=80;

 const float ChargeRate::batteryUpperChargeRate=0.8;

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

void debugMessge(bool debug,string Message)
{
    if(debug)
    {
        cout<<Message;
        
    }
   
}

float Tempature::Conv_temp_cels_2_fahr(float temp)
{
    return (temp*1.8+32);
}


bool Tempature::battery_TempIsOk(float temp)
{
    #if(temp_In==TEMP_IN_celcius)
      return ValLimitCheck(temp,batteryLowerTempLimit,batteryUpperTempLimit);
    #else
      static float temp_fahr,LowerLimit_fahr,upperLimit_fahr;
      temp_fahr=Tempature::Conv_temp_cels_2_fahr(temp);
      LowerLimit_fahr=Tempature::Conv_temp_cels_2_fahr(batteryLowerTempLimit);
      upperLimit_fahr= Tempature::Conv_temp_cels_2_fahr(batteryUpperTempLimit);

       
      return ValLimitCheck(temp_fahr,LowerLimit_fahr,upperLimit_fahr);
    #endif
}



bool SOC::battery_SOCIsOk(float soc)
{
    return ValLimitCheck(soc,batteryLowerSocLimit,batteryUpperSocLimit);
}

bool ChargeRate::batteryChargeRateIsOk(float ChargeRate)
{
    return !(ChargeRate > batteryUpperChargeRate); 
}

bool BMS::batteryIsOk(float temperature,
                 float soc,
                 float chargeRate) {
     bool tempOk=false,SocOk=false,ChargeRateOk=false;
    tempOk = battery_TempIsOk(temperature);
    SocOk  = battery_SOCIsOk(soc);
    ChargeRateOk       = batteryChargeRateIsOk(chargeRate);
    debugMessge(!tempOk,temp_out_rang_msg);
    debugMessge(!SocOk,soc_out_rang_msg);
    debugMessge(!ChargeRateOk,chargeRate_out_rang_msg);
  
  return tempOk&&SocOk&&ChargeRateOk;
 
}




