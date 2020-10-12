#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
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

string needle, haystack;
int N, H, ans, frequency[26] = {0}, numPowers;
ll alpha0 = 1e9-63, hashvalues[3], mod[3] = {(ll)1e9+7, (ll)1e9+9, (ll)1e9+21};
set<ar<ll, 3>> hashtable;
vector<ll> alpha[3];

void initHash() {
    numPowers = max(N, H);
    for (int i = 0; i < 3; i++) {
        alpha[i].assign(numPowers, 1);
        for (int j = 1; j < numPowers; j++) {
            alpha[i][j] = alpha[i][j-1] * alpha0;
            alpha[i][j] %= mod[i];
        }
    }
}

void initFreq() {
    for (int i = 0; i < N; i++) {
        int c = needle.at(i) - 'a';
        frequency[c]++;
    }
}

bool checkSubstring() {
    for (int j = 0; j < 26; j++) {
        if (frequency[j]) {
            return false;
        }
    }
    return true;
}

void addFront(int i) {
    frequency[haystack[i]-'a']--;
    for (int p = 0; p < 3; p++) {
        hashvalues[p] *= alpha0;
        hashvalues[p] += haystack[i];
        hashvalues[p] %= mod[p];
    }
}

void removeBack(int i) {
    frequency[haystack[i]-'a']++;
    for (int p = 0; p < 3; p++) {
        hashvalues[p] += mod[p] * alpha[p][N-1];
        hashvalues[p] -= (haystack[i] * alpha[p][N-1]);
        hashvalues[p] %= mod[p];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> needle;
    N = needle.length();
    cin >> haystack;
    H = haystack.length();

    initHash();
    initFreq();

    for (int i = 0; i < H; i++) {
        addFront(i);
        if (i >= N-1) {
            if (checkSubstring()) {
                ar<ll,3> hv = {hashvalues[0], hashvalues[1], hashvalues[2]};
                if (!hashtable.count(hv)) {
                    hashtable.insert(hv);
                    ans++;
                }

            }
            removeBack(i-N+1);
        }
    }

    cout << ans << endl;
}
