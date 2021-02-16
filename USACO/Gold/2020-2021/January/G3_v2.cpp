// USACO 2021 January Contest, Gold
// Problem 3. Dance Mooves
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define KMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct DSU {
    vi e; void init(int N) {e.assign(N, -1);}
    ll get(ll i) { return (e[i] < 0) ? i : e[i] = get(e[i]); }
    bool sameSet(int i, int j) { return (get(i) == get(j)); }
    ll size(int i) { return -e[get(i)]; }
    bool unite(int i, int j) {
        i = get(i), j = get(j); if (i == j) return 0;
        if (e[i] > e[j]) swap(i, j);
        e[j] += e[i]; e[i] = j; return 1;
    }
};

ll N, K, M, moves[KMAX][2], maxcycle, reps;
vi cows, bcows;
vector<set<ll>> cowPos, bcowPos;
set<ll> ans[NMAX];
DSU S;

void printAns1(vector<set<ll>>& cpos) {
    for (int i = 1; i <= N; i++) {
        cout << sz(cpos[i]) << endl;
    }
}

void printAns2() {
    for (int i = 1; i <= N; i++) {
        int parent = S.get(i);
        for (int pos : cowPos[i]) {
            ans[parent].insert(pos);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << sz(ans[S.get(i)]) << endl;
    }
}

void moveCows(vi& c, vector<set<ll>>& cpos, vi& objc, vector<set<ll>>& objcpos) {
    vi ret(c);
    vector<set<ll>> retpos(cpos);

    for (int i = 1; i <= N; i++) {
        ret[i] = c[objc[i]];
    }
    for (int j = 1; j <= N; j++) {
        int i = c[j];
        retpos[i].insert(all(objcpos[j]));
    }

    c = ret;
    cpos = retpos;
}

void debugPrint(vi& c, vector<set<ll>>& cpos) {
    for (int i = 1; i <= N; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= N; i++) {
        cout << i << ": ";
        for (ll x : cpos[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> K >> M;
    cows.resize(N + 1);
    bcows.resize(N + 1);
    cowPos.resize(N + 1);
    bcowPos.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cows[i] = i;
        cowPos[i].insert(i);
        bcows[i] = i;
        bcowPos[i].insert(i);
    }
    for (int i = 0; i < min(K, M); i++) {
        int a, b; cin >> a >> b;
        moves[i][0] = a; moves[i][1] = b;
        swap(bcows[a], bcows[b]);
        bcowPos[bcows[a]].insert(a);
        bcowPos[bcows[b]].insert(b);
        swap(cows[a], cows[b]);
        cowPos[cows[a]].insert(a);
        cowPos[cows[b]].insert(b);
    }

    if (M <= K) {
        printAns1(bcowPos);
        return 0;
    }

    reps = (M - K) / K / 2;

    while (reps) {
        moveCows(bcows, bcowPos, bcows, bcowPos);
        if (reps & 1) {
            moveCows(cows, cowPos, bcows, bcowPos);
        }
        reps /= 2;
    }


    for (int i = 0; i < M % K; i++) {
        ll a = moves[i][0], b = moves[i][1];
        swap(cows[a], cows[b]);
        cowPos[cows[a]].insert(a);
        cowPos[cows[b]].insert(b);
    }

    printAns1(cowPos);
    //debugPrint(cows, cowPos);

    return 0;
}
