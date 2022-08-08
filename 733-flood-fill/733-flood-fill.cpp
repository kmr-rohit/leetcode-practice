class Solution {
public:
    void dfs(int i , int j , vector<vector<int>> &image  , int color , int finder){
        if(i<0 || j<0 || i == image.size() || j == image[0].size() || image[i][j] != finder || image[i][j] == color) return;
        image[i][j] = color;
        dfs(i+1, j , image  , color , finder);
        dfs(i, j+1 , image  , color , finder);
        dfs(i-1, j , image  , color , finder);
        dfs(i, j-1 , image  , color , finder);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr , sc , image , color , image[sr][sc]);
        return image;
    }
};