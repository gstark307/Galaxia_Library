///
/// @file		Event2.ino
/// @brief		Task for Energia MT
/// @n
/// @n @b		Project EMT-event
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		05/06/2015 21:07
/// @version	102
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///



// Core library for code-sense - IDE-based
#if defined(EMBEDXCODE)
    #if defined(ENERGIA) && defined(__MSP432P401R__) // LaunchPad MSP432 on Energia MT only
        #include "Energia.h"
    #else
        #error LaunchPad MSP432 on Energia MT only
    #endif
#endif // end IDE

// Include application, user and local libraries
#include "rtosGlobals.h"

// Prototypes


// Define variables and constants


// Setup
void Semaphore3_setup()
{
    //#if defined(optionSemaphore)
    //    mySemaphore.begin(1);
    //#endif

    Serial.begin(115200);
    delay(30);
}

// Loop
void Semaphore3_loop()
{
#if defined(optionSemaphore)
    mySemaphore.waitFor();
#endif

    Serial.print(millis(), DEC);
    Serial.print("\t: mySemaphore3      3 (");
#if defined(optionSemaphore)
    Serial.print(mySemaphore.available(), DEC);
#else
    Serial.print("-");
#endif
    Serial.println(")");

#if defined(optionSemaphore)
    mySemaphore.post();
#endif

    delay(120);
}

