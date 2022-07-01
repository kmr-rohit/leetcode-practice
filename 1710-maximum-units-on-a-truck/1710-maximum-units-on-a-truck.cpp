class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , comp);
        int ans = 0;
        for(int i = 0;i<boxTypes.size();i++){
            ans = ans + min(boxTypes[i][0] , truckSize)*boxTypes[i][1];
            truckSize = truckSize - min(boxTypes[i][0] , truckSize);
            if(!truckSize){
                break;
            }
        }
        return ans;
    }
};