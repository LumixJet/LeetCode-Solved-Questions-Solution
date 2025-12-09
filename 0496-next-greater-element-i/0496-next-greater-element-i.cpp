class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        
        for (int x : nums1) m[x] = -1;

        for (int i = 0; i < nums2.size(); i++) {
            if (m.count(nums2[i])) {
                for (int j = i + 1; j < nums2.size(); j++) {
                    if (nums2[j] > nums2[i]) {
                        m[nums2[i]] = nums2[j];
                        break;
                    }
                }
            }
        }

        vector<int> v;
        for (int x : nums1) {
            v.push_back(m[x]);
        }

        return v;
    }
};