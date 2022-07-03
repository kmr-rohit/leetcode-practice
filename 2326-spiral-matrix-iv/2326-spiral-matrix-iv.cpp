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
    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top = 0 , bottom = m-1 , left = 0 , right = n-1;
        int dir = 0;
        
        vector<vector<int>> ans(m , vector<int>(n , -1));
        ListNode* temp = head;
        while(temp){
            if(dir == 0){
                for(int i = left ; i<=right ;i++){
                    ans[top][i] = temp->val;
                    temp = temp->next;
                    if(temp == NULL){
                        break;
                    }
                    
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top ; i<=bottom ;i++){
                  ans[i][right] =  temp->val;
                    temp = temp->next;
                    if(temp == NULL){
                        break;
                    }
                    
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right ; i>=left ;i--){
                    ans[bottom][i] = temp->val;
                    temp = temp->next;
                    if(temp == NULL){
                        break;
                    }
                    
                }
                bottom--;
            }
            else if(dir ==3){
                for(int i = bottom ; i>=top ;i--){
                    ans[i][left] = temp->val;
                    temp = temp->next;
                    if(temp == NULL){
                        break;
                    }
                    
                }
                left++;
                
            }
            dir = (dir+1)%4;
            
        }
        return ans;
    }
};