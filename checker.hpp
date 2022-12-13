
#include <iostream>
using namespace std;

#define batteryLowerTempLimit 0
#define batteryUpperTempLimit 45
#define batteryLowerSocLimit 20
#define batteryUpperSocLimit 80
#define batteryUpperChargeRate 0.8

bool ValLimitCheck(float Val,float LowerLimit,float UpperLimit);
bool battery_Temp_SOCIsOk(float ,float ,float );
;
bool batteryChargeRateIsOk(float chargeRate,float UpperChargeRate);
string debugMessge(bool debug,string Message);
bool batteryIsOk(float , float , float ,float,float,float,float,float);