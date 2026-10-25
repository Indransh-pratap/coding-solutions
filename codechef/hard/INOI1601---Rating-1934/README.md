# INOI1601 - Rating 1934

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T12:08:37.140Z  

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

[View on CodeChef](https://www.codechef.com/problems/INOI1601)