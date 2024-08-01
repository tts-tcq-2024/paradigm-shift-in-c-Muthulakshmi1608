#include <assert.h>
#include "soc_status.h"
#include "temperature_status.h"
#include "range_checking.h"

#define WARNING_SOC_CHECK TRUE
#define WARNING_TEMP_CHECK TRUE
BATTERY_STATUS_RANGE soc_ranges[] = {
#ifdef WARNING_SOC_CHECK
    { 0.0, 20.0, low_soc_breach}, { 21.0, 24.0, low_soc_warning},{ 25.0, 75.0, normal},{ 76.0, 80.0, high_soc_warning},{ 81.0, 100.0, high_soc_breach}
#else
    { 0.0, 20.0, low_soc_breach},{ 25.0, 75.0, normal},{ 81.0, 100.0, high_soc_breach}
#endif
};



BATTERY_STATUS_RANGE temp_ranges[] = {
#ifdef WARNING_TEMP_CHECK
    { -20.0, 0.0, low_temp_breach}, { 0.0, 2.25, low_temp_warning},{ 2.25, 42.75, temp_normal},{ 42.75, 45.0, high_temp_warning},{ 45.0, 100.0, high_temp_breach}
#else
BATTERY_STATUS_RANGE temp_ranges[] = {
    { -20.0, 0.0, low_temp_breach},{ 2.25, 42.75, temp_normal},{ 45.0, 100.0, high_temp_breach}
#endif
};


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
