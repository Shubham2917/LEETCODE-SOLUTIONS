class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if (nums1.size() <= 2) return true;
        int odd = 0, even = 0;
        for (int x : nums1) {
            if (x % 2 == 0) even++;
            else odd++;
        }
        return odd == 0 || even == 0 || odd >= 2 || even >= 2;
    }
};
