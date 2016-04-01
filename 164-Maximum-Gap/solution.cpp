class Solution {
public:
    int maximumGap(vector<int>& num) {
        if (num.size() < 2) return 0;
        int Max = num[0], Min = Max, ans = 0;
        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] < Min)
                Min = num[i];
            if (num[i] > Max)
                Max = num[i];
        }
        if (Max == Min) return 0;

        int bucketGap = (Max - Min)/num.size() + 1; // 桶的间隔是关键
        int bucketLen = (Max - Min)/bucketGap + 1; // 举个 1，2，3的例子就知道了
        vector<int> MinMax(2, INT_MAX);
        MinMax[1] = INT_MIN;
        vector<vector<int> > bucket(bucketLen, MinMax);

        for (int i = 0; i < num.size(); i++)
        {
            int ind = (num[i] - Min)/bucketGap;
            if (num[i] < bucket[ind][0])
                bucket[ind][0] = num[i];
            if (num[i] > bucket[ind][1])
                bucket[ind][1] = num[i];
        }

        int first = bucket[0][1], second;
        for (int i = 1; i < bucketLen; i++)
        {
            if (bucket[i][0] == INT_MAX) continue;
            second = bucket[i][0];
            int tmpmax = second - first;
            ans = tmpmax > ans ? tmpmax : ans;
            first = bucket[i][1];
        }

        return ans;
    }
};