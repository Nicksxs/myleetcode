class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // method 1
        // int d = INT_MAX;
        // while ((m & d) != (n & d)) {
        //     d <<= 1;
        // }
        // return m & d;
        
        // method 2
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};