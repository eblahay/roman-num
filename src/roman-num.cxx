#include <roman-num.hxx>

std::string toRomanNum(int x){
    std::string result;

    if(x > 0){
        // parse thousands
        for(int i=0; i<x/1000; i++){
            result += "M";
        }

        // parse hundreds
        x %= 1000;
        if(x >= 900){
            result += "CM";
        }
        else if(x >= 400 && x < 500){
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
        else if(x >= 40 && x < 50){
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
        else if(x >= 4 && x < 5){
            result += "IV";
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

    return result;
}