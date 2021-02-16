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

ll A, NA, B, NB, M, sticks[NMAX], ans1, useda, usedb;
set<ar<ll, 3>, greater<ar<ll, 3>>> S;

ll getNextJump(int i) {
    return (sticks[i] - (sticks[i] / B * B - B)) / A;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> A >> NA >> B >> NB >> M;
    for (int i = 0; i < M; i++) {
        cin >> sticks[i];
        ans1 += sticks[i] / A;
    }
    if (ans1 < NA) {
        cout << ans1 << endl;
        return 0;
    }
    for (int i = 0; i < M && useda < NA; i++) {
        ll addedsticks = (sticks[i] - (sticks[i] / B * B)) / A;
        if (useda + addedsticks > NA) {
            ll cap = NA - useda;
            useda = NA;
            sticks[i] -= cap * A;
            cout << cap << " sticks at " << i << " (" << sticks[i] << ") [first cap]" << endl;
            break;
        }
        useda += addedsticks;
        sticks[i] -= addedsticks * A;
        cout << addedsticks << " sticks at " << i << " (" << sticks[i] << ") ";
        if (sticks[i] >= A) {
            S.insert({getNextJump(i), sticks[i], i});
            cout << "i";
        } // else, the tube can't hold any more sticks
        cout << endl;
        cout << "useda: " << useda << endl;
    }
    cout << "MOVING ON" << endl;
    while (useda < NA && sz(S)) {
        ar<ll, 3> p = *S.begin(); S.erase(S.begin());
        ll thisjump = p[0], i = p[2];
        if (useda + thisjump > NA) {
            ll cap = NA - useda;
            useda = NA;
            sticks[i] -= cap * A;
            cout << cap << " sticks at " << i << " (" << sticks[i] << ") [cap]" << endl;
            break;
        }
        useda += thisjump;
        sticks[i] -= thisjump * A;
        cout << thisjump << " sticks at " << i << " (" << sticks[i] << ") ";
        if (sticks[i] >= B) {
            S.insert({getNextJump(i), sticks[i], i});
            cout << "i";
        }
        cout << endl;
        cout << "useda: " << useda << endl;
    }
    cout << "B COUNT" << endl;
    for (int i = 0; i < M; i++) {
        usedb += sticks[i] / B;
        cout << "+ " << sticks[i] / B << " " << NA + usedb << endl;
    }
    cout << NA + min(usedb, NB) << endl;

    return 0;
}
