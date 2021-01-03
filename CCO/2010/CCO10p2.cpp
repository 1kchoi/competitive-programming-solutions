// CCO '10 P2 - Tree Pruning
#include <bits/stdc++.h>
using namespace std;
#define NMAX 305
#define INF 0x3f

int N, D, color[NMAX], subtreeSum[NMAX], totalScore, dp[NMAX][4 * NMAX];
int eulerTour[NMAX], eulerStart[NMAX], eulerEnd[NMAX], eulerTimer = 0;
vector<int> tree[NMAX];

int dfs(int node, int parent) {
    eulerTour[eulerTimer] = node;
    eulerStart[node] = eulerTimer;
    eulerTimer++;
    int sum = color[node];
    for (int child : tree[node]) {
        if (child != parent) sum += dfs(child, node);
    }
    eulerEnd[node] = eulerTimer - 1; // this is the position of node's final child in the euler tour
    subtreeSum[eulerStart[node]] = sum;
    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // reading input
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int nodeID, nodeColor, numChildren;
        cin >> nodeID >> nodeColor >> numChildren;
        color[nodeID] = nodeColor;
        if (nodeColor == 0) color[nodeID] = -1;
        for (int j = 0; j < numChildren; j++) {
            int childNode; cin >> childNode;
            tree[nodeID].push_back(childNode);
            tree[childNode].push_back(nodeID);
        }
    }

    // finding total score, recursively generating subtree sums and euler tour information
    totalScore = dfs(0, -1);

    // dp[i][j] = minimum number of prunes to gain j points while only looking at the first i euler tour nodes?
    // setting all values in the DP table to INF by default, except for starting case (0, 0), which is set to 0
    // all values in DP table offset by 2 * N to account for negative score values
    memset(dp, INF, sizeof(dp));
    dp[0][2 * N] = 0;

    for (int i = 0; i + 1 < N; i++) {
        int nextnode = eulerTour[i + 1];
        int nextvalue = subtreeSum[i + 1];
        for (int j = 0; j + nextvalue < 4 * N; j++) {
            // option 1: prune the next node
            dp[eulerEnd[nextnode]][j + nextvalue] = min(dp[eulerEnd[nextnode]][j + nextvalue], dp[i][j] + 1);
            //option 2: keep the next node in the tree
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }

    int answer = dp[N - 1][2 * N + totalScore - D];
    if (answer > N) cout << -1 << endl; // answer not found
               else cout << answer << endl; // answer found

    return 0;
}
