

class Solution {
public:
    
    
   
    string say(int n){
        
        if(n == 1){
            return "1";
        }
        
        string s = say(n-1);
        string ans = "";
        
        for(int i = 0; i<s.size(); i++){
            int count = 1;
            while(i < (s.size() - 1) and (s[i] == s[i + 1])){
                i++;
                count++;
            }
            ans.append(to_string(count) + s[i]);
        }
        cout<<ans<<endl;
        return ans;
    }
    
    
    string countAndSay(int n) {
        
        
        return say(n);
      
    }
};