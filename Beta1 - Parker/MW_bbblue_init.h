#ifndef _MW_BBBLUE_INIT_H_
#define _MW_BBBLUE_INIT_H_

#if ( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER) )
    #define rc_initialize() (0)	
    #define rc_enable_motors() (0)
    #define rc_disable_motors() (0)
    #define rc_cleanup() (0)
#else 
    #ifdef __cplusplus
    extern "C"
    {
    #endif 
        #ifdef _roboticscape_in_use_
            extern int rc_initialize();
            extern int rc_cleanup();
        #else
            #define rc_initialize() (0)	
            #define rc_cleanup() (0)
        #endif
            
        #ifdef _RTT_DCMOTOR_INUSE_            
            extern int rc_enable_motors();
            extern int rc_disable_motors();
        #else
            #define rc_enable_motors() (0)
            #define rc_disable_motors() (0)
        #endif
    #ifdef __cplusplus
    }
    #endif
#endif
#endif