// USACO 2019 December Contest, Silver
// Problem 2. Meetings
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
typedef ar<ll, 3> iii;
typedef vector<ll> vi;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, L, totalweight, T, ans;
viii cows;
vii events;
vi lcows, rcows;
queue<int> Q;

void printEvents() {
    for (ii x : events) {
        cout << x[0] << " " << x[1] << endl;
    }
    cout << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("meetings");

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        ll w, x, d; cin >> w >> x >> d;
        cows.PB({x, w, d});
        totalweight += w;
    }
    sort(all(cows));

    for (int i = 0; i < N; i++) {
        if (cows[i][2] == 1) rcows.PB(cows[i][0]);
        else lcows.PB(cows[i][0]);
    }

    for (int i = 0; i < sz(lcows); i++) {
        events.PB({lcows[i], cows[i][1]});
    }
    for (int i = 0; i < sz(rcows); i++) {
        events.PB({L - rcows[i], cows[sz(lcows) + i][1]});
    }
    sort(all(events));

    for (int i = 0; i < N; i++) {
        totalweight -= 2 * events[i][1];
        if (totalweight <= 0) {
            T = events[i][0]; break;
        }
    }

    for (int i = 0; i < N; i++) {
        if (cows[i][2] == -1) {
            while (sz(Q) && Q.front() + 2 * T < cows[i][0]) Q.pop();
            ans += sz(Q);
        }
        else {
            Q.push(cows[i][0]);
        }
    }

    cout << ans << endl;

    return 0;
}
