#include <stdlib.h>
#include <unistd.h>		// for close()

#include "unity.h"

#include "resource_detector.h"
#include "encode.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

extern void setUp(void)
{
    // This is run before EACH test
}

extern void tearDown(void)
{
    // This is run after EACH test
}

void test_encode(void)
{
	uint8_t value = 255;
    uint8_t* low = 0;
    uint8_t* high = 0;
	encode_get_nibbles(value, low, high);
    TEST_ASSERT_EQUAL(15, *high);
    TEST_ASSERT_EQUAL(15, *low);
    encode_get_nibbles(0, 0, 0);
    TEST_ASSERT_EQUAL(0, *high);
    TEST_ASSERT_EQUAL(0, *low);

    *high = 1;
    *low = 0;
    encode_value_high(value, high);
    encode_value_low(value, low);
    TEST_ASSERT_EQUAL(17, high);
    TEST_ASSERT_EQUAL(0 , low);

    *high = 0b1010;
    TEST_ASSERT_NOT_EQUAL(0, high);  
}

int main (int argc, char * argv[])
{
	if (argc > 1)
	{
		fprintf (stderr, "ERROR: '%s': invalid arguments\n", argv[0]);
	}
    UnityBegin();

    MY_RUN_TEST(test_encode);

    return UnityEnd();
}
