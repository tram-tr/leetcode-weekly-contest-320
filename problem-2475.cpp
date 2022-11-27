class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i; j < nums.size(); j++) {
                for (size_t k = j; k < nums.size(); k++) {
                    if ((nums[i] != nums[j]) && (nums[j] != nums[k]))
                        count++;
                }
            }
        }
        
        return count;
    }
};
