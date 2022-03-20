class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        vector<int>temp;
        temp.push_back(1);
        vec.push_back(temp);
        temp.clear();
        for(int i =1 ; i<numRows ; i++){
          for(int j = 0 ; j<=i; j++){
            if(j == 0 || j == i){
              temp.push_back(1);
              

            }
            else{
              temp.push_back(vec[i-1][j-1] + vec[i-1][j]);
            }
 
          }
          vec.push_back(temp);
          temp.clear();
        }
      return vec;
    }
};