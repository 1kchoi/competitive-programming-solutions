// Now I am become Death, the destroyer of worlds.
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int l, n, f, b, pos, ans;
vii stops; // xi, ci
vi stopssorted;

int calcValue(int i, int p) {
    return stops[i].second * (stops[i].first - p) * (f - b);
}

bool stopSort(int x, int y) {
    return calcValue(x,0) > calcValue(y,0);
}

void printStop() {
    for (int i = 0; i < stops.size(); i++) {
        cout << stops[stopssorted[i]].first << " " << stops[stopssorted[i]].second << " " << calcValue(stopssorted[i],0) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("reststops.out", "w", stdout);

    cin >> l >> n >> f >> b;
    for (int i = 0; i < n; i++) {
        int x, c; cin >> x >> c;
        stops.PB(ii(x,c));
        stopssorted.PB(i);
    }
    sort(stopssorted.begin(), stopssorted.end(), stopSort);
    printStop();


    for (int i = 0; i < n; i++) {
        int index = stopssorted[i];
        if (pos < stops[index].first) {
            ans += calcValue(index,pos);
            pos = stops[index].first;
            cout << i << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
