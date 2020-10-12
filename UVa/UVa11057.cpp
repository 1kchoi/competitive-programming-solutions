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
#define MAXN 1000005
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M;
int hi, mid, lo, target;
int ans1, ans2;
int A[MAXN];

void printAnswer(int i, int j) {
    if (i < j) {
        cout << "Peter should buy books whose prices are " << i << " and " << j << "." << endl << endl;
    }
    else {
        cout << "Peter should buy books whose prices are " << j << " and " << i << "." << endl << endl;
    }
}

int main() {

    while (scanf("%d", &N) != EOF) {
        ans1 = 0;
        ans2 = MAXN * 2;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cin >> M;
        sort(A, A+N);
        for (int i = 0; i < N; i++) {
            //cout << "i = " << i << endl;
            hi = N-1;
            lo = 0;
            target = M-A[i];
            //cout << M << " - " << A[i] << " = " << target << endl;
            while (hi > lo) {
                mid = (hi + lo)/2;
                //cout << lo << " " << mid << " " << hi << " " << target << endl;
                if (A[mid] == target || A[hi] == target || A[lo] == target) {
                    if (abs(ans1 - ans2) > abs(A[i] - target)) {
                        ans1 = A[i];
                        ans2 = target;
                    }
                    break;
                }
                else if (A[mid] > target) {
                    //cout << "over\n";
                    hi = mid;
                }
                else { // A[mid] < target
                    //cout << "under\n";
                    if (lo == mid) break;
                    lo = mid;
                }
            }
        }
        printAnswer(ans1, ans2);
    }

    return 0;
}
