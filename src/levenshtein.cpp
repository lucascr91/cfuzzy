#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

typedef std::vector<int>::const_iterator it_vec;
typedef std::string::iterator it_str;
typedef std::vector<int>::size_type size_vec;

std::vector<std::vector<int>> zero_matrix(int& n, int& m) {
    std::vector<int> l(m,0);
    std::vector<std::vector<int>> matrix;

    for (int i=0; i!=n; i++) {
        matrix.push_back(l);
    }
    return matrix;
}

void print_matrix(const std::vector<std::vector<int>>& m) {
    std::vector<int> lines;

    for (size_vec k=0; k!=m.size(); k++) {
        lines = m[k];
        for (it_vec it=lines.begin(); it!=lines.end(); it++) {
            std::cout<<' '<<*it<<' ';
        };
        std::cout<<"\n";
    }
}

std::vector<std::vector<int>> levenshtein_matrix(std::string& token1, std::string& token2) {
    int leng1 = token1.size()+1;
    int leng2 = token2.size()+1;
    std::vector<std::vector<int>> distances = zero_matrix(leng1, leng2);

    for (int i=0; i!=leng1; i++) {
        distances[i][0] = i;
    }

    for (int i=0; i!=leng2; i++) {
        distances[0][i] = i;
    }

    int a = 0;
    int b = 0;
    int c = 0;

    for (int i=1; i!=leng1;i++) {
        for (int j=1; j!=leng2; j++) {
            if (token1[i-1]==token2[j-1]) {
                distances[i][j] = distances[i-1][j-1];
            } else {
                a = distances[i][j-1];
                b = distances[i-1][j];
                c = distances[i-1][j-1];

                if (a<=b && a<=c) {
                    distances[i][j] = a+1;
                } else if (b<=a && b<=c) {
                    distances[i][j] = b+1;
                } else {
                    distances[i][j] = c+1;
                }
            }
        }
    }

    return distances;
}

int levenshtein_index(std::string& str1, std::string& str2) {
    std::vector<std::vector<int>> matrix = levenshtein_matrix(str1, str2);
    int n = str1.size();
    int m = str2.size();
    int li = matrix[n][m];

    return li;
}

double levenshtein_normalized(int levenshtein, std::string str1, std::string str2) {
    double leng1 = str1.size();
    double leng2 = str2.size();

    double max_len = std::max(leng1, leng2);
    double ln = levenshtein/max_len; 

    return ln;
}


