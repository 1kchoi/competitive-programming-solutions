// CSES Problem Set - Array Description
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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M;
ll G[NMAX][103];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        ll a; cin >> a;
        for (int j = 1; j <= M; j++) {
            if (a == 0 || a == j){
                if (i == 1) {
                    G[i][j] = 1;
                }
                else {
                    G[i][j] = G[i-1][j-1] + G[i-1][j] + G[i-1][j+1];
                }
            }
            G[i][j] %= MOD;
            //cout << G[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;


    ll ans = 0;
    for (int i = 1; i <= M; i++) {
        ans += G[N][i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
