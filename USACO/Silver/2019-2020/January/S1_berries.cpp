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
#define NMAX 1005
#define endl "\n"
#define ll long long
#define PB push_back
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.in");
ofstream fout("berries.out");

int N, K, input, per;
vi berries;
vi baskets;

int check(int x) {
    int out = 0;
    for (int i = 0; i < berries.size(); i++) {
        //cout << "i: " << i << endl;
        if (berries[i] < x) break;
        out += (berries[i] / x);
    }
    return out;
}

int solve(int p) {
    int sum = 0;
    int i = 0;
    for (int i = 0; i < N; i++) {
/**/    cout << "berries[i]: " << berries[i] << endl;
        int q = berries[i]/p;
        if (!q) break;
/**/    cout << "q: " << berries[i]/p << endl;
        for (int j = 0; j < q; j++) {
            baskets.PB(berries[i]/q);
        }
        for (int j = 0; j < berries[i]%q; j++) {
            baskets[baskets.size()-1-j]++;
        }
    }
    sort(baskets.begin(), baskets.end(), greater<int>());

    //*
    for (int i = 0; i < baskets.size(); i++) {
        cout << baskets[i] << " ";
    }
    cout << endl;
    //*/

    for (int a = K/2; a < K; a++) {
        sum += baskets[a];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    per = 0;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> input;
        berries.PB(input);
    }

    sort(berries.begin(), berries.end(), greater<int>());

    //*
    for (int i = 0; i < berries.size(); i++) {
        cout << berries[i] << " ";
    }
    cout << endl;
    //*/

    int lo = 1, hi = berries[0];
    int mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int q = check(mid);
        //cout << mid << " " << q << endl;
        if (q < K) { // q<K ==> mid is too big
            if (mid == hi) break;
            hi = mid;
        }
        else {
            if (mid == lo) break;
            lo = mid;
            per = mid;
        }
    }

    cout << "per:" << per << endl;

    cout << solve(per) << endl;

    return 0;
}
