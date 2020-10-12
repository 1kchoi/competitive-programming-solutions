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
#define NMAX (int)(1e5 +5)
#define ll long long
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("socdist.in");
ofstream fout("socdist.out");
//ifstream fin("input.txt");

int N, M, D;
ll a,b;
vii grass;

bool solve(int d) {
    int cows = 0;
    int patch = 0;
    ll pos = grass[0].first;
    ll end = grass[grass.size()-1].second;
    //cout << "start: " << pos << " " << end << endl;
    while (pos <= end) {
        cows++;
        //cout << pos << endl;
        pos += d;
        if (pos > end) {
            break;
        }
        while (grass[patch].second < pos) {
            patch++;
            if (grass[patch].first > pos) {
                pos = grass[patch].first;
                break;
            }
        }
    }
    //cout << "\n";
    return cows >= N;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    D = 1;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        grass.push_back(ii(a,b));
    }
    sort(grass.begin(), grass.end());
    for (int i = 0; i < grass.size(); i++) {
        //cout << grass[i].first << " " << grass[i].second << endl;
    }

    int lo = 1, hi = (grass[grass.size()-1].second - grass[0].first)/(N-1)+1;
    int mid;
    while (hi - lo > 0) {
        mid = (hi+lo)/2;
        //cout << lo << " " << mid << " " << hi << endl;
        if (solve(mid)) {
            //cout << "works" << endl;
            lo = mid;
            D = mid;
            if ((hi+lo)/2 == mid) break;
        }
        else {
            hi = mid;
        }
    }
    cout << D << endl;


    return 0;
}
