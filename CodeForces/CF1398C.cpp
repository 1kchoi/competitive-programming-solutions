// Codeforces 1398C - Good Subarrays
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define FMAX (int)(2e6+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, P;
ll ans;
map<int,int> M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        P = ans = 0;
        M.clear();
        cin >> N;
        string s;
        cin >> s;
        M.insert(ii(0, 1));
        for (int i = 1; i <= N; i++) {
            P += s.at(i-1)-'0';
            map<int,int>::iterator q = M.find(P-i);
            if (q == M.end()) {
                M.insert(ii(P-i, 1));
            }
            else {
                ans += q->second;
                ++(q->second);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
