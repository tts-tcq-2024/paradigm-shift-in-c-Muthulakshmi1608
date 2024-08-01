#include <assert.h>
#include "soc_status.h"
#include "temperature_status.h"

#define WARNING_SOC_CHECK TRUE
#define WARNING_TEMP_CHECK TRUE

int batteryIsOk(float temperature, float soc, float chargeRate)
{
  int soc_status = get_battery_status(soc, soc_ranges, sizeof(soc_ranges) / sizeof(soc_ranges[0]));
  int temp_status = get_battery_status(temperature, temp_ranges, sizeof(temp_ranges) / sizeof(temp_ranges[0]));
  return (soc_status && temp_status);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7)==true);
  assert(!batteryIsOk(50, 85, 0)==true);
}
