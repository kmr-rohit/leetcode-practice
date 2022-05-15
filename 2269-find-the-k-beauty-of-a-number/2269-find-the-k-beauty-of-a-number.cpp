class Solution {
public:
    vector<string> split(string &s , int k){
    vector<std::string> substrings;
 
    for (size_t i = 0; i < s.size(); i +=1) {
        substrings.push_back(s.substr(i, k));
    }
 
    return substrings;
    }
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        vector<string> parts = split(s , k);
        for(int i = 0; i<parts.size();i++){
            cout<<parts[i]<<" ";
        }
        int count = 0;
        for(int i = 0;i<parts.size();i++){
            if(parts[i].size() == k){
                int temp = stoi(parts[i]);
                if(temp != 0 && num%temp == 0){
                    count++;
                }
            }
        }
        return count;
    }
};