class Solution {
public:
    vector<int> solvearray(vector<int> &arr , int n){
        int newarr[n*n];
        for(int i = 0; i<arr.size();i++){
            if(i%n == 0){
                int y = n-1 -(i)/n;
                newarr[y] = arr[i];
            }
            else if(i%n != 0){
                int x=n*(i%n) + (n*n - i)/n;
                newarr[x] = arr[i];
            }
        }
        vector<int> temp;
        for(int i = 0; i<n*n;i++){
            temp.push_back(newarr[i]);
        }
        return temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> temp;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n ;j++){
                temp.push_back(matrix[i][j]);
            }
        }
        vector<int> newarr = solvearray(temp , n);
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<n;j++){
                matrix[i][j] = newarr[n*i + j%n];
            }
        }
    }
};