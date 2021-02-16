// USACO 2021 January Contest, Gold
// Problem 2. Telephone
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e4+5)
#define KMAX 55
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, A[NMAX];
vi breed[KMAX];
vi S[KMAX];
//priority_queue<ii> Q;
set<ii> Q;
ll dist[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        breed[A[i]].PB(i);
    }
    for (int i = 1; i <= K; i++) {
        string inp; cin >> inp;
        for (int j = 1; j <= K; j++) {
            if (inp[j - 1] == '1') {
                S[i].PB(j);
            }
        }
    }

    memset(dist, INF, sizeof(dist));
    dist[1] = 0;
    Q.insert({0, 1});
    while (sz(Q)) {
        ii front = *Q.begin(); Q.erase(Q.begin());
        ll v = front[1];
        if (front[0] > dist[v]) continue;
        //cout << "NOW PROCESSING: " << front[0] << " " << v << endl;
        for (int i : S[A[v]]) {
            for (int u : breed[i]) {
                ll d = abs(v - u);
                if (dist[u] > dist[v] + d) {
                    dist[u] = dist[v] + d;
                    Q.insert({dist[u], u});
                    //cout << "pushed " << dist[u] << " " << u << endl;
                }
            }
        }
    }

    if (dist[N] >= dist[0]) {
        cout << -1 << endl;
    }
    else {
        cout << dist[N] << endl;
    }

    return 0;
}
