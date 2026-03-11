class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size() - 1 ;
        int ans = bs(nums , high , low , target) ;
        return ans ;
    }
    int bs(vector<int>& nums , int high , int low , int target) {
        if(low > high) return -1 ;
        int mid = (low + high)/2 ;
        if(nums[mid] == target) return mid ;
        else if ( nums[mid] > target) return bs(nums , mid-1 , low , target) ;
        else return bs(nums , high ,  mid+1 , target) ;
    }
};