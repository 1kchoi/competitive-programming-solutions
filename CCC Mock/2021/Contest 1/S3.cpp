// Mock CCC '21 S3 - Lexicographically Smallest Permutation Subsequence
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, last[NMAX];
set<ii> S;
bool contains[NMAX];
bool testcontains[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void printS() {
    //cout << "PRINTING\n";
    for (set<ii>::iterator it = S.begin(); it != S.end(); it++) {

        if (it != S.begin()) cout << " ";
        cout << (*it)[1];

        //cout << (*it)[0] << " " << (*it)[1] << endl;
    }
    cout << endl;
}

void printLast() {
    cout << "LAST\n";
    for (int i = 1; i <= K; i++) {
        cout << i << " " << last[i] << endl;
    }
    cout << endl;
}

void testans() {
    for (ii x : S) {
        assert(!testcontains[x[1]]);
        testcontains[x[1]] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K;
    memset(last, -1, sizeof(last));
    for (int i = 0; i < N; i++) {
        //cout << "i = " << i << endl;
        int x; cin >> x;
        if (x <= 0) continue;
        //cout << "x = " << x << endl;
        if (last[x] == -1) {
            last[x] = i;
            S.insert({last[x], x});
        }
        else {
            set<ii>::iterator it = S.find({last[x], x});
            //cout << "finding " << (*it)[0] << " " << (*it)[1] << endl;
            //cout << "finding " << last[x] << " " << x << endl;
            it++;
            //cout << "now at " << (*it)[0] << " " << (*it)[1] << endl;
            if (it != S.end() && (*it)[1] < x) {
                --it;
                S.erase(it);
                //cout << "erasing " << (*it)[0] << " " << (*it)[1] << endl;
                last[x] = i;
                S.insert({last[x], x});
            }
            while (it != S.end() && (*it)[1] < )
        }
        //printS();
        //printLast();
        //cout << endl;
    }

    //cout << "FINAL" << endl;
    testans();
    printS();


    return 0;
}
