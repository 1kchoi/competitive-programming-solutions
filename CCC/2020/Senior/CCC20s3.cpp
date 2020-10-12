#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

string needle;
string haystack;
int N, H;
int frequency[26] = {0};
vi distinctLetters;
set<string> duplicates;
int ans;
int d;
int dcounter;

void printFreqs() {
    for (int i = 0; i<26; i++) {
        cout << frequency[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < d; i++) {
        cout << distinctLetters[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    cin >> needle;
    N = needle.length();
    cin >> haystack;
    H = haystack.length();

    for (int i = 0; i < N; i++) {
        int c = needle.at(i) - 'a';
        if (frequency[c] == 0) {
            distinctLetters.push_back(c);
            d++;
        }
        frequency[c]++;
    }

    for (int i = 0; i < H; i++) {
        frequency[haystack.at(i)-'a']--;
        if (i >= N-1) {
            bool good = true;
            for (int j = 0; j < d; j++) { // for each distinct letter
                if (frequency[distinctLetters[j]] != 0) {
                    good = false;
                    break;
                }
            }
            if (good) {
                string combo = haystack.substr(i-N+1,N);
                //cout << "FOUND: " << combo << endl;
                int result = haystack.find(combo);
                //cout << result << " " << i-N+1 << endl;
                if (duplicates.find(combo) == duplicates.end() || result == -1 || result >= i-N+1) {
                    //cout << (duplicates.find(combo) != duplicates.end()) << endl;
                    duplicates.insert(combo);
                    //cout << "increasing\n";
                    ans++;
                }
            }

            frequency[haystack.at(i-N+1)-'a']++;
        }
    }

    //cout << COMBINATIONS.size() << endl;
    cout << ans << endl;
}
