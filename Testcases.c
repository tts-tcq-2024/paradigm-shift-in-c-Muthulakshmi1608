#include <assert.h>
#include "range_checker.h"
#include "Testcases.h"

void testchargerateNormal() {
    assert(!batteryIsOk(50, 85, 0.00)==true);
}

void testtemperaturewarning() {
   assert(!batteryIsOk(10, 50, 0.9));
}


