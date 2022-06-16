#include<iostream>
#include<string>
#include <iomanip>

#include "levenshtein.h"

int main() {
    std::string str1="averylongname";
    std::string str2="arussianname";
    int li = levenshtein_index(str1, str2);
    double ln = levenshtein_normalized(li, str1, str2);
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(4);
    std::cout<<"The Levenshtein index of "<<str1<<" and "<<str2<< " is "<<ln<<std::endl;    

    return 0;
}