class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        string *str = new string(len, '0');
        for(int i = n - 1; i > 0; i--){
            str[n-i-1] = s[i];
        }
        return *str;
    }
};