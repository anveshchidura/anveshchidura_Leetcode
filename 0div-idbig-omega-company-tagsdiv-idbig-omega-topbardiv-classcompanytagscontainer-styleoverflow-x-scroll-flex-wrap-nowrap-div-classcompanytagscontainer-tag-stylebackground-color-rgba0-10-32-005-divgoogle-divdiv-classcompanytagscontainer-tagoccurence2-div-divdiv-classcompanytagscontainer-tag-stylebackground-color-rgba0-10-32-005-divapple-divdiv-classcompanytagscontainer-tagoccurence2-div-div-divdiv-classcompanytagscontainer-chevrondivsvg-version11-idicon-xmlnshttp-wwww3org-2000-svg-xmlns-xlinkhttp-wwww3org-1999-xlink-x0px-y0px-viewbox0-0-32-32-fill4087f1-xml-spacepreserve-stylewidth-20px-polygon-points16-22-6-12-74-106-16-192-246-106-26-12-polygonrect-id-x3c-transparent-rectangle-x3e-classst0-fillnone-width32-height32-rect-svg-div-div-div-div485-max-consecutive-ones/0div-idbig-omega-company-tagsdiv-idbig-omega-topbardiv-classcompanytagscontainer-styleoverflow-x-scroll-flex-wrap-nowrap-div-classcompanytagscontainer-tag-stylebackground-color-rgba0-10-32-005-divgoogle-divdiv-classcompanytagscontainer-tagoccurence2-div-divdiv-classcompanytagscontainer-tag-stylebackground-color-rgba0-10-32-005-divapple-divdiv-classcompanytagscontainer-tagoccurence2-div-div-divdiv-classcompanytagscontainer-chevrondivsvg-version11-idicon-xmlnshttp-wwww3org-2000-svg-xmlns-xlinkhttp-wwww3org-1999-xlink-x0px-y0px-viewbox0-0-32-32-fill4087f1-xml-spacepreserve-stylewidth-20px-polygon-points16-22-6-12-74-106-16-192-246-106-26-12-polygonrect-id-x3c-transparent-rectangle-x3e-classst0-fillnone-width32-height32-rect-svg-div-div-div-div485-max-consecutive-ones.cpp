class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0,j=0,res = 0,ans = 0;
    
        while(i<nums.size() && j<nums.size()){
            if(nums[j] == 1){
                res += 1;
                ans = max(ans,res);
                j++;                
            }
            else if(nums[j] == 0){
                i = j +1;
                j++;
                res = 0;
                continue;
            }
            
        }
        return ans;
        
    }
};