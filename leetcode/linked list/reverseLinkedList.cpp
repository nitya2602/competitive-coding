/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* pointer = head;
        vector<int> store;
        while(node!=NULL)
        {
            store.push_back(node->val);
            node = node->next;
        }
        
        int k = store.size()-1;
        while(pointer!=NULL)
        {
            pointer->val = store[k--];
            pointer = pointer->next;
        }
        return head;
    }
};
