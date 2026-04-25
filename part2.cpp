#include <iostream>
#include <vector>
#include <fstream>

int LCSLength(const std::string& X, const std::string& Y) {
    int m = X.size();
    int n = Y.size();
    
    //the matrix only uses 2 rows to save memory
    std::vector<std::vector<int>> c(2, std::vector<int>(n + 1, 0));

    for(int i=1; i<=m; ++i) {
        int curr = i % 2; //flips between row 0 and 1
        int prev = (i-1) % 2;

        for(int j=1; j<=n; ++j) {
            if(X[i-1] == Y[j-1]) {
                c[curr][j] = c[prev][j-1] + 1;
            } else {
                if(c[prev][j] >= c[curr][j-1]) {
					c[curr][j] = c[prev][j];
				} else {
					c[curr][j] = c[curr][j-1];
				}
            }
        }
    }
    //final lcs length is the last number in the array
    return c[m % 2][n];
}

char similarity(int lenX, int lenY, int lenLcs) {
    double min = (lenX < lenY) ? lenX : lenY;
    double max = (lenX > lenY) ? lenX : lenY;
    
    if(min >= 0.9*max && lenLcs >= 0.9*min) {return 'H';}
    if(min >= 0.8*max && lenLcs >= 0.8*min) {return 'M';}
    if(min >= 0.6*max && lenLcs >= 0.5*min) {return 'L';}
    return 'D';
}

int main() {
    //open file
	std::ifstream file("multiStrings.txt");
    if (!file.is_open()) {return -1;}

    //get number of strings
    int numStrings;
    file >> numStrings;
    file.ignore(); //goes to new line

    //read strings to a vector
    std::vector<std::string> strings;
    std::string str;
    for(int i=0; i<numStrings; ++i) {
        file >> str;
        strings.push_back(str);
    }
    file.close();

    //create output matrix
    std::vector<std::vector<char>> results(numStrings, std::vector<char>(numStrings, '-'));

    //compare each pair of strings
    for(int i=0; i<numStrings; ++i) {
        for(int j=i+1; j<numStrings; ++j) {
            std::string str1 = strings[i];
            std::string str2 = strings[j];

            int lcsLen = LCSLength(str1, str2);
            results[i][j] = similarity(str1.size(), str2.size(), lcsLen);
        }
    }

    //print output matrix
    std::cout << "  ";
    for (int i = 1; i <= numStrings; ++i) {
        std::cout << " 0" << i;
    }
    std::cout << "\n";
    
    for (int i = 0; i < numStrings; ++i) {
        std::cout << "0" << (i + 1) << " ";
        for (int j = 0; j < numStrings; ++j) {
            std::cout << " " << results[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}