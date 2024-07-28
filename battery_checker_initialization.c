
#include "soc_checker.h"
#include "temperature_status.h"

#ifdef WARNING_SOC_CHECK
SOC_RANGE ranges[] = {
    { 0.0, 20.0, low_soc_breach}, { 21.0, 24.0, low_soc_warning},{ 25.0, 75.0, normal},{ 76.0, 80.0, high_soc_warning},{ 81.0, 100.0, high_soc_breach}
};
#else
SOC_RANGE soc_ranges[] = {
    { 0.0, 20.0, low_soc_breach},{ 25.0, 75.0, normal},{ 81.0, 100.0, high_soc_breach}
};
#endif

#ifdef WARNING_TEMP_CHECK
TEMP_RANGE ranges[] = {
    { 0.0, 20.0, low_temp_breach}, { 21.0, 24.0, low_temp_warning},{ 25.0, 75.0, temp_normal},{ 76.0, 80.0, high_temp_warning},{ 81.0, 100.0, high_temp_breach}
};
#else
TEMP_RANGE ranges[] = {
    { 0.0, 20.0, low_temp_breach},{ 25.0, 75.0, temp_normal},{ 81.0, 100.0, high_temp_breach}
};
#endif
