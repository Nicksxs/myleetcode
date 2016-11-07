class Solution {
public:
    // string parse(string s) {
    //     cout << "s: " << s << endl;
    //     string r = "";
    //     for(int i = 0; i < s.size();) {
    //         if(isdigit(s[i])) {
    //             int num = 0;
    //             while(isdigit(s[i])) {
    //                 num = num * 10 + (s[i] - '0');
    //                 ++i;
    //             }
    //             int bracket_match = 1;
    //             int j = i;
    //             cout << "i: " << i << endl;
    //             while(bracket_match > 0) {
    //                 ++j;
    //                 cout << "breacket_match: " << bracket_match << " s[j]: " << s[j] << endl;
    //                 if(s[j] == '[') ++bracket_match;
    //                 else if(s[j] == ']') --bracket_match;
    //             }
    //             string temp = parse(s.substr(i + 1, j - i - 1));
    //             for(int k = 0; k < num; ++k) {
    //                 r += temp;
    //             }
    //             i = j + 1;
    //         } else if(isalpha(s[i])) {
    //             r += s[i];
    //             ++i;
    //         }
    //     }
    //     return r;
    // }
    // string decodeString(string s) {
    //     return parse(s);
    // }
    
    // string parse(string s) {
    //     string r = "";
    //     for(int i = 0; i < s.size(); ) {
    //         if(isdigit(s[i])) {
    //             int num = 0;
    //             while(isdigit(s[i])) {
    //                 num = num * 10 + (s[i] - '0');
    //                 ++i;
    //             }
    //             int bracket_match = 1;
    //             int j= i;
    //             while(bracket_match > 0) {
    //                 ++j;
    //                 if(s[j] == '[') ++bracket_match;
    //                 else if(s[j] == ']') --bracket_match;
    //             }
    //             string temp = parse(s.substr(i + 1, j - i - 1));
    //             for(int k = 0; k < num; ++k){
    //                 r += temp;
    //             }
    //             i = j + 1;
    //         } else if(isalpha(s[i])) {
    //             r += s[i];
    //             ++i;
    //         }
    //     }
    //     return r;
    // }
    // string decodeString(string s){
    //     return parse(s);
    // }
    
    
    
    
    string decodeString(string s) {
        auto found = s.find_last_of('[');         //每次处理最后一个中括号里的内容
        cout << found << endl;
        if (found == string::npos) {
            return s;
        } else {
            auto iNum = found;
            while (isdigit(s[iNum - 1])) iNum--;
            int num = stoi(s.substr(iNum, found - iNum));
            auto foundEnd = s.find_first_of(']', found);
            string mid = s.substr(found + 1, foundEnd - found - 1);
            string midsum;
            while (num-- > 0) midsum += mid;
            cout << "1: " <<s.substr(0, iNum) << "  2: " << midsum << " 3: " <<  s.substr(foundEnd + 1) << endl;
            return decodeString(s.substr(0, iNum) + midsum + s.substr(foundEnd + 1));
        }
    }
};