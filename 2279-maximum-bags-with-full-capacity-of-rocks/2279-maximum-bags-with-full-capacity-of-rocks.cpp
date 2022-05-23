class Solution {
public:
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
//         for(int i = 0;i<capacity.size() ;i++){
//             if(capacity[i] > rocks[i] && additionalRocks > 0){
//                 if(additionalRocks >= capacity[i] - rocks[i]){
//                     additionalRocks = additionalRocks - (capacity[i] - rocks[i]);
//                     rocks[i] = capacity[i];
//                 }
//       .000          else if(additionalRocks < capacity[i] - rocks[i]){
//                      rocks[i] = rocks[i] + additionalRocks;
//                 }
                
//             }
//         }
        
//         int fullcount = 0;
//         for(int i = 0;i<rocks.size();i++){
//             if(rocks[i] == capacity[i]){
//                 fullcount++;
//             }
//         }
//         return fullcount;
        int n = capacity.size();
        int count = 0;
        vector<int> diffarr(n);
        for(int i = 0;i<n;i++){
            diffarr[i] = capacity[i] - rocks[i];
        }
        sort(diffarr.begin() , diffarr.end() );
        for(int i = 0;i<n;i++){
            if(additionalRocks>0){
                if(diffarr[i] == 0){
                    count++;}
                else{
                    if(additionalRocks - diffarr[i] >= 0){
                       additionalRocks = additionalRocks - diffarr[i];
                count++; 
                    }
                        
                }
                
            }
        }
        return count;
    }
}; 