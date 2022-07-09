#pragma once

#include <string>
#include <vector>

namespace rmn {
    // Roman Numeral Variants
    enum RmnVariant {nulla, quadbar};

    // returns a string containing a Roman numeral equivalent to the value of 'x'
    std::string toRomanNum(int x, std::vector<RmnVariant> variants={});

    // converts a std::string (composed of decimal numerals) to an integer
    // also throws an exception if input cannot be reasonably interpreted as an integer
    int strToInt(const std::string &a);

    // return integer power of ten
    int pow10(const int &x);
}