#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ll2;
typedef vector<int> vi;
typedef vector<string> vs;

string needle, haystack;
int N, H, ans, d, frequency[26] = {0};
vi distinctLetters;
set<ll2> htable;
ll hashvalue = 1e13+7, mods[2] = {(ll)1e14+7, (ll)1e15+7};

ll getHash(string s, int a) {
    ll output = s[0];
    for (int i = 1; i < (int)s.length(); i++) {
        output *= hashvalue;
        output += s[i];
        output %= mods[a];
    }
    return output;
}

void printFreqs() {
    for (int i = 0; i<26; i++) {
        cout << frequency[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < d; i++) {
        cout << distinctLetters[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> needle;
    N = needle.length();
    cin >> haystack;
    H = haystack.length();

    for (int i = 0; i < N; i++) {
        int c = needle.at(i) - 'a';
        if (frequency[c] == 0) {
            distinctLetters.push_back(c);
            d++;
        }
        frequency[c]++;
    }

    for (int i = 0; i < H; i++) {
        frequency[haystack.at(i)-'a']--;
        if (i >= N-1) {
            bool good = true;
            for (int j = 0; j < d && good; j++) { // for each distinct letter
                if (frequency[distinctLetters[j]] != 0) {
                    good = false;
                }
            }
            if (good) {
                string combo = haystack.substr(i-N+1,N);
                ll hash1 = getHash(combo, 0), hash2 = getHash(combo, 1);
                ll2 hashpair(hash1, hash2);
                if (htable.find(hashpair) == htable.end()) {
                    htable.insert(hashpair);
                    ans++;
                }
            }
            frequency[haystack.at(i-N+1)-'a']++;
        }
    }

    cout << ans << endl;
}
