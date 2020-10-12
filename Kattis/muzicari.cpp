// Now I am become Death, the destroyer of worlds.
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(502)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N;
int lengths[NMAX];
vi lengthsort; // indexes of lengths, sorted descending
int dp[NMAX];

bool sortLength(int a, int b) {
    return lengths[a] > lengths[b];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
        lengthsort.PB(i);
    }
    sort(lengthsort.begin(), lengthsort.end(), sortLength);

    for (int i = 1; i < )

    return 0;
}
