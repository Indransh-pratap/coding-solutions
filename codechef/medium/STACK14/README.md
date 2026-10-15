# STACK14

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Next Smaller Element

Find the next smaller element for each element in an array. For each element, you need to find the next element to the right that is smaller than the current element.

Let's look at an example to understand it better. Consider an array A of integers:

A = [4, 2, 14, 7, 1, 9]

For each element, we want to find the immediate next smallest element. If there is no smaller element, we can use some kind of sentinel value, like -1 or None, to indicate that. Here's how we would solve this for array A:

- The next smallest element after 4 is 2.
- The next smallest element after 2 is 1.
- For 14, the next smallest element is 7.
- For 7, the next smallest element is 1.
- For 1, there is no smaller element, so we might say -1 or None.
- Likewise, for 9, the next smaller element is also -1 or None because there is no element after it, and thus no smaller element.

Thus, after solving the problem for array A, we'd have the result:

[2, 1, 7, 1, -1, -1]

### Task
- Given an integer n, the length of an array
- In the next line you are given n integers, elements of the array.
- Print the next smallest value for each element of the array. If there does not exist a next smaller element, print -1.
### Sample 1:
Input
Output

```
5
1 3 5 1 3
```

```
-1 1 1 -1 -1 
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-15T06:46:49.030Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int n;
    cin >>n ;
    vector < int > arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector < int > nse(n, -1);

    stack < int > st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[i] < arr[st.top()]) {
           nse[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);

    }
    
    for(int i=0; i<n; i++){
        cout<<nse[i]<<" ";
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/STACK14)