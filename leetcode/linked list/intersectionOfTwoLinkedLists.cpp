/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa!=NULL)
        {
            countA++;
            pa = pa->next;
        }
        while(pb!=NULL)
        {
            countB++;
            pb = pb->next;
        }
        pa = headA;
        pb = headB;
        if(countA > countB)
        {
            int diff = countA - countB;
            for(int i = 0; i<diff; i++)
            {
                pa = pa->next;
            }
            while(pa!=pb)
            {
                pa = pa->next;
                pb = pb->next;
            }
            return pa;
        }
        if(countB >= countA)
        {
            int diff = countB - countA;
            for(int i = 0; i<diff; i++)
            {
                pb = pb->next;
            }
            while(pa!=pb)
            {
                pa = pa->next;
                pb = pb->next;
            }
            return pb;
        }
        return NULL;
    }
};
