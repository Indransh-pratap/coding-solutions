# STACT10

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Next Greater Element Algorithm

The algorithm typically uses a stack data structure to keep track of the elements greater than current element.

- Initialize an empty stack
- Iterate through the array from right to left: Start from the rightmost element of the array and move towards the left.
- Pop elements from the stack: For each element in the array, pop elements from the stack until the stack is empty or the element at the top of the stack is greater than the current array element.
- Find the Next Greater Element (NGE): If the stack is empty, there is no NGE for the current element, otherwise the top of the stack is NGE for current element.
- Push the current element: Push the current element on the stack as it can be NGE for the remaining elements.

Example: Consider the array [4, 5, 2, 10, 8].
Length of the array is 5, thus the last index is 4.

- Start from the right:

index = 4
element = 8
stack = []

For 8, the stack is empty. So, the NGE for 8 is -1. `nge[4] = -1`
Push 8 onto the stack.

- Move to the next element (10):

index = 3
element = 10
stack = [8]

Pop 8 from the stack since 8 is smaller than 10.
The stack will become empty. NGE for 10 is -1. `nge[3] = -1`
Push 10 onto the stack.

- Move to the next element (2):

index = 2
element = 2
stack = [10]

The top of the stack (10) is greater than 2. No need to pop.
The NGE for 2 is 10. `nge[2] = 10`
Push 2 onto the stack.

- Move to the next element (5):

index = 1
element = 5
stack = [10, 2]

Pop 2 from the stack since 2 is smaller than 5.
The next element in stack is 10, which is greater than 5. No need to pop.
The NGE for 5 is 10. `nge[1] = 10`
Push 5 onto the stack.

- Move to the last element (4):

index = 0
element = 4
stack = [10, 5]

The top of the stack (5) is greater than 4. No need to pop.
The NGE for 4 is 5. `nge[0] = 5`
Push 4 onto the stack.

The resulting NGE array is [5, 10, 10, -1, -1]. This array represents the next greater element for each element in the original array.

### Task
- Given the implementation of NGE with some missing blank, fill the missing code.
### Sample 1:
Input
Output

```
4 
4 5 2 25
```

```
5 25 25 -1
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-15T06:25:58.494Z  

```c_cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> stack;

    // Initialize the NGE array
    vector<int> nge(n, -1);

    // Iterating the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop till the top element is smaller than current
        while (!stack.empty() && stack.top() < arr[i]) {
           stack.pop();
        }

        if (!stack.empty()) {
            nge[i] = stack.top();
           
        } else {
            nge[i] = -1;
        }

        // Push the current element to stack
        stack.push(arr[i]);
    }

    // Print the NGE array
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/STACT10)