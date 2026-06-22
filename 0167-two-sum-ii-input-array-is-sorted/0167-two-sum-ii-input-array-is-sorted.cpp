// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n = numbers.size();
//         for(int i = 0; i < n - 1; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 int sum = numbers[i] + numbers[j];
//                 if(sum == target)
//                     return {i + 1, j + 1};
//                 if(sum > target)
//                     break;  
//             }
//         }
//         return {};
//     }
// };



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n; i++) {
            int need = target - numbers[i];
            int l = i + 1;
            int r = n - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(numbers[mid] == need)
                    return {i + 1, mid + 1};
                if(numbers[mid] < need)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return {};
    }
};