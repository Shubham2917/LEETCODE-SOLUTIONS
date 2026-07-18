class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];

        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < mn) mn = nums[i];
            if(nums[i] > mx) mx = nums[i];
        }



        for (int i = mn; i>=2; i--){
            if(mn % i==0 && mx%i ==0)
            return i;
        }
        return 1;



    }
        
};