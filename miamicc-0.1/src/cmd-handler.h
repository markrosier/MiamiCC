/* 
 * File:   cmd-handler.h
 * Author: markr_001
 *
 * Created on 07 August 2015, 10:08
 */

#ifndef CMD_HANDLER_H
#define	CMD_HANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

struct command {
    int  commandID;
    int  param;
    unsigned  msRepeatTime;
    bool checkReturnValue;
    BYTE toggleMode;
    BYTE comparisonType;
    int  value1;
    int  value2;
// internal variables
    unsigned msTimeLeft;
    unsigned msToggleTimeLeft;
    BYTE currentToggleValue;
    struct command * nextCommand;
};    

enum {
    retval_eq_value1    = 0,
    retval_lt_value1    = 1,
    retval_gt_value1    = 2,
    retval_ne_value1    = 3,
    retval_within_range_value1_value2  = 4,
    retval_outside_range_value1_value2 = 5
};

typedef struct command cmd;

// function prototypes



// local function prototypes
void generateInterrupt (void);
bool doCommand( cmd * cmdPtr);
void cmdHandlerInit( void );
void cmdHandlerService( void );

#ifdef	__cplusplus
}
#endif

#endif	/* CMD_HANDLER_H */

