class Solution {
public:
    vector<int> counter;
     int solve(vector<int> &v){
         int res = 0;
        for(int i = 0;i<v.size()-1;i++){
            res = res + v[i]*v[i+1];
        }
         return res; 
    }
     int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        for(int i = 0;i<m;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                
                if(bank[i][j] == '1'){
                    count++;
                }
                
            }
            if(count>0){
                counter.push_back(count);
            }
            
        }
        if(counter.size()>1){
            return solve(counter);
        }
         else{
             return 0;
         }
        
    }
};