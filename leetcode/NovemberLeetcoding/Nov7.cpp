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

//without modifying the original lists
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l2 == NULL)
            return l1;
        if(l1 == NULL)
            return l2;
        stack<ListNode*> stack1, stack2, ans;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        while(head1 != NULL)
        {
            stack1.push(head1);
            head1 = head1 -> next;
        }
        while(head2 != NULL)
        {
            stack2.push(head2);
            head2 = head2 -> next;
        }
        int carry = 0;
        while(!stack1.empty() && !stack2.empty())
        {
            ListNode* result = new ListNode();
            int sum = stack1.top()->val + stack2.top()->val + carry;
            result -> val = sum%10;
            carry = sum/10;
            result -> next = NULL;
            stack1.pop();
            stack2.pop();
            ans.push(result);
        }
        if(stack1.empty() && !stack2.empty())
        {
            while(!stack2.empty())
            {
                ListNode* result = new ListNode();
                int sum = stack2.top() -> val + carry;
                carry = sum/10;
                result -> val = sum%10;
                stack2.pop();
                ans.push(result);
            }
        }
        else if(stack2.empty() && !stack1.empty())
        {
            while(!stack1.empty())
            {
                ListNode* result = new ListNode();
                int sum = stack1.top() -> val + carry;
                carry = sum/10;
                result -> val = sum%10;
                stack1.pop();
                ans.push(result);
            }
        }
        if(carry != 0)
        {
            ListNode* result = new ListNode();
            result -> val = carry;
            ans.push(result);
        }
        ListNode* head = ans.top();
        ans.pop();
        ListNode* result = head;
        while(!ans.empty())
        {
            head -> next = ans.top();
            head = head -> next;
            ans.pop();
        }
        return result;
    }
};