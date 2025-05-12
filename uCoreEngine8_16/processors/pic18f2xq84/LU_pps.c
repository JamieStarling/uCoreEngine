#include "LU_pps.h"

#ifdef UC_SYSTEM_PROCESSOR_18F2xQ84

#if UC_PROCESSOR_HAL_PPS


const uc_pps_registers_t pps_register_lu[] = {
    {0x00, &RA0PPS},  // RA.0
    {0x01, &RA1PPS},  // RA.1
    {0x02, &RA2PPS},  // RA.2
    {0x03, &RA3PPS},  // RA.3
    {0x04, &RA4PPS},  // RA.4
    {0x05, &RA5PPS},  // RA.5 
    {0x06, &RA6PPS},  // RA.6
    {0x07, &RA7PPS},  // RA.7
    {0x08, &RB0PPS},  // RB.0
    {0x09, &RB1PPS},  // RB.1
    {0x0A, &RB2PPS},  // RB.2
    {0x0B, &RB3PPS},  // RB.3
    {0x0C, &RB4PPS},  // RB.4
    {0x0D, &RB5PPS},  // RB.5
    {0x0E, &RB6PPS},  // RB.6
    {0x0F, &RB7PPS},  // RB.7    
    {0x10, &RC0PPS},  // RC.0
    {0x11, &RC1PPS},  // RC.1
    {0x12, &RC2PPS},  // RC.2
    {0x13, &RC3PPS},  // RC.3
    {0x14, &RC4PPS},  // RC.4
    {0x15, &RC5PPS},  // RC.5    
    {0x16, &RC6PPS},  // RC.6
    {0x17, &RC7PPS},  // RC.7
    {0x00, NULL},  // RE.3
};


#endif //
#endif //#if UC_PROCESSOR_HAL_PPS