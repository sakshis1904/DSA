class Solution {
public:

    int firstOcc(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }

    int lastOcc(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int last = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return last;
    }

    /* if we use lower and upper bound
    int lowerBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1; 
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1; 
            }
        }
        return ans;
    }
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurence = firstOcc(nums, target);
        if(firstOccurence == -1) return {-1, -1};
        int lastOccurence = lastOcc(nums, target);
        return {firstOccurence, lastOccurence};
    }
};