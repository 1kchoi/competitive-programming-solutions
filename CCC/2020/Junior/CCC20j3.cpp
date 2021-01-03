// CCC '20 J3 - Art
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, minX, maxX, minY, maxY;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    minX = minY = INT_MAX;
    maxX = maxY = INT_MIN;
    while (N--) {
        string s; cin >> s;
        int commaindex = s.find(",");
        int a = stoi(s.substr(0, commaindex));
        int b = stoi(s.substr(commaindex + 1)); //cin >> a >> b;
        minX = min(minX, a);
        maxX = max(maxX, a);
        minY = min(minY, b);
        maxY = max(maxY, b);
    }
    cout << minX - 1 << "," << minY - 1 << endl;
    cout << maxX + 1 << "," << maxY + 1 << endl;

    return 0;
}
