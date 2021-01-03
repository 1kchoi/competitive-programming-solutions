// CCC '18 S5 - Maximum Strategic Savings
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

struct DSU {
    vi e; void init(ll N) { e = vi(N, -1); }
    ll get(ll x) { return (e[x] < 0) ? x : e[x] = get(e[x]); }
    bool sameSet(ll a, ll b) { return get(a) == get(b); }
    ll size(int x) { return -e[get(x)]; }
    bool unite(ll x, ll y) {
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

ll N, M, P, Q, ans, total, xcomp, ycomp;
DSU X, Y;
vector<ar<ll, 4>> EL; // cost, planet/city, node, node

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> P >> Q;
    xcomp = N; ycomp = M;
    X.init(N + 1);
    Y.init(M + 1);
    for (int i = 0; i < P; i++) { // verticals
        ll a, b, cost;
        cin >> a >> b >> cost;
        EL.PB({cost, 0, a, b});
        total += cost * N;
    }
    for (int i = 0; i < Q; i++) { // horizontals
        ll a, b, cost;
        cin >> a >> b >> cost;
        EL.PB({cost, 1, a, b});
        total += cost * M;
    }
    sort(all(EL));


    for (ar<ll, 4> e : EL) {
        ll cost = e[0];
        ll type = e[1];
        ll v = e[2], u = e[3];
        //cout << type << " " << v << " " << u << " " << cost << endl;
        if (type == 1 && X.unite(v, u)) { // horizontal connection, X
            ans += cost * ycomp;
            //cout << "ans += " << cost << " * " << ycomp << "(" << cost * ycomp << ")\n";
            xcomp--;
            if (xcomp <= 0) xcomp = 0;
        }
        else if (type == 0 && Y.unite(v, u)) { // vertical connection, Y
            ans += cost * xcomp;
            //cout << "ans += " << cost << " * " << xcomp << "(" << cost * xcomp << ")\n";
            ycomp--;
            if (ycomp <= 0) ycomp = 0;
        }
    }
    cout << total - ans << endl;


    return 0;
}
