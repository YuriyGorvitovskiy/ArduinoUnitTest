/**
 ** This is Public Domain Software.
 **
 ** The author disclaims copyright to this source code.
 ** In place of a legal notice, here is a blessing:
 **
 **    May you do good and not evil.
 **    May you find forgiveness for yourself and forgive others.
 **    May you share freely, never taking more than you give.
 **/

#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

class UnitTest {

private:

    static const char* suite_name;
    static int         test_counter;
    static int         assert_counter;
    static int         failure_counter;

public:

    static void suite(const char* name);
    static void start();

    static void nextAssert();
    static void report_failure();

    static boolean report();

    static boolean bits_in_mask(byte bits, byte mask);

    static boolean unique_bits(byte* values, int count);
    static boolean unique_bits(uint16_t* values, int count);
    static boolean unique_bits(uint32_t* values, int count);

    static boolean unique_values(byte* values, int count);
    static boolean unique_values(word* values, int count);
    static boolean unique_values(uint16_t* values, int count);
    static boolean unique_values(uint32_t* values, int count);

    static boolean ordered_values(byte* values, int count);
    static boolean ordered_values(word* values, int count);
    static boolean ordered_values(uint16_t* values, int count);
    static boolean ordered_values(uint32_t* values, int count);

    static boolean same_values(byte* values, int count);
    static boolean same_values(word* values, int count);
    static boolean same_values(uint16_t* values, int count);

    static boolean same_values(byte* expect, byte* actual, int count);

    static uint16_t combine(byte a, byte b);
    static uint32_t combine(byte a, byte b, byte c);
    static uint32_t combine(byte a, byte b, byte c, byte d);
};

#define ASSERT(condition)  {UnitTest::nextAssert(); if(!(condition)) {UnitTest::report_failure(); return;}}

inline void UnitTest::suite(const char* name) {
    suite_name = name;
    test_counter = 0;
    assert_counter = 0;
    failure_counter = 0;
}

inline void UnitTest::start() {
    ++test_counter;
    assert_counter = 0;
}

inline void UnitTest::nextAssert() {
    ++assert_counter;
}

#endif //__UNIT_TEST_H__
