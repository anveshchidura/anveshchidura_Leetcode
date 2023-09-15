class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix;
        int maxi = 0;
        for(int i = 0;i< height.size();i++){
            maxi = max(maxi,height[i]);
            prefix.push_back(maxi);
        }
        vector<int> suffix;
        maxi = 0;
        for(int i = height.size()-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            suffix.insert(suffix.begin(),maxi);
        }
        int sum = 0;
        for(int i = 0;i< height.size();i++){
            sum += min(prefix[i],suffix[i]) - height[i];
        }
        return sum;
        
    }
};