//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
//Example:
//Given nums = [-2, 0, 3, -5, 2, -1]
//
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> -1
//sumRange(0, 5) -> -3
//Note:
//You may assume that the array does not change.
//There are many calls to sumRange function.

发现只要初始时计算保存从头到i,j两个连加和，调用sum range时就可以通过两个连加相减得出。

class NumArray {
    
    vector<int> mynums;
    
public:
    NumArray(vector<int> &nums) : mynums(nums.size()+1) {
        for(int i = 0 ; i < nums.size(); ++i) {
            mynums[i+1] = mynums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return mynums[j+1] - mynums[i];
    }
};
