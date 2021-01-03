// DMOPC '20 Contest 2 P1 - Laugh Graphs
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, A[NMAX], B[NMAX], pos = 0, smallest = 0, largest = -1;
string S;


void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == '^') {
            B[i] = 1;
            A[i] = pos;
            largest = max(largest, pos);
            pos++;
        }
        else if (S[i] == 'v') {
            B[i] = -1;
            pos--;
            A[i] = pos;
            smallest = min(smallest, pos);
        }
        else {
            B[i] = 0;
            A[i] = pos;
            largest = max(largest, pos);
            smallest = min(smallest, pos);
        }
    }

    for (int i = largest; i >= smallest; i--) {
        for (int j = 0; j < N; j++) {
            if (A[j] == i) {
                if (B[j] == 1) {
                    cout << "/";
                }
                else if (B[j] == -1) {
                    cout << "\\";
                }
                else {
                    cout << "_";
                }
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}
