// USACO 2020 December Contest, Silver
// Problem 3. Stuck in a Rut
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, killcount[NMAX];
vector<ar<ll, 3>> cow, events;
bool alive[NMAX];

/*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        char c; ll x, y; cin >> c >> x >> y;
        bool b = (c == 'N');
        cow.PB({b, x, y});
    }

    for (int i = 0; i < sz(cow); i++) {
        for (int j = i + 1; j < sz(cow); j++) {
            if (cow[i][0] == cow[j][0]) continue;
            ll xcow, ycow;
            if (cow[j][0]) {
                xcow = i; ycow = j;
            }
            else {
                xcow = j; ycow = i;
            }

            ll xtime = cow[ycow][1] - cow[xcow][1];
            ll ytime = cow[xcow][2] - cow[ycow][2];
            if (xtime < 0 || ytime < 0) continue;
            if (xtime < ytime) { // x kills y
                events.PB({ytime, xcow, ycow});
            }
            else if (xtime > ytime) { // y kills x
                events.PB({xtime, ycow, xcow});
            }
        }
    }

    sort(all(events));

    memset(alive, 1, sizeof(alive));
    for (int i = 0; i < sz(events); i++) {
        ll win = events[i][1], lose = events[i][2];
        if (!alive[win] || !alive[lose]) continue;
        //cout << events[i][0] << " " << win + 1 << " " << lose + 1 << endl;
        killcount[win] += killcount[lose] + 1;
        alive[lose] = 0;
    }

    for (int i = 0; i < N; i++) {
        cout << killcount[i] << endl;
    }

    return 0;
}
