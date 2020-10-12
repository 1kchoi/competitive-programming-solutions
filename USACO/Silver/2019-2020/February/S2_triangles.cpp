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
#define cout fout
#define cin fin
#define ll long long
#define PB push_back
#define NMAX (int)(1e5 + 5)
#define X second.first
#define Y second.second
typedef pair<int,int> ii;
typedef pair <int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;

//ifstream fin("input.txt");
ifstream fin("triangles.in");
ofstream fout("triangles.out");

viii points;
int N;
ll ans;
ll xsum[NMAX];
ll ysum[NMAX];

bool sortByX (iii a, iii b) {
    int ax = a.second.first, bx = b.second.first;
    int ay = a.second.second, by = b.second.second;
    if (ax == bx) return ay < by;
    return ax < bx;
}
bool sortByY (iii a, iii b) {
    int ax = a.second.first, bx = b.second.first;
    int ay = a.second.second, by = b.second.second;
    if (ay == by) return ax < bx;
    return ay < by;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        points.PB(iii(i, ii()));
        points[i].first = i;
        cin >> points[i].second.first >> points[i].second.second;
    }

    sort(points.begin(), points.end(), sortByX);

    /*for (int i = 0; i < points.size(); i++) {
        cout << points[i].X << " " << points[i].Y << "\n";
    }*/

    bool FLAG = false;
    int count, start, startlocation;

    for (int i = 0; i < points.size(); i++) {
        if (!FLAG) {
            FLAG = true;
            start = i;
            startlocation = points[start].Y;
            count = 1;
            //cout << "start: " << start << " (" << startlocation << ")\n";
            while (i+count < points.size() && points[i+count].X == points[i].X) {
                count++;
            }
        }

        if (i == start+count-1) {
            FLAG = false;
        }

        if (count == 1) { // edge case
            continue;
        }

        if (i == start) {
            for (int j = 1; j < count; j++) {
                ysum[points[i].first] += points[i+j].Y - startlocation;
            }
        }
        else {
            ysum[points[i].first] = ysum[points[i-1].first] + (2*(i-start)-count)*(points[i].Y-points[i-1].Y);
        }
    }

    sort(points.begin(), points.end(), sortByY);
    /*for (int i = 0; i < points.size(); i++) {
        cout << points[i].X << " " << points[i].Y << endl;
    }*/
    FLAG = false;
    for (int i = 0; i < points.size(); i++) {
        if (!FLAG) {
            FLAG = true;
            start = i;
            startlocation = points[start].X;
            count = 1;
            //cout << "start: " << start << " (" << startlocation << ")\n";
            while (i+count < points.size() && points[i+count].Y == points[i].Y) {
                count++;
            }
        }

        if (i == start+count-1) {
            FLAG = false;
        }

        if (count == 1) { // edge case
            continue;
        }

        if (i == start) {
            for (int j = 1; j < count; j++) {
                xsum[points[i].first] += points[i+j].X - startlocation;
            }
        }
        else {
            xsum[points[i].first] = xsum[points[i-1].first] + (2*(i-start)-count)*(points[i].X-points[i-1].X);
        }
    }


    //cout << "ans" << endl;
    ans = 0;

    for (int i = 0; i < N; i++) {
        //cout << xsum[i] << " " << ysum[i] << endl;
        ans += xsum[i] * ysum[i];
    }

    cout << ans % 1000000007 << endl;

    return 0;
}
