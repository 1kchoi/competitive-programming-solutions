// USACO 2018 February Contest, Silver
// Problem 2. Snow Boots
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, B, A[NMAX], pos;
vii boots;
bool FLAG = false;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("snowboots.in", "r", stdin);
    freopen("input.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < B; i++) {
        int x, y;
        cin >> x >> y;
        boots.PB(ii(x,y));
    }

    int i;
    for (i = 0; i < B && !FLAG; i++) { // iterate over boots
        int depth = boots[i].first;
        int step = boots[i].second;
        for (int j = 1; j <= step && !FLAG; j++) {
            if (A[pos+j] <= depth) {
                pos += j;
                if (pos >= N-1) {
                    FLAG = true;
                }
                j = 0;
            }
        }
    }

    cout << i-1 << endl;

    return 0;
}
