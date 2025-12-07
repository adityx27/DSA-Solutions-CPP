#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int mid = s + (e-s)/2;

        while(s <= e){
            if(nums[mid] == target){
                return true;
            }
            if(nums[s] == nums[mid] && nums[mid] == nums[e]){
                s += 1;
                e -= 1;
                continue;
            }

            //left sorted
            if(nums[s] <= nums[mid]){
                if(nums[s] <= target && target < nums[mid] ){
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            else {
                if(nums[mid] < target && target <= nums[e]){
                    s = mid + 1;
                }
                else {
                    e = mid - 1;
                }
            }
            mid = s + (e-s)/2;
        }
        return false;
    }
};