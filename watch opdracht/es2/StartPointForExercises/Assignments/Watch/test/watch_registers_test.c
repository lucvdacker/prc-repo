#include <stdio.h>
#include <string.h>

#include "resource_detector.h"
#include "unity.h"
#include "watch_registers.h"
#include "watch_register.c"

// I rather dislike keeping line numbers updated, so I made my own macro to
// ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
  time_bits_low = 0;
  time_bits_high = 0;
  hours = 11;
  minutes = 55;
  seconds = 42;

  date_bits_low = 0;
  date_bits_high = 0;
  year = 108;
  month = 10;
  day_of_month = 30;
}

void tearDown(void)
{
    // This is run after EACH test
}


void test_pause(void)
{

}

void test_setting_time_hours(void)
{
    watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);
    TEST_ASSERT_EQUAL(hours << 12, combine(time_bits_low, time_bits_high));
}

void test_setting_time_minutes(void)
{
    watch_registers_set_time_minutes(&time_bits_low, &time_bits_high, minutes);
    TEST_ASSERT_EQUAL(minutes << 6, combine(time_bits_low, time_bits_high));
}

void test_setting_time_seconds(void)
{
    watch_registers_set_time_seconds(&time_bits_low, &time_bits_high, seconds);
    TEST_ASSERT_EQUAL(seconds, combine(time_bits_low, time_bits_high));
}

void test_setting_time()
{
  watch_registers_set_time_seconds(&time_bits_low, &time_bits_high, seconds);
  watch_registers_set_time_minutes(&time_bits_low, &time_bits_high, minutes);
  watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);

  uint8_t h,m,s;
  watch_registers_get_time(time_bits_low, time_bits_high, &h, &m, &s);
  TEST_ASSERT_EQUAL(hours, h);
  TEST_ASSERT_EQUAL(minutes, m);
  TEST_ASSERT_EQUAL(seconds, s);
}

void test_setting_date_years(void)
{
    watch_registers_set_date_year(&date_bits_low, &date_bits_high, year);
    TEST_ASSERT_EQUAL(year, combine(date_bits_low, date_bits_high));
}

void test_setting_date_months(void)
{
    watch_registers_set_date_month(&date_bits_low, &date_bits_high, month);
    TEST_ASSERT_EQUAL(month << 7, combine(date_bits_low, date_bits_high));
}
void test_setting_date_day_of_month(void)
{
    watch_registers_set_date_day_of_month(&date_bits_low, &date_bits_high, day_of_month);
    TEST_ASSERT_EQUAL(day_of_month << 11, combine(date_bits_low, date_bits_high));
}

void test_set_config_time_update_interval(void)
{
  uint8_t config = 0;
  time_update_interval interval = 3;
  uint8_t config2 = config;
  watch_registers_set_config_time_update_interval(&config,interval);
  TEST_ASSERT_EQUAL(6,config-config2);
  interval = 1;
  config2 = config;
  watch_registers_set_config_time_update_interval(&config,interval);
  TEST_ASSERT_EQUAL(4,config2-config);
}

void test_setting_date()
{
  watch_registers_set_date_year(&date_bits_low, &date_bits_high, year);
  watch_registers_set_date_month(&date_bits_low, &date_bits_high, month);
  watch_registers_set_date_day_of_month(&date_bits_low, &date_bits_high, day_of_month);

  uint8_t y,m,d;
  watch_registers_get_date(date_bits_low, date_bits_high, &y, &m, &d);
  TEST_ASSERT_EQUAL(year, y);
  TEST_ASSERT_EQUAL(month, m);
  TEST_ASSERT_EQUAL(day_of_month, d);
}

//TODO: create more unit-tests.

int main (int argc, char * argv[])
{
    UnityBegin();
    MY_RUN_TEST(test_set_config_time_update_interval);
    MY_RUN_TEST(test_setting_time_hours);
    MY_RUN_TEST(test_setting_time_minutes);
    MY_RUN_TEST(test_setting_time_seconds);
    MY_RUN_TEST(test_setting_time);
    MY_RUN_TEST(test_setting_date_years);
    MY_RUN_TEST(test_setting_date_months);
    MY_RUN_TEST(test_setting_date_day_of_month);
    MY_RUN_TEST(test_setting_date);

    return UnityEnd();
}