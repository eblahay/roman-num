#pragma once

#include <string>

namespace rmn {
    // returns a string containing a roman numeral equivalent to the value of 'x'
    std::string toRomanNum(int x);

    // converts a std::string (composed of decimal numerals) to an integer
    // also throws an exception if input cannot be reasonably interpreted as an integer
    int strToInt(const std::string &a);

    // return integer power of ten
    int pow10(const int &x);
}