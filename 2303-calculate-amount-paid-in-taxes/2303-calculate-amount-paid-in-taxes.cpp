class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0.00000;
        for(int i = 0;i<brackets.size();i++){
                    if(i == 0){
                        ans = ans + (min(brackets[i][0] , income) * brackets[i][1])/100.00000;
                        if(brackets[i][0] > income){
                            break;                       }
                    }
                    else{
                        ans = ans + ((min(income , brackets[i][0]) - brackets[i-1][0])*brackets[i][1])/100.00000;
                        if(brackets[i][0] > income){
                            break;                       }
                    }
                    
                
        }
        return ans;
    }
};