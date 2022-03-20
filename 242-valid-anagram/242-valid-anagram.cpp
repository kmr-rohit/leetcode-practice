class Solution {
public:
    bool isAnagram(string s, string t) {
      int flag = 0;
      map<char ,int> M;
      for(auto x : s){
        M[x]++;
      }
      
      for(auto y:t){
        M[y]--;
      }
      for(auto i : M){
        cout<<i.first<<" -> "<<i.second<<" ";
      }
      for(auto i:M){
        flag = flag + abs(i.second);
      }
      if(flag == 0){
        return true;
        
      }
      else{
        return false;
      }
      
      
    }
};