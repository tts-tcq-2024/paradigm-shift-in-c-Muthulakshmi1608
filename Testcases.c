#include <assert.h>
#include "range_checker.h"
#include "Testcases.h"

void testchargerateNormal() {
    assert(!batteryIsOk(50, 85, 0.00)==true);
}

void testbatterywarning() {
    assert(batteryIsOk(2, 78, 0.78));
}

void testtemperaturewarning() {
   assert(!batteryIsOk(10, 50, 0.9));
}

void testBatteryNormal() {
    assert(batteryIsOk(25, 70, 0.70));
}
