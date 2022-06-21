// Recursion Method
//     int help(int i , vector<int> &h , int bricks , int ladders){
        
        
//         // Base Case 
//         if(i>=h.size()-1){
//             return h.size()-1;
//         }
//         if(h[i+1]-h[i]>bricks && ladders == 0){
//             return i;
//         }
        
//         if(h[i+1]<= h[i]){
//             return help(i+1 , h , bricks , ladders);
//         }
//         else{
//             int ladder = INT_MIN;
//             int brick = INT_MIN;
//             if(h[i+1]-h[i]<bricks){
//                 brick = help(i+1 , h , bricks-(h[i+1]-h[i]) , ladders);
//             }
//             if(ladders>0){
//                 ladder = help(i+1 , h ,bricks , ladders-1);
//             } 
//             return max(brick , ladder);
//         }
        
        
//     }
// Idea is to use Bricks for smaller Diffrences and Ladders for larger diffrence 
// Using a max heap to storing the diffrence 
// if its size is more than ladders we would use bricks then
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = heights.size();
        int brickSum = 0;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if(diff <= 0) continue;
            
            pq.push(diff);
            if(pq.size() > ladders) {
                brickSum += pq.top();
                pq.pop();
            }   
            if(brickSum > bricks) return i - 1;
        }
        return n-1;    
    }
};