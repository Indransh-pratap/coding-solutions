
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, int>> st;

        ListNode* curr = head;
        int idx = 0;

        while (curr != nullptr) {
            ans.push_back(0);

            while (!st.empty() && curr->val > st.top().first) {
                ans[st.top().second] = curr->val;
                st.pop();
            }

            st.push({curr->val, idx});
            curr = curr->next;
            idx++;
        }

        return ans;
    }
};
