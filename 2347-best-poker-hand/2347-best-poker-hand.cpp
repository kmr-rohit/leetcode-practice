class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int , int > m;
        map<char , int > m2;
        
        for(auto &it : ranks){
            m[it]++;
        }
        for(auto &it : suits){
            m2[it]++;
        }
        
        for(auto x:m2){
            if(x.second == 5){
                return "Flush";
            }
        }
        
        for(auto x:m){
            if(x.second >= 3){
                return "Three of a Kind";
            }
        }
        for(auto x:m){
            if(x.second >= 2){
                return "Pair";
            }
        }
        return "High Card";
    }
};