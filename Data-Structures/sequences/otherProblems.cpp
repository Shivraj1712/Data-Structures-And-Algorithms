#include<iostream>
using namespace std;

class OtherProblems{
public:
    // LC - 1
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0 ; i < nums.size() ; ++i){
            int value = target - nums[i];
            if(map.find(value) != map.end()){
                return {i,map[value]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
    // LC - 454
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int,int> map;
        for(int i : nums1){
            for(int j : nums2){
                map[i+j]++;
            }
        }
        for(int i : nums3){
            for(int j : nums4){
                int target = - (i + j);
                if(map.find(target) != map.end()){
                    count += map[target];
                }
            }
        }
        return count;
    }
    // LC - 242
    bool isAnagram(string s, string t) {
        if(t.length() < s.length()) return false;
        unordered_map<char,int> m1,m2;
        for(char i : s) m1[i]++;
        for(char i : t) m2[i]++;
        for(auto &[c,n] : m1){
            if(m2.find(c) == m2.end() || m2[c] != n) return false;
        }
        for(auto &[c,n] : m2){
            if(m1.find(c) == m1.end() || m1[c] != n) return false;
        }
        return true;
    }
};