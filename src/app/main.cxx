#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <cerrno>
#include <exception>
#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

#include <roman-num/roman-num.hxx>
#include <vector>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[]){
    try{
        std::vector<rmn::Variations> variations;

        // Options that will be allowed on the command line
        po::options_description generic("Generic Options");
        generic.add_options()
            ("help", "prints this message")
            ("version", "prints program version number and quits")
            ("nulla,n", "variation")
            ("fourbars,f", "variation")
        ;

        // Hidden options, will be allowed both on command line
        // but will not be shown to the user.
        po::options_description hidden("Hidden Options");
        hidden.add_options()
            ("input", po::value<std::vector<int>>(), "decimal input")
        ;

        // Positional Options
        po::positional_options_description p;
        p.add("input", -1);

        // further grouping options
        po::options_description cmdln_options;
        cmdln_options.add(generic).add(hidden);

        po::options_description visible("Options");
        visible.add(generic);

        // parse options
        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(cmdln_options).positional(p).run(), vm);
        po::notify(vm);    

        if (vm.count("help")) {
            std::cout << "Usage: " << program_invocation_short_name << " [options]\n" << visible << "\n";
            return 0;
        }
        else if(vm.count("version")){
            std::cout << "roman-num(application) v0.2.0\n";
            return 0;
        }
        else{
            if(vm.count("input")){
                // set variations
                if(vm.count("nulla")) variations.push_back(rmn::nulla);
                if(vm.count("fourbars")) variations.push_back(rmn::fourbars);

                // process decimal input
                auto roman_nums = rmn::toRomanNum(vm["input"].as<std::vector<int>>(), variations);
                for(auto it=roman_nums.begin(); it != roman_nums.end(); it++){
                    std::cout << *it << '\n';
                }
            }
        }

        return 0;
    }
    catch(const std::exception &e){
        std::cerr << "\e[31;1mFatal Error: \e[0;1m" << e.what() << '\n';

        return 1;
    }
}