class Solution {
public:
    #define ll long long
    
    
    int dp[1001];
    long long MOD = 1e9 + 7;
    ll helper(int day ,int n  , int & delay , int & forget){
        if(dp[day]!=-1){
            return dp[day];
        }
        
        ll ans = 0;
        
        // he is the only one who knows the secret
        
        ans++;
        
        // do we need to add him it might be possible that today is the day when he forget the secret
        
        if(day + forget <=n){
            ans--;
        }
        
        
        // speading of secret
        for(int start = day+delay;start<min(day+forget  , n+1);start++){
            ans = ans + helper(start , n , delay , forget);
            ans%=MOD;
        }
        
        dp[day] = ans;
        return ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp , -1 , sizeof(dp));
        return helper(1 , n , delay , forget);
    }
};