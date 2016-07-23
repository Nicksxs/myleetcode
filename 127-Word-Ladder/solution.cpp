class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (start.size() != end.size())
            return 0;
        if (start.empty() || end.empty())
            return 1;
        if (dict.size() == 0)
            return 0;
        int distance = 1;
        queue<string> queToPush, queToPop;
        queToPop.push(start)
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
                    if(str == end)
                        return distance + 1;
                    if(dict.count(str) > 0)
                    {
                        queToPush.push(str);
                        dict.erase(str);
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