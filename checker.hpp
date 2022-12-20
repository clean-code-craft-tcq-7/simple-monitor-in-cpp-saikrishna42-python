#include "Project_Config.hpp"
#include <iostream>
#include "Language_Selection.hpp"
using namespace std;

namespace battery
{



class Tempature
{
      private:
        static const float batteryLowerTempLimit;
        static const float batteryUpperTempLimit;
      public:
      static float Conv_temp_cels_2_fahr(float);
      static bool battery_TempIsOk(float );
       
};




class SOC
{
      private:
        static const float  batteryLowerSocLimit;
        static const float  batteryUpperSocLimit;
      public:
      static bool battery_SOCIsOk(float );
      
};
        

 
class ChargeRate
{
      private:
        static const float batteryUpperChargeRate;
        
      public:
       static bool batteryChargeRateIsOk(float);
      
};

 

class BMS:public Tempature,public SOC,public ChargeRate
{
  public:
 
              bool batteryIsOk(float  , float ,float);

};

};



