#include <iostream>

void LCS(const std::string &X, const std::string& Y) {
	int m = X.size();
	int n = Y.size();
	
	int c[m+1][n+1];
	char b[m+1][n+1];
	
	for(int i=0; i<m+1; ++i) {
		for(int j=0; j<n+1; ++j) {
			if(i==0 || j==0) {
				c[i][j] = 0;
			}
			b[i][j] = '*';
		}
	}
	
	for(int i=1; i<m+1; ++i) {
		for(int j=1; j<n+1; ++j) {
			if(X[i-1] == Y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = '\\';
			} else {
				if(c[i-1][j] >= c[i][j-1]) {
					c[i][j] = c[i-1][j];
					b[i][j] = '|' ;
				} else {
					c[i][j] = c[i][j-1];
					b[i][j] = '-';
				}
			}
		}
	}
	
	// --- Print Direction Matrix (b) ---
    std::cout << "Direction Matrix (b):\n";
    std::cout << "    "; // Padding for the top-left corner
    for(int j = 0; j < n; ++j) {
        std::cout << Y[j] << " ";
    }
    
    for(int i = 0; i <= m; ++i) {
        // Print row label (handling the 0th empty row)
        if (i == 0) std::cout << "\n  "; 
        else std::cout << "\n" << X[i - 1] << " ";
        
        for(int j = 0; j <= n; ++j) {
            std::cout << b[i][j] << " ";
        }
    }
    std::cout << "\n\n";
    
    // --- Print Value Matrix (c) ---
    std::cout << "Value Matrix (c):\n";
    std::cout << "    "; 
    for(int j = 0; j < n; ++j) {
        std::cout << Y[j] << " ";
    }
    
    for(int i = 0; i <= m; ++i) {
        if (i == 0) std::cout << "\n  "; 
        else std::cout << "\n" << X[i - 1] << " ";
        
        for(int j = 0; j <= n; ++j) {
            std::cout << c[i][j] << " ";
        }
    }
    std::cout << "\n";
}


int main() {
	std::string X = "ACADB";
	std::string Y = "CBDA";
	
	LCS(X, Y);
}