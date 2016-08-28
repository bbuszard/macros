////////////////////////////////////////////////////////////////////////////////
//
// This is a quickie program to generate macros in grams for a given weight.
// Currently it figures out the macros for the recomp protocal by Jordan
// Feigenbaum at http://www.barbellmedicine.com/potpourri/584/
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

double checkargs(int, char**);

int main(int argc, char **argv)
{
    double weight;
    try {
        weight = checkargs(argc, argv);
    }
    catch (std::out_of_range) {
        std::cout << "command line arguments out of range: exiting\n" 
                  << std::endl;
        return -1;
    }

    std::cout << std::fixed << std::setprecision(0);
    std::cout << "\nMacros for weight " << weight << " lbs:" << std::endl;
    std::cout << "\tKcal: " << weight * 12.75 << std::endl;
    std::cout << "\tprotein: " << weight * 1.15 << "g" << std::endl;
    std::cout << "\tcarbs: " << weight * 1.25 << "g" << std::endl;
    std::cout << "\tfat: " << weight * 0.35 << "g\n" << std::endl;
    return 0;
}

//
// Some very basic argument sanity checks.
//

double checkargs(int _argc, char **_argv)
{
    if (_argc != 2) {
        std::cout << "\nError: wrong number of command line arguments." 
                  << std::endl;
        std::cout << "Usage: macros x" << "\n\twhere x is the current"
                  << " body weight in pounds.\n" << std::endl;
        throw (std::out_of_range("wrong number of command line args"));
    }
    double onerm = std::atof(_argv[1]);
    return onerm;
}
