#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool range(float value, float lower_threshhold,float upper_threshhold){
 return((value < lower_threshhold) || (value > upper_threshhold));
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 int flg=0;
 flg=((range(temperature,0,45)));
 flg=flg+((range(soc,20,80)));
 flg=flg+ ((chargeRate > 0.8));
 if(flg>1)
 {
  return false;
 }
else
{
return true;
}
}

int main() {
  assert(batteryIsOk(25, 70, 0.7)==true);
  assert(!batteryIsOk(50, 85, 0)==false);
}
