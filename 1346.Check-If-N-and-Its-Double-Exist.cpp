class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> mp;
        for (int num : arr) {
            if (mp.count(num * 2) || (num % 2 == 0 && mp.count(num / 2)))   return true;
            mp.insert(num);
        }
        return false;
    }
};
