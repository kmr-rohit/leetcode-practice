class Solution {
public:
    void solve(int idx, int n, int k, int num, vector<int>&ans){
    
    if(idx==n){
        if(ans.empty() || ans.back()!=num){  //To avoid duplicate answers when lastDigit-k == lastDigit+k
            ans.push_back(num);
        }
        return;
    }    
    
    int lastDigit = num%10;
    
    if(lastDigit+k < 10){                                     //if lastDigit + k < 10
        solve(idx+1,n,k, num*10 + (lastDigit+k), ans);    
    }
    if(lastDigit-k >= 0){                                     //if lastDigit - k >= 0
        solve(idx+1,n,k, num*10 + (lastDigit-k), ans);
    }
    
    return;
}

vector<int> numsSameConsecDiff(int n, int k) {
    
    vector<int>ans;
    
    for(int i=1;i<10;i++){     // Beginning from 1 to avoid any leading zeros i.e. from 1 to 9
        solve(1,n,k,i,ans);
    }
    return ans;
}
};