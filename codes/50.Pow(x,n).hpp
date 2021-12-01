/*
 * Question:
 * Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

namespace lc {

class Solution {
   public:
    double operator()(const double& x, const int& n) { return myPow(x, n); }

   private:
    double myPow(double x, int n) {
        long N = n;
        return N >= 0 ? Mult(x, N) : 1. / Mult(x, -N);
    }

    double Mult(double x, long n) {
        if (n == 0) return 1;
        if (n % 2)
            return Mult(x * x, n / 2) * x;
        else
            return Mult(x * x, n / 2);
    }
};

}  // namespace lc

#endif