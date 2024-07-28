#include <assert.h>
#include "soc_checker.h"
#include "temperature_status.h"

#define WARNING_SOC_CHECK TRUE
int batteryIsOk(float temperature, float soc, float chargeRate)
{
  return (get_soc_status(soc));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
