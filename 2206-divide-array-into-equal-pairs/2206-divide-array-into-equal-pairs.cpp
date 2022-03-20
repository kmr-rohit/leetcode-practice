class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int flag = 0;
      int sum = 0;
        map<int ,int> m;
        for(auto x : nums){
            m[x]++;
        }
      
       for(auto i:m){
         sum = sum + i.second/2;
         
       }
      cout<<sum;
        for(auto i:m){
          
          
            if(i.second % 2 == 0 && sum == nums.size()/2){
            flag = 1;
            
          }
          else{
            flag = 0;
            
          }
        }
          
       
        
      
      if(flag ==1){return true;}
      else {return false;}
      
      
        
    }
};