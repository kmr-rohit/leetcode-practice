class Solution {
public:
    int reverse(int x) {
        int neg = bool(false);
        int rev  = 0;
        if (x<0){
            neg = bool(true);
            x = abs(x);
        }
        while(x!=0){
            int digits = x%10;
            if ((rev<INT_MIN/10)||(rev>INT_MAX/10)){
            return 0;
        }
            rev = rev*10+digits;
            x = x/10;
        }
        
       
        if (neg==bool(true)){
            return rev*-1;
        }
        else{
            return rev;
        }
    }
};