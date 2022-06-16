#ifndef GUARD_grade_h
#define GUARD_grade_h

#include<string>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> zero_matrix(int& n, int& m);
void print_matrix(const std::vector<std::vector<int>>& m);
std::vector<std::vector<int>> levenshtein_matrix;
int levenshtein_index(std::string& token1, std::string& token2);
double levenshtein_normalized(int levenshtein, std::string str1, std::string str2);
#endif