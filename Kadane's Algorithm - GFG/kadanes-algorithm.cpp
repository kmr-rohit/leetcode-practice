// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        int global_sum = INT_MIN;
        int curr_sum = 0;
        int max_element = INT_MIN; // We need to track the max element in case when global sum is negative then
        // Max element is maximum sum.
        for(int i =0;i<n;i++){
            curr_sum = max(arr[i] , arr[i]+curr_sum);
            global_sum = max(curr_sum , global_sum);
            max_element = max(max_element , arr[i]);
        }
        
        return max(max_element , global_sum);
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends