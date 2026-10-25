# DIAMTREE - Rating 1620

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Find Tree Diameter

You're given a tree with $N$ vertices numbered from $1$ to $N$. A tree is defined as a connected, undirected graph with $N$ vertices and $N-1$ edges. The distance between two vertices in a tree is equal to the number of edges on the unique simple path between them.

The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.

### Input
- The first line of the input contains a single integer $T$ denoting the number of test cases. The description of $T$ test cases follows.
- The first line of each test case contains an integer $N$.
- Each of the following $N−1$ lines contains two space-separated integers $u$ and $v$ denoting an edge between nodes $u$ and $v$.
### Output

For each test case, output in a single line the answer to the problem - the diameter of the tree.

### Constraints
- $1 \leq T \leq 10$
- $1 \leq N \leq 10^5$
- $1 \leq u, v \leq N$
### Sample 1:
Input
Output

```
2
6
1 2
1 3
2 4
2 5
3 6
5
1 2
1 3
3 4
3 5
```

```
4
3
```

### Explanation:

 **Example case 1:**  The structure of the given tree is shown below.

- The diameter corresponds to the path $4?2?1?3?6$ or $5?2?1?3?6$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T09:33:53.315Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

// Global tracking variables for the DFS traversal
int max_dist;
int furthest_node;

// Standard DFS traversal
// 'curr' is the node we are currently visiting
// 'parent' prevents us from walking backwards up the tree
// 'curr_dist' tracks the number of edges crossed from the start node
void dfs(int curr, int parent, int curr_dist, const vector<vector<int>>& adj) {
    // If we found a deeper path, update our global tracking records
    if (curr_dist > max_dist) {
        max_dist = curr_dist;
        furthest_node = curr;
    }

    // Traverse all connected neighbors
    for (int neighbor : adj[curr]) {
        if (neighbor != parent) { // Skip the node we just came from
            dfs(neighbor, curr, curr_dist + 1, adj);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // Phase 1: Reset global tracking trackers and find the first endpoint
    max_dist = -1;
    furthest_node = 1;
    dfs(1, 0, 0, adj); // Using '0' as a dummy parent for the root

    int endpoint_x = furthest_node;

    // Phase 2: Reset trackers again and launch from endpoint_x to find the diameter
    max_dist = -1;
    dfs(endpoint_x, 0, 0, adj);

    // The max_dist recorded on the second pass is our absolute tree diameter
    cout << max_dist << "\n";
}

int main() {
    // Fast I/O optimization
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

[View on CodeChef](https://www.codechef.com/problems/DIAMTREE)