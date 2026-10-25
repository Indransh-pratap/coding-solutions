# SNSOCIAL - Rating 1581

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T09:07:48.482Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int r, c, k;
        // Read input matching the problem statement: R, C, K
        cin >> r >> c >> k;

        // Convert 1-based indexing to 0-based indexing for C++ arrays
        r--; 
        c--;

        // 8x8 chessboard tracking matrix
        vector<vector<int>> vis(8, vector<int>(8, 0));

        // Queue stores: {row, col, current_moves}
        queue<pair<pair<int, int>, int>> q;

        q.push({{r, c}, 0});
        vis[r][c] = 1;

        // A King can move in 8 directions (horizontal, vertical, and diagonal)
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Starting square counts as visited in <= K moves (0 moves taken)
        int ans = 1; 

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int moves = q.front().second;
            q.pop();

            // If we have already reached the maximum K moves, stop expanding from this square
            if (moves == k) {
                continue;
            }

            for (int i = 0; i < 8; i++) {
                int newrow = row + dr[i];
                int newcol = col + dc[i];

                // Check standard 8x8 boundaries and if it's unvisited
                if (newrow >= 0 && newrow < 8 && newcol >= 0 && newcol < 8 && !vis[newrow][newcol]) {
                    ans += 1;
                    vis[newrow][newcol] = 1;
                    // Increment the move count for the neighbor square
                    q.push({{newrow, newcol}, moves + 1});
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/SNSOCIAL)