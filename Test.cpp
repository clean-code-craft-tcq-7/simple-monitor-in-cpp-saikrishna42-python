#include "checker.hpp"
#include <assert.h>

using namespace battery;

int main() {

Tempature tmp;
SOC soc;
ChargeRate CR; 
BMS bms;


//Testing Battery Temperature in degree 
  assert(tmp.battery_TempIsOk(25));
  assert(tmp.battery_TempIsOk(0));
  assert(tmp.battery_TempIsOk(45));
  assert(tmp.battery_TempIsOk(-10)==false);
  assert(tmp.battery_TempIsOk(50)==false);



//Testing the Battery SOC

assert(soc.battery_SOCIsOk(25));
assert(soc.battery_SOCIsOk(20));
assert(soc.battery_SOCIsOk(80));
assert(soc.battery_SOCIsOk(0)==false);
assert(soc.battery_SOCIsOk(100)==false);




//Testing the Battery Charging Rate
assert(CR.batteryChargeRateIsOk(0));
assert(CR.batteryChargeRateIsOk(0.8));
assert(CR.batteryChargeRateIsOk(1)==false);


assert(bms.batteryIsOk(25,25,0));
assert(bms.batteryIsOk(-10,25,0)==false);
assert(bms.batteryIsOk(50,25,0)==false);
assert(bms.batteryIsOk(0,0,0)==false);
assert(bms.batteryIsOk(45,100,0)==false);
assert(bms.batteryIsOk(45,20,0.8));
assert(bms.batteryIsOk(0,80,1)==false);




}
