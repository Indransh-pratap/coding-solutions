# SNSOCIAL

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Snakes and transition from Capitalism to Socialism

After a long duration of the painful, torturous and tumultuous periods of capitalism in Snakeland, now the snakes have decided to adopt socialism. The houses in Snakeland are arranged in a rectangular fashion of dimension  **n * m**. The wealth of the snake in the house at cell (i, j) is given by  **a** [i][j] rupees.

A bill has been passed for making a smooth transition from capitalism to socialism. At the end of each hour, the wealth of a snake will grow and will become equal to the highest wealth that its neighbor had (at the start of the hour). That is, consider the maximum wealth among its neighbors at the start of the hour, and this snake's wealth will become equal to that at the end of the hour. Note that this increase in wealth will happen simultaneously for each snake. Two houses are said to be neighbors of each other if they share a side or corner with each other. Find out the minimum number of hours required for this transition.

### Input

The first line of the input contains an integer  **T**  denoting the number of test cases. The description of  **T**  test cases follows.

The first line of each test case contains two space separated integers:  **n, m**.

Each of the next  **n**  lines contains  **m**  space separated integers. The j-th integer in the i-th row denotes  **a** [i][j].

### Output

For each test case output a single integer corresponding to the minimum number of hours required for the transition.

### Constraints
- 1 ≤ T ≤ 4
- 1 ≤ n, m ≤ 500
- 1 ≤ a[i][j] ≤ 106
### Sample 1:
Input
Output

```
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2
```

```
0
1
2
```

### Explanation:

 **Example 1**. The wealth of all the snakes is already equal. So, no time is required for the transition.

 **Example 2**. At the end of the first hour, the wealth of snakes at cells (1, 1), (2,1) and (1, 2) will change from 1 to 2. Then, the wealth of all the snakes becomes equal, and hence it required a total of 1 hour.

 **Example 3**. At the end of the first hour, the distribution of wealth of Snakeland will be as given below:

```
2 2 2 2
2 2 2 2
1 2 2 2

```

After the end of the second hour, the wealth of all the snakes will be equal. So, the answer is 2.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T09:27:46.310Z  

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

[View on CodeChef](https://www.codechef.com/problems/SNSOCIAL)