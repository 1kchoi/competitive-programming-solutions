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
#define cout fout
#define cin fin
#define ll long long
#define PB push_back
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("swap.in");
ofstream fout("swap.out");
//ifstream fin("input.txt");

int N, M, K, in1, in2, mod;
vvi seq;
vii steps;
vi ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; ++i) {
        cin >> in1 >> in2;
        steps.PB(ii(in1,in2));
    }

    seq.PB(vi());
    seq.PB(vi());
    for (int i = 1; i <= N; ++i) {
        seq[0].PB(i);
        ans.PB(i);
    }

    for (int i = 0; i < M; ++i) { // for each step
        //cout << "this i: " << i << endl;
        reverse(seq[0].begin() + steps[i].first - 1, seq[0].begin() + steps[i].second);
    }

    int a = 0;
    while ((int)(pow(2,a)) < K) {
        ++a;
        //cout << "i: " << i << endl;
        seq.PB(vi());
        for (int j = 0; j < N; ++j) {
            seq[a].PB(seq[a-1][seq[a-1][j]-1]);
            //cout << seq[i][j] << " ";
        }
        //cout << endl;
    }

    /*for (int i = 0; i < seq.size(); ++i) {
        for (int j = 0; j < seq[i].size(); ++j) {
            cout << seq[i][j] << " ";
        }
        cout << "\n";
    }*/

    int T = K;
    for (int i = 0; i < seq.size(); i++) {
        if (K & (1<<i)) {
            vi anscopy(ans);
            for (int j = 0; j < N; j++) {
                ans[j] = anscopy[seq[i][j]-1];
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
