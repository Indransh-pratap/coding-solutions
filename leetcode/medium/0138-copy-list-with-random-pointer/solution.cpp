/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
          if (head == NULL) return NULL;

    unordered_map<Node*, Node*> mp;
    Node* curr = head;

    // Step 1: Create copies of all nodes
    while (curr != NULL) {
        mp[curr] = new Node(curr->val);
        curr = curr->next;
    }

    // Step 2: Connect next and random pointers
    curr = head;
    while (curr != NULL) {
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }

    // Return the head of the deep-copied list
    return mp[head];
    }
};