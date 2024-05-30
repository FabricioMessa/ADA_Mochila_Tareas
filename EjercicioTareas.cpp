#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 20;
const int INF = 1000000000;
int cost[MAXN][MAXN];
int dp[1 << MAXN];

int solve(int mask, int n) {
    if (mask == (1 << n) - 1) return 0;
    if (dp[mask] != -1) return dp[mask];
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            ans = min(ans, cost[i][__popcnt(mask)] + solve(mask | (1 << i), n));
        }
    }
    return dp[mask] = ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n) << endl;
    return 0;
}