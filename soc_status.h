
#ifndef SOC_STATUS_H
#define SOC_STATUS_H


int low_soc_breach();
int low_soc_warning();
int normal();
int high_soc_warning();
int high_soc_breach();
int batteryIsOk(float temperature, float soc, float chargeRate);


#endif
