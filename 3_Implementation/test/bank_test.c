#include"bank_test.h"
#include"unity.h"
#include<stdio.h>
#include"interest.h"


void setUp(){}
void tearDown(){}

void test_int(void)
{
    TEST_ASSERT_EQUAL(10, interest(1,100,10));
    TEST_ASSERT_EQUAL(20, interest(1,200,10));
    TEST_ASSERT_EQUAL(30, interest(1,300,10));
    TEST_ASSERT_EQUAL(40, interest(1,400,10));
    TEST_ASSERT_EQUAL(50, interest(1,500,10));

}

int test_main()
{
    UNITY_BEGIN();
    RUN_TEST(test_int);

    return UNITY_END();
}