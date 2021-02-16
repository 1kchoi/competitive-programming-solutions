// DMOPC '19 Contest 1 P5 - Broken String
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K;
map<int, vi> G;
map<int, int> outdegree, indegree;
set<int> allnodes;
string ans;
vector<int> anspath;
int pow26[] = {1, 27, 27*27, 27*27*27, 27*27*27*27};

int hashs(string s) {
    int a = 0;
    for (int i = 0; i < sz(s); i++) {
        a += (s[i] - 'a' + 1) * pow26[i];
    }
    return a;
}

string unhash(int x) {
    string s("");
    while (x) {
        s = s + (char)(x % 27 + 'a' - 1);
        x /= 27;
    }
    return s;
}

void dfs(int v) {
    while (outdegree[v]) {
        dfs(G[v][--outdegree[v]]);
    }
    anspath.PB(v);
}

int findStart() {
    for (int v : allnodes) {
        if (outdegree[v] - indegree[v] == 1) {
            return v;
        }
    }
    return -1;
}

bool isEuler() {
    int st = 0, en = 0;
    for (int v : allnodes) {
        if (abs(outdegree[v] - indegree[v]) > 1) {
            return false;
        }
        if (outdegree[v] - indegree[v] == 1) {
            st++;
        }
        else if (indegree[v] - outdegree[v] == 1) {
            en++;
        }
    }
    return (st == 1 && en == 1);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K;
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            cout << s;
        }
        cout << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int u = hashs(s.substr(0, K - 1));
        int v = hashs(s.substr(1));
        G[u].PB(v);
        outdegree[u]++;
        indegree[v]++;
        allnodes.insert(u);
        allnodes.insert(v);
    }
    if (!isEuler()) {
        cout << -1 << endl;
        return 0;
    }

    int stnode = findStart();
    assert(stnode != -1);
    dfs(stnode);

    cout << sz(anspath) << endl;
    if (sz(anspath) != N + 1) {
        cout << -1 << endl;
        return 0;
    }
    reverse(all(anspath));
    for (int i = 0; i < sz(anspath); i++) {
        string s = unhash(anspath[i]);
        if (!i) {
            cout << s;
        }
        else {
            cout << s[K - 2];
        }
    }
    cout << endl;


    return 0;
}
