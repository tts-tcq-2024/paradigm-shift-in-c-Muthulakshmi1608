#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool range(float value, float lower_threshhold,float upper_threshhold){
 return((value < lower_threshhold) && (value > upper_threshhold));
}

bool chargeRange(float value, float threshhold){
 return(value > threshhold);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 bool a;
 float threshhold;
 a=(range(temperature,0,45) || (range(soc,20,80)) || (chargeRange(chargeRate,threshhold)));
 return a;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7)==true);
  assert(!batteryIsOk(50, 85, 0)==false);
}
