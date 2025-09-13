using namespace std;
#include <unordered_map>
#include <string>
class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'i' || c == 'o' || c =='e' || c == 'u');
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> counter;
        int maxVowelCount = 0;
        int maxConsonantCount = 0;
        for(auto c: s){
            counter[c]++;
            if(isVowel(c)){
                maxVowelCount = max(maxVowelCount, counter[c]);
            } else {
                maxConsonantCount = max(maxConsonantCount, counter[c]);
            }
        }
        return maxVowelCount+maxConsonantCount;
    }
};

//time complexity O(n)
//space complexity O(n)