class Solution {
public:
   int longestPalindrome(vector<string>& w) {
        
        map<string, int> m;
        int res = 0;
        for(auto s : w){ 
            string t = s;
            reverse(t.begin(), t.end());
            if(m.count(t) != 0){  
                m[t]--;
                if(m[t] == 0) m.erase(t);   
                
                res += 4;
            }
            else m[s]++;
        }
        
        for(auto it : m){
            if(it.second>0) {
                string str = it.first;
                if(str[0] == str[1]){
                    res+=2;
                    break; 
                }                
            }
        }
        
        return res;
    }
};