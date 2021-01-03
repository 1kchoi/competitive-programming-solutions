// CCC '19 J5 - Rule of Three
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

string rule[4][2], start, finish;
int N;

ii convertToBinary(string s) {
    int x;
    for (int i = 0; i < sz(s); i++) {

    }
}

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> rule[i][j];
        }
    }

    cin >> N >> start >> finish;

    return 0;
}
