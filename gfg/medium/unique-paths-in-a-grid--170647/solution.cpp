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
