class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int curmax=INT_MIN;

         for(int i=0;i<nums.size();i++)
         {
            
            pq.push({nums[i][0],i,0}); // element, list_idx,idx
            curmax = max(curmax, nums[i][0]);
         }

         vector<int>ans={0,INT_MAX};
        
         while(!pq.empty())
         {
            vector<int>vec= pq.top();
            pq.pop();
            int currmin= vec[0], listidx=vec[1], eleidx=vec[2];

            if(curmax-currmin< ans[1]-ans[0])
            {
                ans[0]=currmin;
                ans[1]=curmax;
            }

            if(eleidx+1< nums[listidx].size())
            {

                eleidx+=1; 
                pq.push({nums[listidx][eleidx] ,listidx, eleidx});
                curmax=max(curmax,nums[listidx][eleidx] );
            }
            else
            {
                break;
            }


         }
         return ans;
    }
};