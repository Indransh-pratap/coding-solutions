# ROOTTREE - Rating 1934

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

### Root the Tree

A  *directed tree*  is a directed graph such that if all edges were undirected, this graph would be a tree. A  *rooted directed tree*  is a directed tree in which there is one vertex (the  *root*, let's denote it by $r$) such that it is possible to reach all vertices of the graph from $r$ by moving along the directed edges.

You are given a directed tree with $N$ vertices (numbered $1$ through $N$). You may perform the following operation on it any number of times (including zero):

- Choose some edge which currently exists in the graph.
- Remove this edge.
- Add a new edge in such a way that the graph becomes a directed tree again.

What is the smallest number of operations which need to be performed in order to make the directed tree rooted?

### Input
- The first line of the input contains a single integer $T$ denoting the number of test cases. The description of $T$ test cases follows.
- The first line of each test case contains a single integer $N$.
- Each of the next $N-1$ lines contains two space-separated integers $u$ and $v$ denoting that there is a directed edge from $u$ to $v$ in the tree.
### Output

For each test case, print a single line containing one integer ― the smallest number of operations we need to perform to create a rooted directed tree.

### Constraints
- $1 \le N \le 10^4$
- $1 \le u, v \le N$
- the graph described on the input is a directed tree
- the sum of $N$ over all test cases does not exceed $10^5$
### Subtasks

 **Subtask #1 (20 points):**  for each edge, $u = 1$ or $v = 1$ (the graph is a directed star)

 **Subtask #2 (80 points):**  original constraints

### Sample 1:
Input
Output

```
2
3
1 2
3 2
3
1 2
2 3
```

```
1
0
```

### Explanation:

 **Example case 1:**  We can delete the edge from vertex $3$ to vertex $2$ and insert an edge from $3$ to $1$. Then, the graph becomes a rooted directed tree with vertex $3$ as the root. However, there are many other possible solutions.

 **Example case 2:**  The graph is already a rooted directed tree; the root is vertex $1$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T12:08:36.133Z  

```c_cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> indegree(N + 1, 0);

        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            indegree[v]++;
        }

        int sources = 0;

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                sources++;
            }
        }

        cout << sources - 1 << '\n';
    }

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/ROOTTREE)