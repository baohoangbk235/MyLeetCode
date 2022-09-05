// A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

// For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
// In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
// A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

// Given an integer array nums, return the length of the longest wiggle subsequence of nums.

#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) 
            return nums.size();
        int maxLength = 2;
        int left = 0;
        int right = 2;
        while (left < nums.size()-1 && nums[left] == nums[left+1]){
            left ++;
        }
        if (left == nums.size() - 1) return 1;
        right = left + 2;
        int flag =  nums[left+1] - nums[left];
        while (right < nums.size() && left < right){
            if ((nums[right] - nums[right-1]) * flag < 0){
                flag *= -1;
                maxLength += 1;
            }
            right ++;
        }
        return maxLength;
    }
};