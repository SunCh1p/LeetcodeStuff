class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int count = 0;
        while(i < nums.size()){
            if(i+1 < nums.size() && nums[i] != nums[i+1]){
                i++;
            } else {
                int next = i+2;
                while(next < nums.size() && nums[i] == nums[next]){
                    count++;
                    nums[next] = std::numeric_limits<int>::max();
                    next++;
                }
                i = next;
            }
        }
        sort(nums.begin(), nums.end());
        return nums.size()-count;
    }
};
//Time complexity O(nlogn)
//space complexity O(1)