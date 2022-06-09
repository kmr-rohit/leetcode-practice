class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n =numbers.size();
        int low = 0;
        int high =  n-1;
        vector<int> t;
        while(low<high){
            if(numbers[low] + numbers[high] == target){
                t.push_back(low+1);
                t.push_back(high+1);
                break;
            }
            else if(numbers[low] + numbers[high] < target){
                low++;
            }
            else{
                high--;
            }
        }
        return t;
    }
};