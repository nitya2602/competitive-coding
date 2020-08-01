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
    int getDecimalValue(ListNode* head) {
        deque<int> num;
        int n=0, sum=0, mul;
        while(head!=NULL)
        {
            num.push_front(head->val);
            head = head->next;
        }
        for(int i=0; i<num.size(); i++)
        {
            mul=pow(2, n);
            n++;
            sum+=mul*num[i];
        }
        return sum;
    }
};
