class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans(k, 0);
		for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
			vector<int> res1 = get_max_sub_array(nums1, i);
			vector<int> res2 = get_max_sub_array(nums2, k - i);
			vector<int> res(k, 0);
			int pos1 = 0, pos2 = 0, tpos = 0;
			while (pos1 < res1.size() || pos2 < res2.size()) {
				res[tpos++] = greater(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
			}
			if (!greater(ans, 0, res, 0))
				ans = res;
		}
		return ans;
	}

	bool greater(const vector<int> & a, int start1, const vector<int> &b, int start2) {
		for (; start1 < a.size() && start2 < b.size(); start1++, start2++) {
			if (a[start1] > b[start2]) return true;
			if (a[start1] < b[start2]) return false;
		}
		return start1 != a.size();
	}

	vector<int> get_max_sub_array(const vector<int> &nums, const int& k) {
		vector<int> res(k,0);
		int len = 0 , n = nums.size();
		for (int i = 0; i < n; i++) {
			while (len && len + n - i > k && nums[i] > res[len - 1])
				len--;
			if (len < k)
				res[len++] = nums[i];
		}
		return res;
	}
};