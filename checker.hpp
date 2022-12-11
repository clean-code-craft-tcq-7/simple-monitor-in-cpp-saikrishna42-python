
#include <iostream>
using namespace std;

#define batteryLowerTempLimit 0
#define batteryUpperTempLimit 45
#define batteryLowerSocLimit 20
#define batteryUpperSocLimit 80
#define batteryUpperChargeRate 0.8

bool ValLimitCheck(float Val,float LowerLimit,float UpperLimit);
bool batteryTempIsOk(float temperature,float LowerTempLimit,float UpperTempLimit);
bool batterySocIsOk(float soc,float LowerSocLimit,float UpperSocLimit);
bool batteryChargeRateIsOk(float chargeRate,float UpperChargeRate);
void debugMessge(bool debug,string Message);
bool batteryIsOk(float , float , float ,float,float,float,float,float);