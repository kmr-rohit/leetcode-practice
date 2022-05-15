class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        int j = 0,cover = 0,res = 0;
        sort(begin(tiles) , end(tiles));
        for(int i = 0; res<len && i<tiles.size();){
            if(j == i || tiles[j][0] + len > tiles[i][1]){
                cover += min(len , tiles[i][1]-tiles[i][0] + 1);
                res  = max(res , cover);
                ++i;
            }
            else{
                int partial = max(0 , tiles[j][0] + len - tiles[i][0]);
                res = max(res , cover + partial);
                cover -= (tiles[j][1] - tiles[j][0] + 1);
                ++j;
                
            }
        }
        return res;   
    }
};