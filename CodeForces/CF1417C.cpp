// Codeforces 1421C. k-Amazing Numbers
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(3e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, ans[NMAX], kscore;
map<int, vi> S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        S.clear();
        memset(ans,0,sizeof(ans));
        kscore = INT_MAX;

        cin >> N;
        for (int i = 1; i <= N; i++) {
            int a; cin >> a;
            S[a].PB(i);
        }

        for (map<int,vi>::iterator it = S.begin(); it != S.end(); it++) {
            int score = 0, start = 0;
            for (int i = 0; i < sz(it->second); i++) {
                int end = (it->second)[i];
                score = max(score, end - start);
                start = end;
            }
            score = max(score, N-start+1);
            if (score < kscore) {
                ans[score] = it->first;
                kscore = score;
            }
        }

        int l = -1;
        for (int i = 1; i <= N; i++) {
            if (ans[i]) {
                l = ans[i];
            }
            cout << l << " ";
        }
        cout << endl;

    }


    return 0;
}
