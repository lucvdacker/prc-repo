#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "io.h"
#include "parity.h"

void encode_get_nibbles(uint8_t value, uint8_t* low, uint8_t* high)
{
    low = value & LOWMASK;
    high = value>>4;
}

void encode_value(uint8_t value, uint8_t* high, uint8_t* low)
{
    int p0 = calculateParity(*high & P0MASK) % 2;
    if(p0 = 1)
    {
        high = *high | 0b10000;
    }
    int p1 = calculateParity(*high & P1MASK) % 2;
    if(p1 = 1)
    {
        high = *high | 0b100000;
    }
    int p2 = calculateParity(*high & P2MASK) % 2;
    if(p2 = 1)
    {
        high = *high | 0b1000000;
    }
}



