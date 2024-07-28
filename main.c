#include <assert.h>
#include "soc_checker.h"

SOC_RANGE soc_ranges[] = {
    { 0.0, 20.0, low_soc_breach},
    { 21.0, 24.0, low_soc_warning},
    { 25.0, 75.0, normal},
    { 76.0, 80.0, high_soc_warning},
    { 81.0, 100.0, high_soc_breach}
};
int batteryIsOk(float temperature, float soc, float chargeRate)
{
  return (get_soc_status(soc));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
