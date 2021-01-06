#include <stdio.h>
#include <stdlib.h>

#include "parity.h"
#include "resource_detector.h"

int calculateParity(__uint8_t toEncode)
{
    int ones = 0;
    for(int i = 0; i < toEncode; i++)
    {
        if(toEncode >7)
        {
            ones++;
            toEncode = toEncode -8;
        }
        if(toEncode >3)
        {
            ones++;
            toEncode = toEncode -4;
        }
        if(toEncode > 1)
        {
            ones++;
            toEncode = toEncode -2;
        }
        if(toEncode > 0)
        {
            ones++;
            toEncode = toEncode -1;
        }
        return ones;
    }
}
