class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n , vector<int>(n , -1));
        int top = 0 , bottom = n-1 , left = 0 , right = n-1;
        int dir = 0;
        int k = 1;
        while(k<=n*n){
            if(dir == 0){
                for(int i = left ; i<=right ;i++){
                    ans[top][i] = k;
                    k++;
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top ; i<=bottom ;i++){
                  ans[i][right] =  k;
                    k++;
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right ; i>=left ;i--){
                    ans[bottom][i] = k;
                    k++;
                }
                bottom--;
            }
            else if(dir ==3){
                for(int i = bottom ; i>=top ;i--){
                    ans[i][left] = k;
                    k++;
                }
                left++;
                
            }
            dir = (dir+1)%4;
            
        }
        return ans;
    }   
    
};