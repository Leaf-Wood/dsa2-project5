#include <iostream>
#include <vector>

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
	std::string X = "ACATA";
	std::string Y = "CAT";
	
	std::cout << LCS(X, Y) << "\n";
}