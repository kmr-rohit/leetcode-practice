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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        queue<int> q1;
        queue<int> q2;
        if(head == NULL || head->next == NULL){
            return head;
        }
        while(temp->next!= NULL){
            if(temp->val < x){
                q1.push(temp->val);
            }
            else{
                q2.push(temp->val);
            }
            temp = temp->next;
        }
        if(temp->val<x){
            q1.push(temp->val);
        }
        else{
            q2.push(temp->val);
        }
        temp = head;
        
        while(temp->next != NULL){
            if(!q1.empty()){
                swap(temp->val  , q1.front());
                q1.pop();
            }
            else{
                swap(temp->val  , q2.front());
                q2.pop();
            }
            temp = temp->next;
        }
        if(!q1.empty()){
            swap(temp->val , q1.front());
        }
        else{
            swap(temp->val , q2.front());
        }
        
        return head;
        
        
    }
};