#include<iostream>
using namespace std;

class BinarySearch{
public:
    // LC - 704
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1 ;
    }
    // LC - 34
    int firstOccur(vector<int>& nums, int target){
        int st = 0 , end = nums.size() - 1, value = -1 ;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == target){
                value = mid ;
                end = mid - 1;
            }else if(nums[mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        return value;
    }
    int lastOccur(vector<int>& nums, int target){
        int st = 0 , end = nums.size() - 1, value = -1 ;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == target){
                value = mid ;
                st = mid + 1;
            }else if(nums[mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        return value;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = firstOccur(nums,target);
        ans[1] = lastOccur(nums,target);
        return ans;
    }
    // LC - 162
    int findPeakElement(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid+1]) high = mid;
            else low = mid + 1;
        }
        return low;
    }
    // LC - 33
    int searchLC33(vector<int>& nums, int target) {
        int low = 0 , high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < nums[high]){
                if(nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid -1 ;
            }else{
                if(nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
    // LC - 81
    bool search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[high] == nums[mid]){
                low++;
                high--;
                continue;
            }
            else if(nums[mid] <= nums[high]){
                if(nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }else{
                if(nums[low] <= target && target < nums[mid]) high = mid -1;
                else low = mid + 1;
            }
        }
        return false;
    }
    
};