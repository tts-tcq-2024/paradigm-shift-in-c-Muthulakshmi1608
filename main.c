#include <assert.h>
#include "range_checking.h"

void add_soc_parameter(BatteryParameter *bp) {
    strcpy(bp->name, "soc");  // Properly copying the string to the char array
    
    bp->ranges[0] = (Battery_Status_Range){0.0, 20.0, "State of Charge out of range!", 0};
    bp->ranges[1] = (Battery_Status_Range){21.0, 24.0, "Warning: Approaching discharge", 1};
    bp->ranges[2] = (Battery_Status_Range){24.0, 75.0, "SOC is normal", 3};
    bp->ranges[3] = (Battery_Status_Range){76.0, 80.0, "Warning: Approaching charge-peak", 1};
    bp->ranges[4] = (Battery_Status_Range){81.0, 100.0, "State of Charge out of range!", 0};
    
    bp->isEarlyWarningRequired = false;  // Set early warning flag to false for testing
}
void add_temp_parameter(BatteryParameter *temp_bp) {
    strcpy(temp_bp->name, "temperature");  // Properly copying the string to the char array
    
    temp_bp->ranges[0] = (Battery_Status_Range){-20.0, 0.0, "Temperature out of range!", 0};
    temp_bp->ranges[1] = (Battery_Status_Range){0.0, 2.25, "Warning: Approaching discharge", 1};
    temp_bp->ranges[2] = (Battery_Status_Range){2.25, 42.75, "Temperature is normal", 3};
    temp_bp->ranges[3] = (Battery_Status_Range){42.76, 45, "Warning: Approaching charge-peak", 1};
    temp_bp->ranges[4] = (Battery_Status_Range){46, 100.0, "Temperature out of range!", 0};
    
    temp_bp->isEarlyWarningRequired = false;  // Set early warning flag to false for testing
}
void add_charge_parameter(BatteryParameter *charge_bp) {
    strcpy(charge_bp->name, "chargerate");  // Properly copying the string to the char array
    
    charge_bp->ranges[0] = (Battery_Status_Range){0, 0.75, "chargerate normal!", 0};
    charge_bp->ranges[1] = (Battery_Status_Range){0.76,0.80, "Warning: Approaching charge-peak", 1};
    charge_bp->ranges[2] = (Battery_Status_Range){0.90, 2.00, "chargerate is out of range!", 3};
    
    charge_bp->isEarlyWarningRequired = false;  // Set early warning flag to false for testing
}
int batteryIsOk(float temperature, float soc, float chargeRate)
{
 add_soc_parameter(&bp);
 add_temp_parameter(&temp_bp);
 add_charge_parameter(&charge_bp);
  int soc_status = get_battery_status(soc, soc_ranges, sizeof(soc_ranges) / sizeof(soc_ranges[0]));
  int temp_status = get_battery_status(temperature, temp_ranges, sizeof(temp_ranges) / sizeof(temp_ranges[0]));
  int chargerate_status = get_battery_status(chargeRate, chargerate_ranges, sizeof(chargerate_ranges) / sizeof(chargerate_ranges[0]));
  return (soc_status && temp_status && chargerate_status);
}

int main() {
  assert(batteryIsOk(25, 70, 0.70)==true);// Normal
  assert(!batteryIsOk(50, 85, 0.00)==true);// SOC and temp outofrange,chargerate normal
  assert(batteryIsOk(1, 77, 0.77));//Warning
   assert(!batteryIsOk(10, 50, 0.90));// chargerate outofrange,SOC and temp normal
}
