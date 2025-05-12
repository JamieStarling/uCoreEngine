#include "LU_pps.h"

#ifdef UC_SYSTEM_PROCESSOR_16F15313

#if UC_PROCESSOR_HAL_PPS


const uc_pps_registers_t pps_register_lu[] = {
    {0x00, &RA0PPS},  // RA.0
    {0x01, &RA1PPS},  // RA.1
    {0x02, &RA2PPS},  // RA.2
    {0x03, &RA3PPS},  // RA.3
    {0x04, &RA4PPS},  // RA.4
    {0x05, &RA5PPS},  // RA.5 
};

#endif //#ifdef UC_SYSTEM_PROCESSOR_16F15313
#endif //#if UC_PROCESSOR_HAL_PPS