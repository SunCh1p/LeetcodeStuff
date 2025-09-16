class Solution {
public:
    int getGcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    int getLcm(int a, int b) {
        return (a / getGcd(a, b)) * b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> res;
        for (int num : nums) {
            res.push(num);
            while (res.size() > 1) {
                int a = res.top(); res.pop();
                int b = res.top(); res.pop();
                int g = getGcd(a, b);
                if (g > 1) {
                    res.push(getLcm(a, b));
                } else {
                    res.push(b);
                    res.push(a);
                    break;
                }
            }
        }
        vector<int> result;
        while (!res.empty()) {
            result.push_back(res.top());
            res.pop();
        }
        reverse(result.begin(), result.end());
        return result; 
    } 
};