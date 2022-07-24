class Solution {
public:
    #define ll long long 
    ll calculation(ll n){
        if(n == 0){
            return 0;
        }
        return (n*(n+1)/2);
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0;
        int j = 0;
        int i = 0;
        while(j<nums.size()){
            if(nums[j] == 0 ){
                if(j == nums.size()-1){
                    ans = ans + calculation(j-i+1);
                }
                j++;  
            }
            else{
                ans = ans + calculation(j-i);
                j++;
                i = j;
                
            }
            
           
        }
        return ans;
    }
};