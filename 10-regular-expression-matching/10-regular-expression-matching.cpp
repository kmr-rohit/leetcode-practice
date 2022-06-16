//Recursive Solution
// class Solution {
// public:
//     bool util(string s, string p, int n, int m){
// 	// if both the string have reached their end, then p must be in s
//     if(n <= -1 && m <= -1)
//         return true;

// 	/* if the second last element is '*' then also we can call it a match, as given in the question, 
// 		we can have 0 occurences of the previous element */
//     if(n == -1 && p[m] == '*')
//         return util(s, p, n, m-2);
	
// 	// even now if element's are left in s or p, then return false
//     if(n == -1 || m == -1)
//         return false;
	
// 	// if elements are same the skip it, cause it exists in both of them
//     if(s[n] == p[m]){
//         return util(s, p, n-1, m-1);
//     }
//     else{
// 		// as it is given , when we encounter '*', we can choose 0 or n number of previous element
//         if(p[m] == '*'){
//             if(s[n] == p[m-1] || p[m-1] == '.'){
//                 return (util(s, p, n-1, m) || util(s, p, n, m-2));
//             }
//             else{
//                 return util(s, p, n, m-2);
//             }
//         }
// 		// when encountering '.' we can skip 1 element
//         else if(p[m] == '.'){
//            return util(s, p, n-1, m-1);
//         }
//         else
//             return false;
//     }
// }

// bool isMatch(string s, string p) {
//     return util(s, p, s.length()-1, p.length()-1);
// }
// };

class Solution{
    public:
    unordered_map<string, int> dp;
bool util(string s, string p, int n, int m){
    string key = to_string(n) + to_string(m);

    if(n <= -1 && m <= -1)
        return true;

    if(n == -1 && p[m] == '*')
        return util(s, p, n, m-2);

    if(n == -1 || m == -1)
        return false;

    if(dp.count(key))
        return dp[key];

    if(s[n] == p[m]){
        dp[key] = util(s, p, n-1, m-1);
    }
    else{
        if(p[m] == '*'){
            if(s[n] == p[m-1] || p[m-1] == '.'){
                dp[key] = (util(s, p, n-1, m) || util(s, p, n, m-2));
            }
            else{
                dp[key] = util(s, p, n, m-2);
            }
        }
        else if(p[m] == '.'){
            dp[key] = util(s, p, n-1, m-1);
        }
        else
            dp[key] = false;
    }

    return dp[key];
}

bool isMatch(string s, string p) {
    return util(s, p, s.length()-1, p.length()-1);
}
    
    
};