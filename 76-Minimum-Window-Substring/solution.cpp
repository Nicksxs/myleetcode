class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0) return "";
        if(s.size() < t.size()) return "";
        int appearCount[256];
        int expectCount[256];
        memset(appearCount, 0, 256*sizeof(appearCount[0]));
        memset(expectCount, 0, 256*sizeof(appearCount[0]));
        for(int i =0; i < T.size(); i++)
        {
            expectCount[T[i]]++;
        }
        int minV = INT_MAX, min_start = 0;  
        int wid_start=0;  
        int appeared = 0;   
        for(int wid_end = 0; wid_end< s.size(); wid_end++)  
        {
             if(expectCount[s[wid_end]] > 0)// this char is a part of T  
             {
                  appearCount[s[wid_end]]++;  
                  if(appearCount[s[wid_end]] <= expectCount[s[wid_end]])
                       appeared ++;                      
                 }  
             if(appeared == t.size())
             {
                  while(appearCount[s[wid_start]] > expectCount[s[wid_start]]
                      || expectCount[s[wid_start]] == 0)  
                  {
                        appearCount[s[wid_start]]--;  
                        wid_start ++;  
                    }                      
                    if(minV > (wid_end - wid_start +1))
                    {
                           minV = wid_end - wid_start +1;  
                           min_start = wid_start;  
                    }  
                 }                 
            }  
      if(minV == INT_MAX) return "";  
            return s.substr(min_start, minV)
    }
};