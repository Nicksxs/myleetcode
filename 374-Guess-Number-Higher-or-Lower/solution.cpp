// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return bsearch(n, 1, n);
    }
private:
    int bsearch(int n, int start, int end){
        if(start > end) return -1;
        if(guess(start)==0) return start;
        if(guess(end)==0) return end;
        int mid = start + (end - start)/2;
        if(guess(mid)==0) return mid;
        else if(guess(mid)==-1) return bsearch(n, start+1, mid-1);
        else return bsearch(n, mid+1, end-1);
    }
};