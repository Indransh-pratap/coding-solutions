#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
  int n;
    cin >> n; // Number of characters in the RPN string
    
    string s;
    cin >> s; // The RPN string itself
    
    stack<long long> st; // Use long long to prevent integer overflow during multiplications
    
    for (char ch : s) {
        if (isdigit(ch)) {
            // Convert character digit '1'-'9' to integer and push
            st.push(ch - '0'); 
        } 
        else {
            // Operator encountered: pop the top two elements
            long long op2 = st.top(); st.pop(); // Second operand
            long long op1 = st.top(); st.pop(); // First operand
            
            if (ch == '+') {
                st.push(op1 + op2);
            } 
            else if (ch == '-') {
                st.push(op1 - op2);
            } 
            else if (ch == '*') {
                st.push(op1 * op2);
            }
        }
    }
    // The final remaining element in the stack is the evaluation result
    cout << st.top() << "\n";
}
}

