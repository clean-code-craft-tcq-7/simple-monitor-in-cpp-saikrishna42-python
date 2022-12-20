#include "checker.hpp"

using namespace battery;

 const float Tempature::batteryLowerTempLimit=0;
 const float Tempature::batteryUpperTempLimit=45;

 const float  SOC::batteryLowerSocLimit=20;
 const float  SOC::batteryUpperSocLimit=80;

 const float ChargeRate::batteryUpperChargeRate=0.8;

bool Val_Below_theLimitCheck(float Val,float LowerLimit)
{
     if(Val < LowerLimit)
     {
          return false;
     }
     else
     {
          return true;
     }
}

bool Val_Above_theLimitCheck(float Val,float UpperLimit)
{
     if( Val > UpperLimit)
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
      return Val_Below_theLimitCheck(temp,batteryLowerTempLimit)&&Val_Above_theLimitCheck(temp,batteryUpperTempLimit);
    #else
       float temp_fahr,LowerLimit_fahr,upperLimit_fahr;
      temp_fahr=Tempature::Conv_temp_cels_2_fahr(temp);
      LowerLimit_fahr=Tempature::Conv_temp_cels_2_fahr(batteryLowerTempLimit);
      upperLimit_fahr= Tempature::Conv_temp_cels_2_fahr(batteryUpperTempLimit);

       
      return Val_Below_theLimitCheck(temp_fahr,LowerLimit_fahr)&&Val_Above_theLimitCheck(temp_fahr,upperLimit_fahr);
    #endif
}



bool SOC::battery_SOCIsOk(float soc)
{
    return Val_Below_theLimitCheck(soc,batteryLowerSocLimit)&&Val_Above_theLimitCheck(soc,batteryUpperSocLimit);
}

bool ChargeRate::batteryChargeRateIsOk(float ChargeRate)
{
    return Val_Above_theLimitCheck(ChargeRate,batteryUpperChargeRate); 
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




