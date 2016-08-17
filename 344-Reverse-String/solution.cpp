class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
	    string str(len, '0');
	    for (int i = (len - 1); i >= 0; i--) {
			str[len - i - 1] = s[i];
	    }
        return str;
    }
};