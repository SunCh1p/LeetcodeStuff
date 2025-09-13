using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //how to solve with o(1) spacee
        sort(nums.begin(), nums.end());
        int maxFrequency = 0;
        int maxFreqElement = 0;
        int left = 0, right = 0;
        while(left < nums.size()){
            while(right < nums.size() && nums[right] == nums[left]){
                right++;
            }
            if(right-left > maxFrequency){
                maxFrequency = right-left;
                maxFreqElement = nums[left];
            }
            left = right;
        }
        return maxFreqElement;
    }
};
//O(nlogn) time
//O(1) space