#include "deposit.h"
#include "ctest.h"

CTEST(arithmetic_suite, penalty_test)
{
    //GIVEN
    const int dur = 20;
    const int amount = 1000;
    //WHEN
    const int result = perform(dur, amount);
    //THEN
    const int expected = 900;
    ASSERT_EQUAL(expected, result);
}
