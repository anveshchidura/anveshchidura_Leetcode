class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt =0,maxi = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(cnt,maxi);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
        /*
        //my approach
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
        */
        
    }
};