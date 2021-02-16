// Mock CCC '20 Contest 2 S5 - Sticks
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
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll NA, NB, A, B, M, ans;
vi X;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> A >> NA >> B >> NB >> M;
    for (int i = 0; i < M; i++) {
        ll x; cin >> x; X.PB(x);
    }

    bool flag = true;
    bool firstRound = true;
    while (true) { // add condition where you can't use all NA sticks
        cout << "yo" << endl;
        flag = false;
        for (int i = 0; i < M; i++) {
            if (!firstRound && X[i] >= A) {
                X[i] -= A;
                cout << "X[" << i << "] = " << X[i] << endl;
                ans++;
                flag = true;
            }
            while(X[i] >= A && (X[i] - A) / B == X[i] / B) {
                X[i] -= A;
                cout << "X[" << i << "] = " << X[i] << endl;
                ans++;
                flag = true;
            }
        }
        if (!(ans < NA && (flag || firstRound))) break;
        firstRound = false;
    }

    if (!flag) {
        cout << ans << endl;
        cout << "howdy" << endl;
        return 0;
    }

    ll sum = 0;
    for (int i = 0; i < M; i++) {
        sum += (X[i] / B);
    }

    cout << NA + min(NB, sum) << endl;

    return 0;
}
