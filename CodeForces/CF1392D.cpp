// Codeforces 1392D. Omkar and Bed Wars
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(2e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int TC, N, ans;
vi G, path;
bool isHead[NMAX];
bool isCycle;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> TC;
    while (TC--) {
        memset(isHead,1,sizeof(isHead));
        isCycle = true;
        ans = 0;
        G.clear();
        cin >> N;
        string s; cin >> s;
        for (int i = 0; i < N; i++) {
            char c = s.at(i);
            if (c == 'L') {
                G.PB(N-1);
                isHead[(i+N-1)%N] = false;
            }
            else {
                G.PB(1);
                isHead[(i+1)%N] = false;
            }
            if (i > 0 && G[i] != G[i-1]) isCycle = false;
        }

        if (isCycle) {
            ans = max((N+2)/3, 0);
        }
        else {
            for (int i = 0; i < N; i++) {
                if (isHead[i]) {
                    path.clear();
                    int pos = i;
                    while (path.size() < 4 || path[path.size()-1] != path[path.size()-3]) {
                        path.PB(pos);
                        pos += G[pos];
                        pos %= N;
                    }
                    ans += max((int)(path.size()-2)/3, 0);
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}
