// Kattis - String Matching
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
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

string pattern, text, filler = "~!@#$%^&*)(";
vi pi;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    while (getline(cin, pattern)) {
        getline(cin, text);
        string S = pattern + filler + text;
        //cout << S << endl;
        pi.clear();
        pi.assign(sz(S)+2,0);
        for (int i = 1; i <= sz(S); i++) {
            int j = pi[i-1];
            while (j > 0 && S[i] != S[j]) {
                j = pi[j-1];
            }
            if (S[i] == S[j]) {
                j++;
            }
            pi[i] = j;
        }

        /*
        for (int i = 0; i < sz(pi); i++) {
            cout << pi[i] << " ";
        }
        cout << endl;
        //*/
        //*
        //cout << "buffer: " << sz(pattern+filler) << endl;
        for (int i = sz(pattern+filler); i <= sz(S); i++) {
            if (pi[i] == sz(pattern)) {
                cout << i-sz(pattern+pattern+filler)+1 << " ";
            }
        }
        cout << endl;
        //*/
    }

    return 0;
}
