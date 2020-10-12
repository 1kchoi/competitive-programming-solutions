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
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vvi S;
vi queryChar;
vi queryNum;
int Q;
int location;
int lo, hi, mid;
int startserial;
int seqstart;
bool FLAG;
string s;

void initializeS() {
    vi v;
    for (int i = 0; i < 'z'-'A'+2; i++) {
        S.push_back(v);
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        S[s.at(i)-'A'].push_back(i);
    }
}

void printS() {
    for (int i = 0; i < S.size(); i++) {
        if (S[i].size() > 0) {
            printf("%c: ", i + 'A');
            for (int j = 0; j < S[i].size(); j++) {
                printf("%d ", S[i][j]);
            }
            printf("\n");
        }
    }
}

void takeQuery() {
    string input;
    queryChar.clear();
    queryNum.clear();
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (i == 0 || input.at(i-1) != input.at(i)) {
            queryChar.push_back(input.at(i)-'A');
            queryNum.push_back(1);
        }
        else {
            queryNum[queryNum.size()-1]++;
        }
    }
}

void printQuery() {
    for (int i = 0; i < queryChar.size(); i++) {
        printf("%c %d\n", queryChar[i]+'A', queryNum[i]);
    }
}

void binarySearch(int c) {
    lo = 0; hi = S[c].size()-1;
    if (hi == -1 || location > S[c].back()) {
        seqstart = -1;
        return;
    }
    seqstart = hi;
    while (hi != lo) {
        mid = (lo + hi) / 2;
        //cout << lo << " " << mid << " " << hi << endl;
        if (S[c][mid] == location) {
            //cout << "equal" << endl;
            seqstart = mid;
            break;
        }
        else if (S[c][mid] > location) {
            //cout << "over" << endl;
            seqstart = mid;
            if (hi == mid) break;
            hi = mid;
        }
        else { // S[c][mid] < position
            //cout << "under" << endl;
            if (lo == mid) break;
            lo = mid;
        }
    }
}

int main() {
    initializeS();
    //printS();
    cin >> Q;

    while (Q--){
        FLAG = true;
        location = 0;
        takeQuery();

        for (int i = 0; i < queryChar.size() && FLAG; i++) {
            int c = queryChar[i];
            binarySearch(c);
            //cout << "seqstart: " << seqstart << endl;
            int nextPos = seqstart + queryNum[i] - 1;
            if (seqstart == -1 || nextPos >= S[c].size()) {
                cout << "Not matched" << endl;
                FLAG = false;
                break;
            }
            else {
                location = S[c][nextPos];
            }
            if (i == 0) {
                startserial = S[c][seqstart];
            }
        }
        if (FLAG) cout << "Matched " << startserial << " " << location << endl;
    }

    return 0;
}
