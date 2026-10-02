# Unique Paths in a Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a grid  **grid[][]**  of size  **n**  ×  **m**  containing values 0 and 1 having the following meanings:

- 0 represents an open cell through which movement is allowed.
- 1 represents a blocked cell that cannot be traversed.

Starting from the top-left cell (0, 0), find the total number of distinct paths to reach the bottom-right cell (n - 1, m - 1). From any cell, movement is allowed only in the right and down directions, and a path is valid only if it passes through open cells.

 **Note:**  It is guaranteed that the answer fits within a 32-bit integer.

 **Examples:** 

```
Input: grid[][] = {{0, 0, 0},{0, 1, 0},{0, 0, 0}}
Output: 2
Explanation: There are two distinct paths from (0, 0) to (2, 2) while avoiding the blocked cell.
 
```

```
Input: grid[][] = {{1, 0, 1}}
Output: 0
Explanation: There is no possible path to reach the end.

```

 **Constraints:** 
1 ≤ n*m ≤ 106

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T13:19:59.125Z  

```cpp
class Solution {
	public:
	
	int solve(int n, int m, int cr, int cc, vector<vector<int>> &grid,
	vector<vector<int>> &dp) {
		int ans = 0;
		
		if (cc > m - 1 || cr > n - 1 || cc <0 || cr < 0)
			return 0;
		
		if (grid[cr][cc] == 1)
			return 0;
		
		if (dp[cr][cc] != -1)
			return dp[cr][cc];
		
		if (cr == n - 1 && cc == m - 1)
			return 1;
		
		int right = solve(n, m, cr, cc + 1, grid, dp);
		
		int down = solve(n, m, cr + 1, cc, grid, dp);
		
		return dp[cr][cc] = right + down;
	}
	int uniquePaths(vector<vector<int>> &grid) {
		// code here
		
		int n = grid.size();
		int m = grid[0].size();
		
		vector<vector<int>> dp(n, vector<int>(m, -1));
		return solve(n, m, 0, 0, grid, dp);
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1)