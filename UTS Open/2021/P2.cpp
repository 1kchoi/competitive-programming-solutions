// UTS Open '21 P2 - Prime Array
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 105
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll K, N, A[NMAX], ans[NMAX], target;
ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571};

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void dA() {
    for (int i = 1; i <= N; i++) {
        cout << i << " " << A[i] << endl;
    }
    cout << endl;
}

void printAns() {
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> K;
    N = min(100LL, (ll)sqrt(2 * K) + 2);
    cout << N << endl;
    target = N * (N + 1) / 2 - K;
    assert(target >= 0);

    // fix case when N is 1, there's no A[1]

    ll runningsum = 0;
    int i = 1;
    for (; i <= N; i++) {
        if (runningsum + A[i - 1] + 1 <= target) {
            runningsum += A[i - 1] + 1;
            A[i] = A[i - 1] + 1;
        }
        else break;
    }
    A[i] = target - runningsum;
    for (int i = 1; i <= N; i++) {
        ans[i] = 1;
    }
    i = 1;
    for (; i <= N; i++) {
        if (A[i] == A[i - 1] + 1) {
            ans[i] *= 2;
        }
        else break;
    }
    int j = A[i];
    while (j) {
        ans[i] *= 3;
        i--;
        j--;
    }
    printAns();



    return 0;
}
