class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
        }
        
        /*
        //brute
        set<int> mpp;
        
        for(int i = 0; i < nums.size(); i++) {
            mpp.insert(nums[i]);
        }
        
        int index = 0;
        for (const int& element : mpp) {
            nums[index++] = element;
        }
        
        return mpp.size();
        */
    
};
