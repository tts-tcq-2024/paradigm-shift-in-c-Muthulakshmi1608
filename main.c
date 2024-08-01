#include <assert.h>
#include "soc_status.h"
#include "temperature_status.h"

#define WARNING_SOC_CHECK TRUE
#define WARNING_TEMP_CHECK TRUE
int batteryIsOk(float temperature, float soc, float chargeRate)
{
  return (get_battery_status(soc) && get_battery_status(temperature));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7)==true);
  assert(!batteryIsOk(50, 85, 0)==true);
}
