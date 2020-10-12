// Now I am become Death, the destroyer of worlds.
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>
#include <climits>
#include <fstream>
using namespace std;
//#define cout fout
#define cin fin
#define ll long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

char letters[100] = {';','1','2','3','4','M','0',',','.','9','`','1','2','3','4','5','6','7','8',':','L','<','-','>','?','@','A','V','X','S','W','D','F','G','U','H','J','K','N','B','I','O','Q','E','A','R','Y','C','Q','Z','T','Z','P',']','[','^','_'};

string line;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    while (getline(cin, line), !cin.eof()) {
        for (int i = 0; i < line.length(); i++) {
            char c = line.at(i);
            if (c == ' ') {
                cout << " ";
            }
            else {
                cout << letters[c-'\''];
            }

        }
        cout << endl;
    }

    return 0;
}
