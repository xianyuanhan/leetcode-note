class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {  // ✅ 修正1: <= 不能有空格
            int middle = left + (right - left) / 2;  // 防止溢出

            if (nums[middle] > target) {
                right = middle - 1;  // 目标在左半部分
            } else if (nums[middle] < target) {
                left = middle + 1;   // 目标在右半部分
            } else {
                return middle;       // 找到目标，返回下标
            }
        }

        return -1;  // 未找到
    }
};