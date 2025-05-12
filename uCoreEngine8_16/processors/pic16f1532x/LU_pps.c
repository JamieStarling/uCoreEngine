#include "LU_pps.h"

#ifdef UC_SYSTEM_PROCESSOR_16F1532X 

#if UC_PROCESSOR_HAL_PPS


const uc_pps_registers_t pps_register_lu[] = {
    {0x00, &RA0PPS},  // RA.0
    {0x01, &RA1PPS},  // RA.1
    {0x02, &RA2PPS},  // RA.2
    {0x03, &RA3PPS},  // RA.3
    {0x04, &RA4PPS},  // RA.4
    {0x05, &RA5PPS},  // RA.5 
    {0x10, &RC0PPS},  // RC.0
    {0x11, &RC1PPS},  // RC.1
    {0x12, &RC2PPS},  // RC.2
    {0x13, &RC3PPS},  // RC.3
    {0x14, &RC4PPS},  // RC.4
    {0x15, &RC5PPS},  // RC.5    
};

#endif 
#endif 