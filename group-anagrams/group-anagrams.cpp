class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string tmp;
        vector<vector<string>> res;
        unordered_map<string, int> um;
        for (auto str: strs)
        {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if (um[tmp]>0)                      //anagram group of current string already exists in the array
            {
                res[um[tmp]-1].push_back(str);
            }
            else
            {
                res.push_back({str});
                um[tmp] = res.size();           //store index of new anagram group array in map
            }
            
        }
                
        return res;
    }
};