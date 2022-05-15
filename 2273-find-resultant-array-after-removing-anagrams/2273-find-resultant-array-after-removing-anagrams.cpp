class Solution {
public:
    bool anagrams(string &s1 , string &s2){
        map<char,int> m1;
        bool res = false;
        for(int i = 0;i<s1.size();i++){
            m1[s1[i]]++;
        }
        for(int i = 0;i<s2.size();i++){
           m1[s2[i]]--;
        }
        
        for(auto x: m1){
            if(x.second != 0){
                res = false;
                break;
            }
            else{
                res = true;
            }
        }
        return res;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        
        for(int i = 1;i<words.size();i = i+1){
            
            if(anagrams(words[i-1], words[i])){
                words.erase(words.begin()+i);
                i--;
            }
            
        }
        
        return words;
        
    }
};