// Now I am become Death, the destroyer of worlds.
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define EPS 1e-15
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int n;
int scores[NMAX];
int smallestScore[NMAX];
int pSum[NMAX];
int rawTotal[NMAX];
double maxAvg;
vi ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("homework.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    smallestScore[n-1] = scores[n-1];
    for (int i = n-2; i >= 0; i--) {
        smallestScore[i] = min(smallestScore[i+1],scores[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        pSum[i] = pSum[i+1] + scores[i];
    }

    for (int i = 0; i < n; i++) {
        rawTotal[i] = pSum[i] - smallestScore[i];
    }

    maxAvg = 0.0;
    for (int i = 1; i < n-1; i++) {
        double avg = (double)rawTotal[i] / (double)(n-i);
        cout << "i " << i << ": " << avg << " vs " << maxAvg << endl;
        if (abs(avg - maxAvg) < EPS) {
            ans.PB(i);
        }
        else if (avg-maxAvg > EPS) {
            ans.clear();
            ans.PB(i);
            maxAvg = avg;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
