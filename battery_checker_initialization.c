
#include "soc_status.h"
#include "temperature_status.h"
#include "range_checking.h"


BATTERY_STATUS_RANGE ranges[] = {
#ifdef WARNING_SOC_CHECK
    { 0.0, 20.0, low_soc_breach}, { 21.0, 24.0, low_soc_warning},{ 25.0, 75.0, normal},{ 76.0, 80.0, high_soc_warning},{ 81.0, 100.0, high_soc_breach}
#else
    { 0.0, 20.0, low_soc_breach},{ 25.0, 75.0, normal},{ 81.0, 100.0, high_soc_breach}
};
#endif


BATTERY_STATUS_RANGE temp_ranges[] = {
#ifdef WARNING_TEMP_CHECK
    { -20.0, 0.0, low_temp_breach}, { 0.0, 2.25, low_temp_warning},{ 2.25, 42.75, temp_normal},{ 42.75, 45.0, high_temp_warning},{ 45.0, 100.0, high_temp_breach}
#else
BATTERY_STATUS_RANGE temp_ranges[] = {
    { -20.0, 0.0, low_temp_breach},{ 2.25, 42.75, temp_normal},{ 45.0, 100.0, high_temp_breach}
};
#endif
