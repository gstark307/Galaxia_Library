///
/// @mainpage	Galaxia SWI Library
///
/// @details	Galaxia SWI example for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		20/06/2015 17:06
/// @version	102
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		Galaxia_SWI.ino
/// @brief		Main sketch
///
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		20/06/2015 17:06
/// @version	102
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense - IDE-based
#if defined(ENERGIA) // LaunchPad specific
    #include "Energia.h"
#else // error
    #   error Platform not defined
#endif // end IDE

// Include application, user and local libraries
#include "rtosGlobals.h"
//#include "SWI.h"

// Prototypes


// Define variables and constants
//bool flag = false;

// Setup
void setup()
{
    delay(30);
#if (SOLUTION == 1)
    pinMode(PUSH1, INPUT_PULLUP);
#endif
    /*
        pinMode(PUSH2, INPUT_PULLUP);
        pinMode(RED_LED, OUTPUT);
    */
}

// Loop
void loop()
{
    mySemaphore.waitFor();

    Serial.print(millis(), DEC);
    Serial.print("\t1\t");
    Serial.println(chrono, DEC);

    mySemaphore.post();

#if (SOLUTION == 1)
    // Solution 1: polling
    if (!digitalRead(PUSH1))
    {
        while (!digitalRead(PUSH1));
        mySWI.post();
    }
#endif

    /*
        if (!digitalRead(PUSH2))
        {
        while (!digitalRead(PUSH2));
        flag = !flag;
        if (flag) disableSWI();
        else restoreSWI();
        Serial.println(flag, DEC);
        digitalWrite(RED_LED, flag);
        }
    */

    //    delay(10);
}


