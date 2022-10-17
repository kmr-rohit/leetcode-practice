class Solution {
public:
    bool checkIfPangram(string s) {
        map<char , int> m;
        
        for(int i = 0;i<s.size();i++){
            m[s[i]]++;
        }
        
        for(char i = 'a' ;i<='z';i++){
            if(m[i] == 0){
                return false;
            }
        }
        
        return true;
    }
};