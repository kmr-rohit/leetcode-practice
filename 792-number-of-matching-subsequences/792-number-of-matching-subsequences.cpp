// Brute - Force -- tle
// class Solution {
// public:
//     bool isSubsequence(int i , int j , string &s1 , string &s2 ,vector<vector<int>> &dp){
//         if(j == s2.size() ){
//             return true;
//         }
//         if(i==s1.size() && j!=s2.size()){
//             return false;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         if(s1[i] == s2[j]){
//             return dp[i][j] = isSubsequence(i+1 , j+1, s1 , s2 ,dp);
//         }
        
//         return dp[i][j] = isSubsequence(i+1 , j , s1 , s2 , dp);
        
        
//     }
//     int numMatchingSubseq(string s, vector<string>& words) {
        
//         int counter = 0;
//         for(auto it:words){
//             vector<vector<int>> dp(s.size()+1 , vector<int>(51 , -1));
//             if(isSubsequence(0 , 0 ,s  , it , dp)){
//                 counter++;
//             }
            
//         }
//         return counter;
//     }
// };


// Optimised - Use of maps

class Solution{
    public:
    
    
    int numMatchingSubseq(string s , vector<string> & words){
        vector<vector<int>> mappings(26);
        for(int i = 0;i<s.size();i++){
            mappings[s[i] - 'a'].push_back(i);
        }
        
        int ans = 0;
        for(auto word: words){
            bool found = true;
            for(int i = 0 , prev = -1;found && i<word.size();i++){
                auto& mapper = mappings[word[i]  - 'a'];
                auto it = upper_bound(mapper.begin() , mapper.end() , prev);
                if(it == mapper.end()){
                    found = false;
                }
                else{
                    prev = *it;
                }
            }
            ans = ans + found;
        }
        return ans;
    
    }
};

