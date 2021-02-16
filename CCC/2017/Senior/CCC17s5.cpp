// CCC '17 S5 - RMT
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 150005
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, K, M, Q, L[NMAX], A[NMAX], B[NMAX], lbyline[NMAX], linerotations[NMAX];
vi linepos[NMAX], lineval[NMAX];
map<int, int> temp[NMAX];
set<ii> lastperblock[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

ll getVal(int i) {
    int line = L[i];
    int indexinline = lbyline[i];
    int adjustedindex = indexinline - linerotations[line];
    adjustedindex += sz(lineval[line]);
    adjustedindex %= sz(lineval[line]);
    //cout << line << " " << adjustedindex << " " << sz(lineval[line]) << endl;
    return lineval[line][adjustedindex];
}

void debugPrint1() {
    cout << "L BY LINE" << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " " << L[i] << " " << lbyline[i] << endl;
    }
    cout << endl;
    cout << "LINE POS" << endl;
    for (int i = 1; i <= M; i++) {
        cout << i << ": ";
        for (int j = 0; j < sz(linepos[i]); j++) {
            cout << linepos[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "LINE VAL" << endl;
    for (int i = 1; i <= M; i++) {
        cout << i << ": ";
        for (int j = 0; j < sz(lineval[i]); j++) {
            cout << lineval[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void debugPrint2() {
    cout << "LAST PER BLOCK" << endl;
    for (int i = 1; i <= M; i++) {
        cout << i << ": ";
        for (set<ii>::iterator it = lastperblock[i].begin(); it != lastperblock[i].end(); it++) {
            cout << "(" << (*it)[0] << "," << (*it)[1] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> Q;
    K = (int)(sqrt(N)); // K items per block

    for (int i = 0; i < N; i++) {
        cin >> L[i];
        lbyline[i] = sz(linepos[L[i]]);
        linepos[L[i]].PB(i);
    }

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i / K] += A[i];
        lineval[L[i]].PB(A[i]);
    }
    //debugPrint1();

    for (int i = 0; i < N; i++) {
        temp[L[i]][i / K] = lbyline[i];
    }
    for (int i = 0; i < N; i++) {
        lastperblock[L[i]].insert({i / K, temp[L[i]][i / K]});
    }
    //debugPrint2();

    while (Q--) {
        int type; cin >> type;
        if (type == 1) { // query l r
            ll l, r; cin >> l >> r; --l; --r;
            ll lblock = l / K, rblock = r / K, ans = 0;
            if (lblock == rblock) {
                for (int i = l; i <= r; i++) {
                    ans += getVal(i);
                }
            }
            else {
                for (int i = l; i < (lblock + 1) * K; i++) {
                    //cout << i << endl;
                    ans += getVal(i);
                    //getVal(i);
                }
                for (int i = lblock + 1; i < rblock; i++) {
                    ans += B[i];
                }
                for (int i = rblock * K; i <= r; i++) {
                    //cout << i << endl;
                    ans += getVal(i);
                    //getVal(i);
                }
            }

            //cout << "ANS: ";
            cout << ans << endl;
        }
        else { // update x
            int x; cin >> x;
            int linesize = sz(lineval[x]);
            linerotations[x] = (linerotations[x] + 1) % linesize;
            int r = linerotations[x];
            set<ii>::iterator it = lastperblock[x].begin();
            int firstblock, lastblock, firstindex, lastindex;
            firstblock = lastblock = ((*it)[0] - r + linesize) % linesize;
            firstindex = lastindex = (*it)[1];
            B[firstblock] -= lineval[x][firstindex];
            for (++it; it != lastperblock[x].end(); it++) {
                int thisblock = (*it)[0], thisindex = (*it)[1];
                B[thisblock] += lineval[x][lastindex];
                B[thisblock] -= lineval[x][thisindex];
                lastblock = thisblock;
                lastindex = thisindex;
            }
            B[firstblock] += lineval[x][lastindex];
        }
    }


    return 0;
}
