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
//#define cin fin
#define ll long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int A, B, T;

int getOddSum(int x) {
    if (x == -1) return 0;
    return (x/2+1)*(x/2+1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> A >> B;
        if (A%2==0) A++;
        if (B%2==0) B--;
        if (A > B) {
            cout << "Case " << tc << ": 0\n";
            continue;
        }
        cout << "Case " << tc << ": " << getOddSum(B)-getOddSum(A-2) << "\n";
    }

    return 0;
}
