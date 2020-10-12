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
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX 1e12
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int valid(long long n, long long k, long long m, long long x) {
  long long g = 0;
  while(k > 0 && g < n) {
    long long y = (n - g) / x;
    if(y < m) {
      long long leftover = (n-g + m-1) / m;
      return leftover <= k;
    }
    long long maxmatch = n - x*y;
    long long numdays = (maxmatch - g) / y + 1;
    if(numdays > k) numdays = k;
    g += y * numdays;
    k -= numdays;
  }
  return g >= n;
}

int main() {
  freopen("input.in", "r", stdin);
  //freopen("loan.out", "w", stdout);
  long long n, k, m;
  scanf("%lld %lld %lld", &n, &k, &m);
  long long lhs = 1;
  long long rhs = 1e12;
  while(lhs < rhs) {
    long long mid = (lhs + rhs + 1) / 2;
    cout << mid << endl;
    if(valid(n, k, m, mid)) {
      lhs = mid;
    }
    else {
      rhs = mid - 1;
    }
  }
  printf("%lld\n", lhs);
}
