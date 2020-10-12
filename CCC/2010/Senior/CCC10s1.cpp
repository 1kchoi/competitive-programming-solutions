// CCC '10 S1 - Computer Purchase
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
typedef pair<int,string> is;
typedef vector<is> vis;

int N;
vis A;

bool sortFunc(is f, is g) {
    if (f.first == g.first) {
        return string(f.second) < string(g.second);
    }
    else return f.first > g.first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        int x, y, z;
        cin >> s >> x >> y >> z;
        A.PB(is(2*x + 3*y + z, s));
        //cout << A[i].first << " " << A[i].second << endl;
    }

    if (N == 0) {
        cout << endl;
    }
    else if (N==1) {
        cout << A[0].second << endl;
    }
    else {
        sort(A.begin(), A.end(), sortFunc);

        cout << A[0].second << endl;
        cout << A[1].second << endl;
    }

    return 0;
}
