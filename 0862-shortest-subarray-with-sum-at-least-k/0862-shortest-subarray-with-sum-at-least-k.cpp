class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans= n+1;
        
        vector<long long> sum(n+1);
        sum[0]=0;
        for(int i=0;i<n;i++)
            sum[i+1]= sum[i]+nums[i];
        
        deque<int> dq;
        
        for(int i=0;i<=n;i++){
            while(!dq.empty() && sum[i]- sum[dq.front()]>=k){
                ans= min( ans, i-dq.front());
                dq.pop_front();
            }
            
            while(!dq.empty() && sum[dq.back()]>= sum[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        return (ans==n+1)?-1:ans;
    }
};