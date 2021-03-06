/*
 * debug.h
 *
 * #define DEBUG_MODE to get some helpful development tools
 *
 * Created: 7/14/2017 1:50:04 PM
 *  Author: josh
 */ 


#ifndef DEBUG_H_
#define DEBUG_H_

// This enables debug features like output on the debug port
// and some extra sanity parameter checks.

#define DEBUG_MODE

#ifdef DEBUG_MODE

// Use pin 19 (PE2)for debug port
#define DEBUG_INIT()            SBI( DDRE  , 2); SBI(DDRE,1)         // DebugA on pin #19 PE2
// DebugB on pin  #6 PE1
#define DEBUGA_1()               SBI( PORTE , 2)
#define DEBUGA_0()               CBI( PORTE , 2)
#define DEBUGA_PULSE(width_us)   DEBUGA_1();_delay_us(width_us-2);DEBUGA_0()   // Generate a pulse. width must be >= 2us.

#define DEBUGB_1()               SBI( PORTE , 1)
#define DEBUGB_0()               CBI( PORTE , 1)
#define DEBUGB_PULSE(width_us)   DEBUGB_1();_delay_us(width_us-2);DEBUGB_0()   // Generate a pulse. width must be >= 2us.

#define DEBUG_ERROR(error)       debug_error(error)                 // output an error code

#define DEBUG_

#else

#define DEBUG_INIT()
#define DEBUGA_1()
#define DEBUGA_0()
#define DEBUGA_PULSE(width_us)
#define DEBUGB_1()
#define DEBUGB_0()
#define DEBUGB_PULSE(width_us)

#endif

// Use ADC6 (pin 19) for an analog input- mostly for dev work
// Returns 0-255 for voltage between 0 and Vcc
// Handy to connect a potentiometer here and use to tune params
// like rightness or speed

uint8_t analogReadPin19(void);


#endif /* DEBUG_H_ */