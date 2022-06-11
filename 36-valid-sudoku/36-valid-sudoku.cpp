class Solution {
public:
    bool count ( vector<char> &v){
        map<char , int> m;
        for(char c : v){
            m[c]++;
        }
        for(auto x:m){
            if(x.second > 1){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                bool ans = true;
                vector<char> row;
                vector<char> col;
                vector<char> grid;
                
                for(int k = 0;k<9;k++){
                    if(board[i][k] != '.'){
                      row.push_back(board[i][k]);
                    }
                    if(board[k][j] != '.'){
                        col.push_back(board[k][j]);
                    }
                }
                
                if(i/3 == 0 && j/3 == 0){
                    for(int p = 0;p<3;p++){
                        for(int k = 0;k<3;k++){
                            if(board[p][k] != '.'){
                                grid.push_back(board[p][k]);
                            }
                        }
                    }
                }
                else if(i/3 == 0 && j/3 != 0){
                    for(int p = 0;p<3;p++){
                        for(int k = j - j%3;k<j - j%3 + 3;k++){
                            if(board[p][k] != '.'){
                                grid.push_back(board[p][k]);
                                
                            }
                        }
                    }
                }
                else if(i/3 != 0 && j/3 == 0){
                    for(int p = i-i%3;p<i- i%3 +3;p++){
                        for(int k =0;k<3;k++){
                            if(board[p][k] != '.'){
                                grid.push_back(board[p][k]);
                            }
                        }
                    }
                }
                else{
                    for(int p = i-i%3;p<i- i%3 +3;p++){
                        for(int k = j - j%3;k<j - j%3 + 3;k++){
                            if(board[p][k] != '.'){
                                grid.push_back(board[p][k]);
                            }
                        }
                    }
                }
                
                ans = (count(row)&&count(col))&&count(grid);
                if(ans == false){
                    return ans;
                }
                
            }
        }
        return true;
        
    }
};

