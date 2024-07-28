#ifndef BATTERY_CHECKER_INITIALIZATION_H
#define BATTERY_CHECKER_INITIALIZATION_H

#include "soc_checker.h"
#ifdef WARNING_SOC_CHECK
SOC_RANGE soc_ranges[] = {
    { 0.0, 20.0, low_soc_breach}, { 21.0, 24.0, low_soc_warning},{ 25.0, 75.0, normal},{ 76.0, 80.0, high_soc_warning},{ 81.0, 100.0, high_soc_breach}
};
#elif
SOC_RANGE soc_ranges[] = {
    { 0.0, 20.0, low_soc_breach},{ 25.0, 75.0, normal},{ 81.0, 100.0, high_soc_breach}
};
#endif
