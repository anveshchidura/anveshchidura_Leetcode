class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            int maxi = prices[i]-mini;
            ans = max(maxi,ans);
            mini = min(prices[i],mini); 
        }
        return ans; 
    }
};