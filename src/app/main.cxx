#include <exception>
#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

#include <roman-num/roman-num.hxx>
#include <vector>

int main(int argc, char* argv[]){
    int exit_code;
    try{
        std::vector<rmn::RmnVariant> variants;

        if(argc < 2) throw std::runtime_error("Missing Required Argument!");
        for(int i=1; i<argc; i++){
            if(argv[i][0] == '-'){
                if(std::strcmp(argv[i], "-n")==0) variants.push_back(rmn::nulla);
                else if(std::strcmp(argv[i], "-Q")==0) variants.push_back(rmn::quadbar);
            }
            else{
                std::cout << rmn::toRomanNum(rmn::strToInt(argv[i]), variants) << '\n';
            }
        }

        exit_code = 0;
    }
    catch(const std::exception &e){
        std::cerr << "\e[31;1mFatal Error: \e[0;1m" << e.what() << '\n';

        exit_code = 1;
    }

    return exit_code;
}