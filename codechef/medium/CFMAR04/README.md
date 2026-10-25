# CFMAR04

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### IS IT DSU HARD!!

You might hear about Disjoint Set Union,click here for more info. Question is, You are given a list of $N$ words (strings containing only lower case English alphabet). Let's say two words are equivalent if one word can be obtained by rearranging the letters of another word. Your task is, form sets equivalent words and print the size of the $largest$ set.

### Input:
- First-line will contain $N$, the number of words.
- The next $N$ line contains a string.
### Output:

Output the size of the $largest$ subset of equivalent words.

### Constraints
- $1 \leq N \leq 10^5$
- $1 \leq |S| \leq 10^5$
- $$ \begin{equation} \sum_{i=1}^{N}|S| \leq 10^6 \end{equation} $$
### Sample 1:
Input
Output

```
4
aaa
aba
aab
aca

```

```
2
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T09:30:51.767Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Map to store: { sorted_string -> count }
    unordered_map<string, int> group_counts;
    int max_size = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        // 1. Sort the string to get its unique anagram signature
        sort(s.begin(), s.end());

        // 2. Increment the frequency of this signature in our map
        group_counts[s]++;

        // 3. Keep track of the largest group size seen so far
        max_size = max(max_size, group_counts[s]);
    }

    // Output the size of the largest group
    cout << max_size << "\n";

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CFMAR04)