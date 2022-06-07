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

    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL ){
            return NULL;
        }
        if(head->next->next == NULL){
            head->next = head->next->next;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp;
        while(fast->next != NULL){
            temp = slow;
            slow = slow->next;
            if(fast->next->next != NULL){
                 fast = fast->next->next;
            }
            else{
                fast = fast->next;
            }
           
        }
        if(slow->next != NULL){
            temp->next = slow->next;
        }
        
        return head;
    }
};