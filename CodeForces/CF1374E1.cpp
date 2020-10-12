// Now I am become Death, the destroyer of worlds.
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>
#include <climits>
#include <fstream>
using namespace std;
//#define cout fout
//#define cin fin
#define endl "\n"
#define ll long long
#define PB push_back
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.in");
ofstream fout("output.out");

int n, k;
vi a;
vi b;
vi both;
int ans;
int alice;
int bob;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        bool alike, blike;
        int t;
        cin >> t >> alike >> blike;
        if (alike&&blike) both.PB(t);
        else if (alike) a.PB(t);
        else if (blike) b.PB(t);
    }
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());
    sort (both.begin(), both.end());

/*
    cout << "a:";
    for (int i = 0; i < a.size(); i++) {
        cout << " " << a[i];
    }
    cout << endl;
    cout << "b:";
    for (int i = 0; i < b.size(); i++) {
        cout << " " << b[i];
    }
    cout << endl;
    cout << "both:";
    for (int i = 0; i < both.size(); i++) {
        cout << " " << both[i];
    }
    cout << endl;
*/

    if (a.size()+b.size()+both.size() < k) {
        cout << -1 << endl;
    }
    else {
        ans = alice = bob = 0;
        while (alice < k || bob < k) {
            fuse++;
            int x = (!a.empty()) ? a[0] : INT_MAX/3;
            int y = (!b.empty()) ? b[0] : INT_MAX/3;
            int z = (!both.empty()) ? both[0] : INT_MAX/3;
            //cout << (alice<k) << " " << (x <= y) << " " << (x<=z) << endl;
            //cout << (z < INT_MAX/3 && z<= x+y) << endl;
            //cout << "xyz: " << x << " " << y << " " << z << endl;
            if (z < INT_MAX/3 && z <= x+y && alice < k && bob < k) {
                //cout << "z enterd!" << endl;
                both.erase(both.begin());
                //cout << "both +" << z << endl;
                ans += z;
                ++alice; ++bob;
            }
            else if (x < INT_MAX/3 && alice < k && x <= y && x <= z) {
                //cout << "x enterd!" << endl;
                a.erase(a.begin());
                //cout << "a +" << x << endl;
                ans += x;
                ++alice;
            }
            else if (y < INT_MAX/3 && bob < k) {
                //cout << "hi\n";
                b.erase(b.begin());
                //cout << "b +" << y << endl;
                ans += y;
                ++bob;
            }
        }
        cout << ans << endl;
    }



    return 0;
}
