#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define XMAX 100002
#define ZMAX 102
using namespace std;

int N;
string X, Z;
int xlength, zlength;
int dp[XMAX][ZMAX];
bool done[XMAX][ZMAX];

int solve(int i, int j) {
    //cout << X.substr(i) << " " << Z.substr(j) << endl;
    if (!done[i][j]) {
        if (j == zlength) {
            dp[i][j] = 1;
        }
        else if (i == xlength) {
            dp[i][j] = 0;
        }
        else {
            string c = Z.substr(j,1);
            int sum = 0;
            for (int a = i; a < xlength; a++) {
                //cout << X.substr(a,1) << endl;
                if (X.substr(a,1).compare(c) == 0) {
                    sum += solve(a+1,j+1);
                }
            }
            dp[i][j] = sum;
        }
        done[i][j] = true;
    }
    return dp[i][j];
}

int main() {
    cin >> N;
    while (N--) {
        cin >> X;
        cin >> Z;
        xlength = X.length();
        zlength = Z.length();
        memset(done, false, XMAX*ZMAX);
        cout << solve(0,0) << endl;
    }
}
