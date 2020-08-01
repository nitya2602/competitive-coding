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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        vector<int> store;
        
        //store first half of the linked list in a vector
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            store.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(store.size()==0)
            store.push_back(slow->val);
        
        //for odd number of nodes
        else if(fast->next==NULL)
        {}
        
        //for even number of nodes
        else
            store.push_back(slow->val);
        int k = store.size()-1;
        
        //traverse the linked list further while comparing with vector
        //elements in reverse order
        while(slow->next!=NULL)
        {
            slow = slow->next;
            if(slow->val!=store[k--])
                return false;
        }
        
        //one last comparision may be required
        if(k>=0 && slow->val!=store[k])
            return false;
        return true;
    }
};
