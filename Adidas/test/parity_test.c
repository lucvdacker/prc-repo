#include <stdlib.h>

#include "resource_detector.h"
#include "parity.h"
#include "unity.h"

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

void test_parity(void)
{
    __uint8_t toEncode = 0b1111;
    TEST_ASSERT_EQUAL(4, calculateParity(toEncode));
    TEST_ASSERT_TRUE(calculateParity(toEncode) < 5);
    TEST_ASSERT_FALSE(calculateParity(toEncode) < 0);
}


int main (int argc, char * argv[])
{
	if (argc > 1)
	{
		fprintf (stderr, "ERROR: '%s': invalid arguments\n", argv[0]);
	}
    UnityBegin();

    MY_RUN_TEST(test_parity);
	
    return UnityEnd();
}
