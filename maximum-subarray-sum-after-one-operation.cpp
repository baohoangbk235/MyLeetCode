
// You are given an integer array nums. You must perform exactly one operation where you can replace one element nums[i] with nums[i] * nums[i]. 
// Return the maximum possible subarray sum after exactly one operation. The subarray must be non-empty.
#include<vector>
using namespace std;

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int maxSum = 0, sq = 0, no_sq = 0;
        for (auto& num: nums){
            sq = max(max(sq + num, no_sq + num * num), num * num);
            no_sq = max(no_sq + num, num);
            maxSum = max(maxSum, sq);
        }
        return maxSum;
    }
};