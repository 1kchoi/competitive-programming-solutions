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
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, K;
int first, second, current, input, input1, input2;

int truncUp(int x, int k) {
    if (x % k > 0) {
        return x/k + 1;
    }
    return x/k;
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        first = 0;
        second = 0;
        current = 0;
        input = 0;
        input1 = 0;
        input2 = 0;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> input;
            input2 = input1;
            input1 = input;
            if (i > 0) {
                current = input1 - input2;
                if (current >= first) {
                    second = first;
                    first = current;
                }
                else if (current > second) {
                    second = current;
                }
            }
        }
        cout << "Case #" << tc << ": " << max(truncUp(first,2), second) << endl;
    }

    return 0;
}
