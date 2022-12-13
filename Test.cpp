#include "checker.hpp"
#include <assert.h>

int main() {

//Testing the Value with in the limit
assert(ValLimitCheck(25,0,80));
assert(ValLimitCheck(0,0,80));
assert(ValLimitCheck(80,0,80));
assert(ValLimitCheck(-10,0,80)==false);
assert(ValLimitCheck(100,0,80)==false);

//Testing Battery Temperature  
assert(battery_Temp_SOCIsOk(25,batteryLowerTempLimit,batteryUpperTempLimit));
assert(battery_Temp_SOCIsOk(0,batteryLowerTempLimit,batteryUpperTempLimit));
assert(battery_Temp_SOCIsOk(45,batteryLowerTempLimit,batteryUpperTempLimit));
assert(battery_Temp_SOCIsOk(-10,batteryLowerTempLimit,batteryUpperTempLimit)==false);
assert(battery_Temp_SOCIsOk(50,batteryLowerTempLimit,batteryUpperTempLimit)==false);

//Testing the Battery SOC
assert(battery_Temp_SOCIsOk(25,batteryLowerSocLimit,batteryUpperSocLimit));
assert(battery_Temp_SOCIsOk(20,batteryLowerSocLimit,batteryUpperSocLimit));
assert(battery_Temp_SOCIsOk(80,batteryLowerSocLimit,batteryUpperSocLimit));
assert(battery_Temp_SOCIsOk(0,batteryLowerSocLimit,batteryUpperSocLimit)==false);
assert(battery_Temp_SOCIsOk(100,batteryLowerSocLimit,batteryUpperSocLimit)==false);

//Testing the Battery Charging Rate
assert(batteryChargeRateIsOk(0,batteryUpperChargeRate));
assert(batteryChargeRateIsOk(0.8,batteryUpperChargeRate));
assert(batteryChargeRateIsOk(1,batteryUpperChargeRate)==false);



  assert(batteryIsOk(25,batteryLowerTempLimit,batteryUpperTempLimit,70,batteryLowerSocLimit,batteryUpperSocLimit, 0.7,batteryUpperChargeRate) == true);
  assert(batteryIsOk(50 ,batteryLowerTempLimit,batteryUpperTempLimit,85,batteryLowerSocLimit,batteryUpperSocLimit, 0,batteryUpperChargeRate) == false);
  assert(batteryIsOk(25 ,batteryLowerTempLimit,batteryUpperTempLimit,85,batteryLowerSocLimit,batteryUpperSocLimit, 10,batteryUpperChargeRate) == false);
  assert(batteryIsOk(25 ,batteryLowerTempLimit,batteryUpperTempLimit,70,batteryLowerSocLimit,batteryUpperSocLimit, 10,batteryUpperChargeRate) == false);

assert(debugMessge(true,"Temperature out of range!\n")=="Temperature out of range!\n");
assert(debugMessge(false,"Temperature out of range!\n")=="No error");

}


