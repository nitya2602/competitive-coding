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
/*
for j = 2 to A.length
    key = A[j]
    i = j - 1;
    while i > 0 && A[i] > key
        A[i+1] = A[i]
        i = i -1 
    A[i+1] = key
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* loop = head -> next;
        ListNode* prev1 = head;
        while(loop != NULL)
        {
            int key = loop -> val;
            ListNode* _head = head;
            ListNode* prev = NULL;
            while(_head != NULL && _head != loop && key > _head -> val)
            {
                prev = _head;
                _head = _head -> next;
            }
            if(_head == NULL) break;
            if(_head == loop)
            {
                prev1 = loop;
                loop = loop -> next;
                continue;
            }
            if(prev == NULL)
            {
                prev1 -> next = loop -> next;
                loop -> next = _head;
                head = loop;
                loop = prev1 -> next;
            }
            else
            {
                prev -> next = loop;
                prev1 -> next = loop -> next;
                loop -> next = _head;
                loop = prev1 -> next;
            }
        }
        return head;
    }
};