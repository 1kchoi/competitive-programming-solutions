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

int M, S, rem;
vi digits;
vi digits2;
bool flag;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    flag = 0;

    cin >> M >> S;

    if (S == 0) {
        if (M == 1) {
            cout << "0 0\n";
        }
        else {
            cout << "-1 -1\n";
        }
    }
    else if (M * 9 < S) {
        cout << "-1 -1\n";
    }
    else {
        rem = S;
        while (rem >= 9) {
            rem -= 9;
            digits.push_back(9);
            digits2.push_back(9);
        }
        digits.push_back(rem);
        digits2.push_back(rem);
        while (digits.size() < M) {
            digits.push_back(0);
            digits2.push_back(0);
        }

        /*for (int i = 0; i < digits2.size(); i++) {
            cout << digits2[i] << " ";
        }
        cout << endl;*/

        sort (digits2.begin(), digits2.begin() + M);

        /*for (int i = 0; i < digits2.size(); i++) {
            cout << digits2[i] << " ";
        }
        cout << endl;*/

        for (int i = 0; i < M; i++) {
            if (!i && digits2[0] == 0) {
                cout << 1;
                flag = 1;
            }
            else {
                if (digits2[i] != 0 && flag) {
                    flag = 0;
                    cout << digits2[i]-1;
                }
                else {
                    cout << digits2[i];
                }
            }
        }
        cout << " ";
        for (int i = 0; i < M; i++) {
            cout << digits[i];
        }
        cout << endl;
    }

    return 0;
}
