#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

#include <roman-num.hxx>

int main(int argc, char* argv[]){
    int exit_code;
    try{
        if(argc < 2) throw std::runtime_error("Missing Required Argument!");
        for(int i=1; i<argc; i++){
            std::cout << toRomanNum(std::atoi(argv[i])) << '\n';
        }

        exit_code = 0;
    }
    catch(const std::exception &e){
        std::cerr << "\e[31;1mFatal Error: \e[0;1m" << e.what() << '\n';

        exit_code = 1;
    }

    return exit_code;
}