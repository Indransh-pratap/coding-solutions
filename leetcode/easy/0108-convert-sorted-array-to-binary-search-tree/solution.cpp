class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Handle the base case for an empty array
        if (nums.empty()) return nullptr;
        
        // Call the recursive helper function with the full array range
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        // Base case: if the left index crosses the right index, there are no elements left
        if (left > right) return nullptr;
        
        // Choose the middle element to maintain balance
        int mid = left + (right - left) / 2;
        
        // Create the root node with the middle value
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }
};
