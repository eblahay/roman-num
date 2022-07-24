#pragma once

#include "roman-num/roman-num.hxx"
#include <string>
#include <vector>

namespace rmn {
    // roman numeral variations
    enum Variations {nulla, fourbars};

    struct VariationFlags {
        bool
            nulla = false,
            fourbars = false
        ;
    };

    // returns a string containing a Roman numeral equivalent to the value of 'x'
    std::string toRomanNum(int x, const VariationFlags &variations);
    std::string toRomanNum(int x, const std::vector<Variations> &variations={});
    // batch conversion of decimal integers to equivalent Roman numerals
    std::vector<std::string> toRomanNum(std::vector<int> v, const std::vector<Variations> &variations={});

    // parses a vector of Variation enums and spits out a flag structure
    VariationFlags parseVariation(const std::vector<Variations> &variations);

    // converts a std::string (composed of decimal numerals) to an integer
    // also throws an exception if input cannot be reasonably interpreted as an integer
    int strToInt(const std::string &a);

    // return integer power of ten
    int pow10(const int &x);
}