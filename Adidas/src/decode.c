#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "decode.h"
#include "io.h"
#include "parity.h"
#include "encode.h"

uint8_t decode_combine_nibbles(uint8_t high, uint8_t low)
{
    uint8_t highByte;
    uint8_t lowByte;
    decode_byte(high, highByte);
    decode_byte(low, lowByte);
    uint8_t combinedNibbles = (highByte<<4) | lowByte;
    return combinedNibbles;
}

void decode_byte(uint8_t in, uint8_t* nibble)
{
    int p0 = calculateParity(in & P0MASK);
    int p1 = calculateParity(in & P1MASK);
    int p2 = calculateParity(in & P1MASK);
    
    uint8_t p0check = (p0check & P0CHECKMASK)>>4;
    uint8_t p1check = (p1check & P1CHECKMASK)>>4;
    uint8_t p2check = (p2check & P2CHECKMASK)>>4;

    bool p0ToF = true;
    bool p1ToF = true;
    bool p2ToF = true;

    if(p0 != p0check)
    {
        p0ToF = false;
    }
    if(p1 != p2check)
    {
        p1ToF = false;
    }
    if(p2 != p2check)
    {
        p0ToF = false;
    }

    if(p0ToF == false && p1ToF== false)
    {
       nibble = in | ZEROONEFALSEMASK;
    }
    if(p0ToF == false && p2ToF == false)
    {
        nibble = in | ZEROTWOFALSEMASK;
    }
    if(p1ToF == false && p2ToF == false)
    {
        nibble = in | ONETWOFALSEMASK;
    }
    if(p0ToF == false && p1ToF == false && p2ToF == false)
    {
        nibble = in | ALLFALSEMASK;
    }
}
