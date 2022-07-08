#include <roman-num.hxx>

#include <stdexcept>
#include <vector>
#include <algorithm>

std::string rmn::toRomanNum(int x, std::vector<rmn::RmnVariant> variants){
    std::string result;

    if(x == 0 && std::binary_search(variants.begin(), variants.end(), nulla)){
        result = 'N';
    } 
    else if(x > 0 && x <= 3999){
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
            if(std::binary_search(variants.begin(), variants.end(), quadbar)) result += "IIII";
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
    else{ // x is greater than greatest possible number in the numerical system or lower than the lowest
        throw std::out_of_range("Cannot properly represent given input!");
    }

    return result;
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