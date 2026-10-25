# CFMAR04

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T09:27:47.477Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            maxi = max(maxi, arr[i][j]);
        }
    }

    // vis[i][j] will store the time/hours it takes for the max wealth to reach cell (i, j)
    // Initialize with -1 to signify unvisited cells
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // Push ALL maximum wealth cells into the queue at the exact same time (Multi-Source BFS)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == maxi) {
                q.push({i, j});
                vis[i][j] = 0; // Starts at hour 0
            }
        }
    }

    // 8-directional movement arrays (includes corners)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int max_hours = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int newrow = r + dr[i];
            int newcol = c + dc[i];

            // If the neighboring cell is within boundaries and has not been reached by max wealth yet
            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && vis[newrow][newcol] == -1) {
                vis[newrow][newcol] = vis[r][c] + 1;
                max_hours = max(max_hours, vis[newrow][newcol]);
                q.push({newrow, newcol});
            }
        }
    }

    cout << max_hours << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CFMAR04)