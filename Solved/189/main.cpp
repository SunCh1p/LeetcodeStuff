#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> numToIndex;
        int size = nums.size();
        for(int i = 0; i < nums.size(); i++){
            numToIndex[nums[i]].push_back((i+k)%size);
        }
        for(auto pairing: numToIndex){
            int num = pairing.first;
            for(auto index: pairing.second){
                nums[index] = num;
            }
        }
    }
};