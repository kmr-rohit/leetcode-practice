class Solution {
public:
  double myPow(double x, int n) {
    // base conditions
    if (!n) {
      return 1;
    } else if (n == 1) {
      return x;
    } else if (n == -1) {
      return 1 / x;
    }
    double power = myPow(x, n / 2);
    double base = (n > 0) ? x : 1 / x;

    if (n % 2 == 0) { // if n is even, just multiplying the powers would do
      return power * power;
    } else { // if n is odd, multiplying the powers and then multiplying the base (x) or 1 / x would suffice
      return power * power * base;
    }
  }
};