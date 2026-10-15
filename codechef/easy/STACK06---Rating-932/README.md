# STACK06 - Rating 932

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Convert Decimal to Binary

Let's implement a stack using arrays to solve a classic problem: converting an integer from decimal to binary using the "divisor-remainder" method.

In this method, you repeatedly divide the decimal number by 2 and keep track of the remainders.
The remainders, when read from bottom to top, give you the binary representation of the number.

Update the code given in the IDE to solve this problem.

### Sample 1:
Input
Output

```
3
10
15
18
```

```
1010
1111
10010
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-15T05:49:20.165Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;

void push(int ele){
    if(top<=MAX_SIZE-1){
        a[++top]=ele;
    }
    else{
        cout<<"Stack is full. Cannot push: "<<ele<<"\n";
    }
}

int pop(){
    if(top>=0){
        int ele = a[top];
        top--;
        return ele;
    }
    else{
        cout<<"Stack is empty. Cannot pop.\n";
        return -1;
    }
}

bool isEmpty(){
    return top==-1;
}

int size(){
    return top+1;
}

void decimalToBinary(int decimal){
    while (decimal > 0) {
        // Update the code below
       
        int rem = decimal % 2;
        push(rem);
        decimal = decimal / 2;
    }
    while(!isEmpty()){
        cout<<pop();
    }

    cout<<"\n";
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int decimal;
        cin>>decimal;
        decimalToBinary(decimal);
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/STACK06)