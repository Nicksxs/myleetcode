class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string compare;
        if(strs.size() == 0) return compare;
        compare = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            string prefix;
            int k = 0;
            while( k < compare.size() && k < strs[i].size())
            {
                if(compare[k] != strs[i][k])
                    break;
                prefix.append(1, compare[k]);
                k++;
            }
            compare.clear();
            compare.append(prefix.c_str());
        }
        return compare;
    }
};