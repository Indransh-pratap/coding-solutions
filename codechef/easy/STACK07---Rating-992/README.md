# STACK07 - Rating 992

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Practice problem - Transform the Expression

Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands. For instance, to add three and four, one would write "3 4 +" rather than "3 + 4". If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 − 4 + 5" would be written "3 4 − 5 +" first subtract 4 from 3, then add 5 to that.

Reverse polish notations are easier to parse for computers and you don't need parentheses to denote precedence of operations.

Transform the algebraic expression with brackets into RPN form.

You can assume that for the test cases below only single letters will be used, brackets [] will not be used and each expression has only one RPN form (no expressions like a *b* c)

### Input Format
- The first line contains t, the number of test cases (less then 100).
- Followed by t lines, containing an expression to be translated to RPN form, where the length of the expression is less then 400.
### Output Format

The  *expression* s in RPN form, one per line.

### Sample 1:
Input
Output

```
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

```

```
abc*+
ab+zx+*
at+bac++cd+^*

```

### Explanation:

 **Test case 1: `(a+(b*c))`** 

- Start with innermost brackets: b *c becomes bc*.
- Replace (b *c) in the original expression: it becomes (a+bc*).
- Process the addition: a+bc *becomes abc* +. Result: abc*+.

 **Test case 2: `((a+b)*(z+x))`** 

- Start with the first set of brackets: a+b becomes ab+.
- Process the second set of brackets: z+x becomes zx+.
- Combine with the multiplication: (ab+) *(zx+) becomes ab+zx+*. Result: ab+zx+*.

 **Test case 3: `((a+t)*((b+(a+c))^(c+d)))`** 

- Start with the innermost brackets: a+c becomes ac+. b+(a+c) becomes bac++.
- Process the next set of brackets: bac++^(c+d): c+d becomes cd+. bac++^cd+ combines to bac++cd+^.
- Finally, handle the outermost multiplication: (a+t) becomes at+, so (at+) *(bac++cd+^) becomes at+bac++cd+^*. Result: at+bac++cd+^*

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-15T06:04:17.796Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here

    int t;
    cin >> t;

    while (t--) {
        string exp;
        cin >> exp;

        stack < char > st;

        string ans;

        for (char ch: exp) {
            if (ch == '(') {
                continue;
            }

            else if (isalpha(ch)) {
                // If it is an operand (a-z), append it directly to the answer
                ans += ch;
            }


            else if (ch == ')' && !st.empty()) {
                ans += st.top();
                st.pop();
            }

            else {
                st.push(ch);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/STACK07)