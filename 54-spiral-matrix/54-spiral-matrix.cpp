class Solution {
public:
    //Basic idea is to take four pointers denoting top & bottom row and left & right coloumn
    // We will use a variable called direction for denoting traversal direction 
    // initialize dir == 0 ( 0 = left->right , 1 = top->bottom , 2 = right ->left , 3 = bottom          ->top)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int  m = matrix.size();
        int n = matrix[0].size();
        vector<int>ans;
        int top = 0 , bottom = m-1 , left = 0 , right = n-1;
        int dir = 0;
        
        while(top<=bottom && left<=right){
            
            if(dir == 0){
                for(int i = left ; i<=right ;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top ; i<=bottom ;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right ; i>=left ;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if(dir ==3){
                for(int i = bottom ; i>=top ;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                
            }
            dir = (dir+1)%4;
            
        }
        return ans;
    }
};