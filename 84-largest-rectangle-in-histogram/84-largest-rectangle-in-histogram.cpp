// Brute force Approach   : Is to iterate through the array , at any idx we have to run two for loops one to left and one to right to find smallest no in left and right tc - o(n^2)

// Optimal : Using Monotonik Stack - creating leftSmall and rightSmall array and a stack to keep track of linearly increasing rectangles and determining the boundaries TC: O(2n) , SC: 0(3n);

    // Code : 
// int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         stack<int> s;
//         int leftSmall[n] , rightSmall[n];
        
//         for(int i = 0;i<n;i++){
//             while(!s.empty() && heights[s.top()] >= heights[i]){
//                 s.pop(); // poping indx at which rectangle is greater as it does not decide boundaries(heights);
                
//             }
//             if(s.empty()){
//                 leftSmall[i] = 0;
//             }
//             else{
//                 leftSmall[i] = s.top()+1;
               
//             }
//              s.push(i);
//         }
        
//         // Clear the stack for reusing for rightSmall Array
//         while(!s.empty()) s.pop();
        
//         // For rightSmall 
//         for(int i = n-1;i>=0;i--){
//             while(!s.empty() && heights[s.top()] >= heights[i]){
//                 s.pop(); // poping indx at which rectangle is greater as it does not decide boundaries(heights);
                
//             }
//             if(s.empty()){
//                 rightSmall[i] = n-1;
//             }
//             else{
//                 rightSmall[i] = s.top()-1;
               
//             }
//              s.push(i);
//         }
//         int maxA = 0;//Track for area maximisation 
//         for(int i = 0;i<n;i++){
//             maxA  = max(maxA  ,(rightSmall[i] - leftSmall[i]+1)*heights[i]);
            
//         }
        
//         return maxA;
        
//     }



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxA = 0;
        for(int i = 0 ; i<=n;i++){
            while(!s.empty() && (i == n || heights[s.top()]>= heights[i])){
                int height = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()){
                    width  = i;
                }
                else{
                    width = i - s.top() - 1;
                   
                }
                 maxA = max(maxA , width*height);
                
            }
            s.push(i);
        }
        return maxA;
        
    }
};