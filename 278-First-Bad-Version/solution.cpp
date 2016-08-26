// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while(!isBadVersion(n-1)){
            n = n / 2;
        }
        return n;
    }
};