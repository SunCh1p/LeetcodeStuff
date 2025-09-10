class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int count = 0;
        while(i < nums.size()){
            int next = i+1;
            while(next < nums.size() && nums[i] == nums[next]){
                count++;
                nums[next] = std::numeric_limits<int>::max();
                next++;
            }
            i = next;
        }
        sort(nums.begin(), nums.end());
        return nums.size()-count;
    }
};
//O(nlogn) time
//o(1) space