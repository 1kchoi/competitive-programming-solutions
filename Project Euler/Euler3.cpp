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
#define BOI 600851475143
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

bool primes[800000];

int main() {
    cout << "hi" << endl;
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = 0;

    for (int i = 2; i < 900; i++) {
        if (primes[i]) {
            for (int j = 2*i; j < 800000; j += i) {
                primes[j] = 0;
            }
        }
    }

    for (int i = 799999; i >= 0; i--) {
        if (primes[i]) {
            if (BOI % i == 0) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
