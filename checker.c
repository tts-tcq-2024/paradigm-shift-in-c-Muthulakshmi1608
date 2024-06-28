#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool battemp(float temperature){
 return (temperature >= 0 && temperature <=45);
  }

bool batsoc(float soc){
  return (soc>=20 && soc<=80);
  }

bool batchargeRate(float chargeRate){
 return (chargeRate<=0.8);
   }

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return (battemp(temperature) || batsoc(soc) || batchargeRate(chargeRate));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7)==true);
  assert(!batteryIsOk(50, 85, 0)==false);
}
