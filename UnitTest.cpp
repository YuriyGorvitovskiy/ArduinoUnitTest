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
 
#include <Arduino.h>
#include "UnitTest.h"

const char* UnitTest::suite_name;
int         UnitTest::test_counter = 0;
int         UnitTest::assert_counter = 0;
int         UnitTest::failure_counter = 0;


void UnitTest::report_failure() {
    ++failure_counter;
    Serial.print("Test Failed: ");
    Serial.print(suite_name);
    Serial.print(":");
    Serial.print(test_counter);
    Serial.print(":");
    Serial.println(assert_counter);
}

boolean UnitTest::report() {
    Serial.print("Test ");
    Serial.print(suite_name);
    Serial.print(" completed. Total: ");
    Serial.print(test_counter);
    Serial.print(". Failed: ");
    Serial.print(failure_counter);
    Serial.println(".");
    return failure_counter == 0;
}

boolean UnitTest::bits_in_mask(byte bits, byte mask) {
    return ((bits & mask) == bits);
}

boolean UnitTest::unique_bits(byte* values, int count) {
    for (int i = 0; i < count; ++i) {
        if (values[i] == 0)
            return false;

        for (int j = i+1; j < count; ++j)
            if ((values[i] & values[j]) != 0)
                return false;
    }
    return true;
}

boolean UnitTest::unique_values(byte* values, int count) {
    for (int i = 0; i < count; ++i)
        for (int j = i+1; j < count; ++j)
            if (values[i] == values[j])
                return false;

    return true;
}

boolean UnitTest::unique_values(word* values, int count) {
    for (int i = 0; i < count; ++i)
        for (int j = i+1; j < count; ++j)
            if (values[i] == values[j])
                return false;

    return true;
}

boolean UnitTest::unique_values(uint16_t* values, int count) {
    for (int i = 0; i < count; ++i)
        for (int j = i+1; j < count; ++j)
            if (values[i] == values[j])
                return false;

    return true;
}

boolean UnitTest::ordered_values(byte* values, int count) {
    for (int i = 1; i < count; ++i) {
        if (values[i-1] > values[i])
            return false;
    }
    return true;
}

boolean UnitTest::ordered_values(word* values, int count) {
    for (int i = 1; i < count; ++i) {
        if (values[i-1] > values[i])
            return false;
    }
    return true;
}

boolean UnitTest::ordered_values(uint16_t* values, int count) {
    for (int i = 1; i < count; ++i) {
        if (values[i-1] > values[i])
            return false;
    }
    return true;
}

boolean UnitTest::same_values(byte* values, int count) {
    for (int i = 1; i < count; ++i) {
        if (values[i-1] != values[i])
            return false;
    }
    return true;
}

boolean UnitTest::same_values(word* values, int count) {
    for (int i = 1; i < count; ++i) {
        if (values[i-1] != values[i])
            return false;
    }
    return true;
}

boolean UnitTest::same_values(uint16_t* values, int count) {
    for (int i = 1; i < count; ++i) {
        if (values[i-1] != values[i])
            return false;
    }
    return true;
}

uint16_t UnitTest::combine(byte a, byte b) {
    return a | (((uint16_t)b) << 8);
}

uint32_t UnitTest::combine(byte a, byte b, byte c) {
    return a | (((uint16_t)b) << 8) | (((uint16_t)c) << 16);
}

uint32_t UnitTest::combine(byte a, byte b, byte c, byte d) {
    return a | (((uint16_t)b) << 8) | (((uint16_t)c) << 16) | (((uint16_t)d) << 24);
}
