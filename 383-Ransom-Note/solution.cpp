class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magazLetters(128, 0);
        for(char m : magazine)
            magazLetters[m]++;
        for(char r : ransomNote)
            if(--magazLetters[r]<0) return false;
        return true;
    }
};