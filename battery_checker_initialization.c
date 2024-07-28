#ifndef BATTERY_CHECKER_INITIALIZATION_H
#define BATTERY_CHECKER_INITIALIZATION_H

#include "soc_checker.h"
SOC_RANGE soc_ranges[] = {
    { 0, 20, "low_soc_breach" },
    { 21, 24, "low_soc_warning" },
    { 25, 75, "normal" },
    { 76, 80, "high_soc_warning" },
    { 81, 100, "high_soc_breach" }
};

#endif
