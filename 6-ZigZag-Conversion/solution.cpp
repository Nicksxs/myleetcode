class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        const int len = (int)s.length();
        string *str = new string[numRows];
        int row = 0;
        int step = 1;
        for(int i = 0; i < len; i++){
            str[row].push_back(s[i]);
            if(row == 0)
                step = 1;
            else if(row == (numRows - 1))
                    step = -1;
            row += step;
        }
        s.clear();
        for(int i = 0; i < numRows; i++){
            s.append(str[i]);
        }
        return s;
    }
};