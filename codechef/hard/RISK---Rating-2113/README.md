# RISK - Rating 2113

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

### Maximum Size

Chef is playing an easier variation of the board game ‘Risk’ with his friend Mike. There is an $N * M$ grid, depicting the world map. Each cell of the grid is either $1$ or $0$ where $1$ denotes that there is land on this cell, while $0$ denotes water.

In a turn, a player can capture an uncaptured cell that has land, and keep capturing neighbouring cells that share a side with it if they are on land. A cell once captured by a player can't be captured again by another player. The game continues till no uncaptured cell has land. Each player wants to be in control of as many cells of land as possible in total when the game finishes. Find the maximum number of cells of land that Chef can capture if he plays second, and both players play optimally.

###Input:

- First line will contain $T$, number of testcases. Then the testcases follow.
- Each testcase contains $N + 1$ lines of input.
- First line will contain $2$ space separated integers $N$ and $M$ denoting the size of the grid.
- Each of the next $N$ lines contains a binary string of length $M$ depicting the map.

###Output: For each testcase, output in a single line answer to the problem.

###Constraints

- $1 \leq N, M \leq 10^5$
- Each character in the grid is either $0$ or $1$
- There's atleast $1$ land on the grid
- Sum of $N * M$ over all testcases is almost $10^6$.
### Sample 1:
Input
Output

```
3
4 4
1001
0110
0110
1001
2 2
11
11
3 3
100
010
001
```

```
2
0
1
```

### Explanation:

In  **test case 1**, if both players play optimally, it takes $5$ steps to finish the game:

 **Step 1:**  First Mike chooses the cells $\{(2, 2), (2, 3), (3, 2), (3, 3)\}$ adding $4$ to his score.

 **Step 2:**  Second Chef chooses the cell $\{(1, 1)\}$ adding $1$ to his score.

 **Step 3:**  Next Mike chooses the cell $\{(1, 4)\}$ adding $1$ to his score.

 **Step 4:**  Next Chef chooses the cell $\{(4, 1)\}$ adding $1$ to his score.

 **Step 5:**  Finally, Mike chooses the cell $\{(4, 4)\}$ adding $1$ to his score.

Hence total score of Chef is $1 + 1 = 2$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T07:16:26.366Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

int findsize(int row, int col, vector < string > & grid, vector < vector < int >> & vis, int m, int n) {
    int size = 1;

    int dr[] = {
        0,
        -1,
        1,
        0
    };
    int dc[] = {
        -1,
        0,
        0,
        1
    };


    queue < pair < int, int >> q;
    q.push({
        row,
        col
    });


    vis[row][col] = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newrow = r + dr[i];
            int newcol = c + dc[i];


            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == '1' && !vis[newrow][newcol]) {
                q.push({
                    newrow,
                    newcol
                });
                vis[newrow][newcol] = 1;
                size += 1;
            }
        }
    }
    return size;
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector < string > grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vector < vector < int >> vis(n, vector < int > (m, 0));
        vector < int > sizes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && grid[i][j] == '1') {
                    int size = findsize(i, j, grid, vis, m, n);

                    sizes.push_back(size);
                }

            }
        }




        int mike = 0;
        int chef = 0;

        std::sort(sizes.rbegin(), sizes.rend());

        for (int i = 0; i < sizes.size(); i++) {
            if (i % 2 == 0) {
                mike += sizes[i];
            }

            else {
                chef += sizes[i];
            }
        }

        cout << chef << endl;
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/RISK)