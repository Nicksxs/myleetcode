class Solution {
public:
    int numDistinct(string s, string t) {
        int match[200];
        if(s.size() < t.size()) return 0;
        match[0] = 1;
        for(int i = 1; i <= t.size(); i++){
            match[i] = 0;
        }
        for(int i = 1; i <= s.size(); i++){
            for(int j = t.size(); j >= 1; j--){
                cout << "s[i-1]:" << s[i-1] << " " << "t[j-1]" << t[j-1] << endl;
                if(s[i-1] == t[j-1])
                    match[j] += match[j-1];
                cout << "match[j]: " << match[j] << endl;
            }
        }
        return match[t.size()];
    }
};