// CCC '17 S3 - Nailed It!
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define INF 0x7f7f7f7f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, freq[2005], longest, numWays;
vi boardlengths;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    memset(freq, 0, sizeof(freq));
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        freq[a]++;
    }
    for (int i = 2; i < 4000; i++) {
        int score = 0;
        for (int j = 1; j <= i/2; j++) {
            if (2*j == i) {
                score += freq[j]/2;
            }
            else {
                if (i-j <= 2000) {
                    score += min(freq[j], freq[i-j]);
                }
            }
        }
        if (score > longest) {
            longest = score;
            numWays = 1;
        }
        else if (score == longest) {
            numWays++;
            //cout << i << endl;
        }
        //cout << i << " " << longest << " " << numWays << endl;
    }
    cout << longest << " " << numWays << endl;

    return 0;
}
