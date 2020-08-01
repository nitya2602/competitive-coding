//using temp only increses running time that overpowers reduction in space comsumption

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int> aux;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* temp = l1;
        while(temp!=NULL)
        {
            aux.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* temp1 = l2;
        while(temp1!=NULL)
        {
            aux.push_back(temp1->val);
            temp1 = temp1->next;
        }
        sort(aux.begin(), aux.end());
        ListNode* head = new ListNode(aux[0]);
        ListNode* temp2 = head;
        for(int i=1; i<aux.size(); i++)
        {
            ListNode* node = new ListNode(aux[i]);
            head->next = node;
            head = head->next;
        }
        return temp2;
    }
};
