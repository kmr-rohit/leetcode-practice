class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        //Use of Monotonic Stack
        stack<pair<int, int>> s;
        vector<int> res(h.size() , 0);
        for(int i = 0;i<h.size();i++){
          while(!s.empty() && s.top().first <= h[i]){
            res[s.top().second]++;
            s.pop();
          }
          
          if(!s.empty()){
            res[s.top().second]++;
          }
          s.push({h[i] , i});
        }
      return res;
    }
};