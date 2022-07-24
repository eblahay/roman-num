#include <ios>
#include <roman-num/roman-num.hxx>

#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

std::string rmn::toRomanNum(int x, const VariationFlags &variations){
    std::string result;

    // body
    if(x > 0 && x <= 3999){
        // parse thousands
        for(int i=0; i<x/1000; i++){
            result += "M";
        }

        // parse hundreds
        x %= 1000;
        if(x >= 900){
            result += "CM";
        }
        else if(x < 500 && x >= 400){
            result += "CD";
        }
        else{
            if(x >= 500){
                result += "D";
                x -= 500;
            }

            for(int i=0; i<x/100; i++){
                result += 'C';
            }
        }

        // parse tens
        x %= 100;
        if(x >= 90){
            result += "XC";
        }
        else if(x < 50 && x >= 40){
            result += "XL";
        }
        else{
            if(x >= 50){
                result += "L";
                x -= 50;
            }

            for(int i=0; i<x/10; i++){
                result += 'X';
            }
        }

        // parse ones
        x %= 10;
        if(x >= 9){
            result += "IX";
        }
        else if(x < 5 && x >= 4){
            if(variations.fourbars) result += "IIII";
            else result += "IV";
        }
        else{
            if(x >= 5){
                result += "V";
                x -= 5;
            }

            for(int i=0; i<x; i++){
                result += 'I';
            }
        }
    }
    else if(variations.nulla && x == 0) result = "N";
    else{
        throw std::out_of_range("Cannot properly represent given input! (" + std::to_string(x) + ")");
    }

    return result;
}

std::string rmn::toRomanNum(int x, const std::vector<Variations> &variations){
    return toRomanNum(x, parseVariation(variations));
}

std::vector<std::string> rmn::toRomanNum(std::vector<int> v, const std::vector<Variations> &variations){
    std::vector<std::string> result;

    auto variation_flags = rmn::parseVariation(variations);

    for(auto x=v.begin(); x != v.end(); x++){
        result.push_back(toRomanNum(*x, variation_flags));
    }

    return result;
}

rmn::VariationFlags rmn::parseVariation(const std::vector<Variations> &variations){
    // process variations
    VariationFlags variation_flags;
    for(auto it=variations.begin(); it != variations.end(); it++){
        switch (*it) {
            case nulla:
                variation_flags.nulla = true;
                break;
            case fourbars:
                variation_flags.fourbars = true;
                break;
        }
    }

    return variation_flags;
}

int rmn::strToInt(const std::string &a){
    int result = 0;

    static char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};

    int x=0;
    for(auto it=a.rbegin(); it != a.rend(); it++){
        if(*it != digits[0]){
            int d;
            for(d=1; d < 10; d++){
                if(*it == digits[d]){
                    result += d * pow10(x);
                    break;
                }
            }
            if(d == 10){// character is NOT 0-9
                switch (*it) {
                    case '-':
                        result *= -1;
                        break;
                    default:
                        throw std::out_of_range("INVALID INPUT");
                        break;
                }
            }
        }
        
        x++;
    }

    return result;
}

int rmn::pow10(const int &x){
    static int pow10tbl[10] = {
        1, 10, 100, 1000, 10000, 100000,
        1000000, 10000000, 100000000, 1000000000
    };

    return pow10tbl[x];
}