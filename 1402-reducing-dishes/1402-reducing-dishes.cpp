class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size(),ans=0;
        for(int i=n-2;i>=0;i--){
            arr[i]+=arr[i+1];
            if(arr[i]>0) ans+=arr[i];
            else break;
        }
        if(arr[n-1]>0) ans+=arr[n-1];
        return ans;
        
    }
};