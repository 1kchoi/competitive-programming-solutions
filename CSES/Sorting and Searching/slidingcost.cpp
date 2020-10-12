// CSES Problem Set - Sliding Cost
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, A[NMAX];
vii firstK; // A[i], i
set<ii> top;
set<ii, greater<ii> > bottom;
ii med(-1,-1);
ll cost;

void rebalance() {
    int m = sz(top) + sz(bottom) + 1;
    if (sz(bottom) < (m-1)/2) {
        ll dmed = (*top.begin()).first - med.first;
        bottom.insert(med);
        med = *top.begin();
        top.erase(med);
        // bottom cost += (new size of bottom * (new med - old med));
        // top cost -= (old size of top * (new med - old med));
        cost += dmed * (sz(bottom) - sz(top) - 1);
    }
    else if (sz(bottom) > (m-1)/2) {
        ll dmed = med.first - (*bottom.begin()).first;
        top.insert(med);
        med = *bottom.begin();
        bottom.erase(med);
        // bottom cost -= (old size of bottom * (old med - new med))
        // top cost += (new size of top * (old med - new med))
        cost += dmed * (sz(top) - sz(bottom) - 1);
    }
}

void add(int i) {
    ii p(A[i], i);

    if (med.first == -1) {
        med = p; return;
    }

    if (A[i] < med.first) {
        bottom.insert(p);
        cost += med.first - A[i];
    }
    else {
        top.insert(p);
        cost += A[i] - med.first;
    }
    rebalance();

}

void rem(int i) {
    ii p(A[i], i);
    if (A[i] > med.first) {
        top.erase(p);
        cost -= A[i] - med.first;
    }
    else if (A[i] < med.first) {
        bottom.erase(p);
        cost -= (med.first - A[i]);
    }
    else { // A[i] == med.first
        ll dmed = (*top.begin()).first - med.first;
        med = *top.begin();
        top.erase(med);
        cost += dmed * (sz(bottom) - sz(top) - 1);
    }
    rebalance();
}

void print() {
    for (set<ii >::reverse_iterator it = bottom.rbegin(); it != bottom.rend(); it++) {
        cout << (*it).first << " ";
    }
    cout << "- " << med.first << " - ";
    for (auto& it : top) {
        cout << it.first << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < K-1; i++) {
            add(i);
        }
        for (int i = K-1; i < N; i++) {
            add(i);
            cout << cost << " ";
            rem(i-K+1);
        }
        cout << endl;
    }

    return 0;
}
