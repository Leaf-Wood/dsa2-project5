#include <iostream>
#include <vector>
#include <fstream>

std::string LCS(const std::string &X, const std::string& Y) {
	int m = X.size();
	int n = Y.size();

	//build c array
	std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1, 0));
	for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            if(X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
				if(c[i-1][j] >= c[i][j-1]) {
					c[i][j] = c[i-1][j];
				} else {
					c[i][j] = c[i][j-1];
				}
			}
		}
	}
	
	//read c array backwards to find lcs
	std::string lcs = "";
	int i = m; int j = n;
	while(i>0 && j>0) {
		if(X[i-1] == Y[j-1]) {
			//match, diagonal
			lcs = X[i-1] + lcs; //add to front
			i--; j--;
		} else if(c[i-1][j] > c[i][j-1]) {
			//above > left, move up
			i--;
		} else {
			//left >= above, move left
			j--;
		}
	}

	return lcs;
}


int main() {
	std::ifstream file("twoStrings.txt");

	std::string X, Y;

	if(file.is_open()) {
		std::getline(file, X);
		std::getline(file, Y);
		file.close();
	}
	std::cout << "String 1 Length: " << X.size() << "\n";
	std::cout << "String 2 Length:  " << Y.size() << "\n";

	std::string lcs = LCS(X, Y);
	std::cout << "LCS length " << lcs.size() << "\n";
	std::cout << "LCS: " << lcs << "\n";

	return 0;
}