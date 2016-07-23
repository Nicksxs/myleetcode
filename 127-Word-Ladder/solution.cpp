class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord.size() != endWord.size())
            return 0;
        if (beginWord.empty() || endWord.empty())
            return 1;
        if (wordList.size() == 0)
            return 0;
        int distance = 1;
        queue<string> queToPush, queToPop;
        queToPop.push(beginWord)
        while(dict.size() > 0 && !queToPop.empty())
        {
            while(!queToPop.empty())
            {
                string str(queToPop.front());
                queToPop.pop();
                for(int i = 0; i < str.size(); i++)
                {
                    if (j == str[i])
                        continue;
                    char temp = str[i];
                    str[i] = j;
                    if(str == endWord)
                        return distance + 1;
                    if(wordList.count(str) > 0)
                    {
                        queToPush.push(str);
                        wordList.erase(str);
                    }
                    str[i] = temp;
                }
            }
            swap(queToPush, queToPop);
            distance++;
        }
        return 0;
    }
};