# ADAKNG - Rating 1581

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Ada King

Chef Ada is training to defend her title of World Chess Champion.

To train her calculation skills, Ada placed a king on a chessboard. Remember that a chessboard has $8$ rows and $8$ columns (for the purposes of this problem, both the rows and the columns are numbered $1$ through $8$); let's denote the square in row $r$ and column $c$ by $(r, c)$. A king on a square $(r, c)$ can move to another square $(r', c')$ if and only if $(r'-r)^2+(c'-c)^2 \le 2$.

Ada placed her king on the square $(R, C)$. Now, she is counting the number of squares that can be visited (reached) by the king in at most $K$ moves. Help Ada verify her answers.

### Input
- The first line of the input contains a single integer $T$ denoting the number of test cases. The description of $T$ test cases follows.
- The first and only line of each test case contains three space-separated integers $R$, $C$ and $K$.
### Output

For each test case, print a single line containing one integer — the number of squares the king can visit.

### Constraints
- $1 \le T \le 512$
- $1 \le R, C, K \le 8$
### Sample 1:
Input
Output

```
1
1 3 1
```

```
6
```

### Explanation:

 **Example case 1:**  The king can stay on its original square or move to one of the squares circled in the following figure.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T09:07:47.272Z  

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

[View on CodeChef](https://www.codechef.com/problems/ADAKNG)