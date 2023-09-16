class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> mpp;
        
        for(int i = 0; i < nums.size(); i++) {
            mpp.insert(nums[i]);
        }
        
        int index = 0;
        for (const int& element : mpp) {
            nums[index++] = element;
        }
        
        return mpp.size();
    }
};
