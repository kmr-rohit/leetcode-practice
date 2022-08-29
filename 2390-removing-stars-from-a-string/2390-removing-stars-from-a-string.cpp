class Solution {
public:
    string removeStars(string s) {
        deque<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '*'){
                st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.front();
            st.pop_front();
        }
        
        return ans;
    }
};