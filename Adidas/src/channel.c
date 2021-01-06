#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "channel.h"
#include "parity.h"
#include "resource_detector.h"

void channel_init()
{
    srand(time(NULL)); // take the current time as seed for random generator
}

uint8_t channel_change_one_random_bit(uint8_t value)
{
    int x;
    int random = rand() % 8;
    for(int i = 1; i < random; i++)
    {
        x = x*2;
    }
    value = value ^ x;
    return value;
}
