// CSES Problem Set - Road Reparation
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

class UFDS {
private:
    vi rank, p;
public:
    void init(int N) {
        rank.assign(N+1, 0);
        for (int i = 0; i <= N; i++) {
            p.PB(i);
        }
    }
    int findSet(int i) {
        return (i == p[i]) ? i : p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
            }
            else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
};

int N, M;
ll ans;
priority_queue< iii, vector<iii>, greater<iii> > EL;
UFDS S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    S.init(N);
    for (int i = 0; i < M; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        EL.push(iii(c, ii(a,b)));
    }

    while (!EL.empty()) {
        iii front = EL.top(); EL.pop();
        if (!S.isSameSet(front.second.first, front.second.second)) {
            ans += front.first;
            S.unionSet(front.second.first, front.second.second);
        }
    }

    bool f = true;
    for (int i = 1; i < N && f; i++) {
        if (!S.isSameSet(i, i+1)) {
            cout << "IMPOSSIBLE" << endl;
            f = false;
        }
    }
    if (f) {
        cout << ans << endl;
    }

    return 0;
}
