#include <stdlib.h>

#include "unity.h"
#include "channel.h"
#include "parity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

extern void setUp(void)
{
  	channel_init();
}

extern void tearDown(void)
{
    // This is run after EACH test
}

static void test_channel(void)
{
  	uint8_t value = 0b1010110;
	TEST_ASSERT_NOT_EQUAL(0b1010110, channel_change_one_random_bit(value)); 
	channel_change_one_random_bit(value) | 0b01111111;
	TEST_ASSERT_TRUE(value < 0b11111111);
}

int main (int argc, char * argv[])
{
	if (argc > 1)
	{
		fprintf (stderr, "ERROR: '%s': invalid arguments\n", argv[0]);
	}
    UnityBegin();

    MY_RUN_TEST(test_channel);

    return UnityEnd();
}
