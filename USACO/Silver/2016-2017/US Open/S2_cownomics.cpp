// USACO 2017 US Open Contest, Silver
// Problem 2. Bovine Genomics
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
#define MOD (int)(1e6+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, M, ans, A[505][55], B[505][55];
//vector<string> A, B;
bool filter[100];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("cownomics");

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'G') {
                A[i][j] = 0;
            }
            else if (s[j] == 'C') {
                A[i][j] = 1;
            }
            else if (s[j] == 'A') {
                A[i][j] = 2;
            }
            else if (s[j] == 'T') {
                A[i][j] = 3;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'G') {
                B[i][j] = 0;
            }
            else if (s[j] == 'C') {
                B[i][j] = 1;
            }
            else if (s[j] == 'A') {
                B[i][j] = 2;
            }
            else if (s[j] == 'T') {
                B[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < M - 2; i++) {
        for (int j = i + 1; j < M - 1; j++) {
            for (int k = j + 1; k < M; k++) {
                memset(filter, 0, sizeof(filter));
                ans++;

                for (int l = 0; l < N; l++) {
                    int x = A[l][i] * 16 + A[l][j] * 4 + A[l][k];
                    filter[x] = true;
                }
                for (int l = 0; l < N; l++) {
                    int x = B[l][i] * 16 + B[l][j] * 4 + B[l][k];
                    if (filter[x]) {
                        ans--;
                        break;
                    }
                }

            }
        }
    }


    cout << ans << endl;


    return 0;
}
