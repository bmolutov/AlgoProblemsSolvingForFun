class Solution {
    public static void main(String[] args) {

    }
    public static int maxSubArray(int[] nums) {
        int global_max = nums[0];
        int current_max = nums[0];
        for(int i = 1; i < nums.length; i++) {
            current_max = Math.max(nums[i], current_max + nums[i]);
            global_max = Math.max(global_max, current_max);
        }
        return global_max;
    }
}