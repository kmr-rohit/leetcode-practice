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
    int count(ListNode* head){
        int count =1;
        ListNode*temp = head;
        if(temp == NULL){
            return 0;
        }
        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        
        
        int size = count(temp);
        if(size ==1 && n ==1){
            return NULL;
        }
        if(size == n){
            head=head->next;
            return head;
        }
        if(size>1){
            if(temp->next!=NULL || temp->next->next != NULL){
            for(int i = 1 ; i<size-n ;i++){
            temp = temp->next;
        }
            temp->next = temp->next->next;
            
        }
            
        }
        
        
        
        return head;
    }
};