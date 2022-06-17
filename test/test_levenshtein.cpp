#include<iostream>
#include<string>
#include "../src/levenshtein.h"

bool test_levenshtein(std::string& str1, std::string& str2, int ref) {
    int li = levenshtein_index(str1, str2);

    return li==ref;
}

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

void test() {
    std::string str1 = "Mavs";
    std::string str2 = "Rockets";
    IS_TRUE(test_levenshtein(str1, str2, 6));
    str1 = "Spurs";
    str2 = "Pacers";
    IS_TRUE(test_levenshtein(str1, str2, 4));
    str1 = "SPURS";
    IS_TRUE(test_levenshtein(str1, str2, 4));
}

int main(void) {
    test();
}