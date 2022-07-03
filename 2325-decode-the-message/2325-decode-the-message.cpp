class Solution {
public:
    string decodeMessage(string key, string mess) {
    char m[128] = {}, cur = 'a';
    for (char k : key)
        if (isalpha(k) && m[k] == 0)
            m[k] = cur++;
    for (int i = 0; i < mess.size(); ++i)
        mess[i] = m[mess[i]] ?: mess[i];
    return mess;
}
    
};