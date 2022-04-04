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
    ListNode* swapNodes(ListNode* head, int k) {
        int t=k-1;
        ListNode* T=head;
        while(t--)T=T->next;
        ListNode *T1=T,*T2=head;
        while(T1->next){T1=T1->next;T2=T2->next;}
        t=T2->val;
        T2->val=T->val;
        T->val=t;
        return head;
    }
};