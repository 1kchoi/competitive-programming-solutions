// IOI 2008 (Cairo) Day 1 - Problem 1 - Type Printer
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct Trie {
    map<char, Trie> children;
    bool isWord;

    void insert(string s, int pos = 0) {
        if (pos == sz(s)) {
            isWord = true;
        }
        else {
            children[s[pos]].insert(s, pos+1);
        }
    }

    void dfsTest() {
        for (auto& it : children) {
            cout << it.first << endl;
            it.second.dfsTest();
            cout << "-" << it.first << endl;
        }
    }

    int nodeCount() {
        int output = 1;
        trav(it, children) {
            output += it.second.nodeCount();
        }
        return output;
    }

    void dfs(string longest, int depth, bool mainBranch) {
        if (!children.empty()) {
            trav(it, children) {
                //cout << "depth " << depth << ", now at char " << c << endl;
                if (it.first != longest[depth] || !mainBranch) {
                    dfs2(longest, depth, false, it.first);
                }
            }
            if (mainBranch) dfs2(longest, depth, true, longest[depth]);
        }
    }

    void dfs2(string longest, int depth, bool mainBranch, char c) {
        cout << c << endl;
        if (children[c].isWord) cout << "P" << endl;
        children[c].dfs(longest, depth+1, mainBranch);
        if (c != longest[depth] || !mainBranch) {
            cout << "-" << endl;
        }
    }

};

int N, longestLength;
string longestWord;
Trie T;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        T.insert(s);
        if (sz(s) > longestLength) {
            longestWord = s;
            longestLength = sz(s);
        }
    }

    cout << 2*(T.nodeCount()-1) + N - longestLength << endl;
    T.dfs(longestWord, 0, 1);
    //T.dfsTest();


    return 0;
}
