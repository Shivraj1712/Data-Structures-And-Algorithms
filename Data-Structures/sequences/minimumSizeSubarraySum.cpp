#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinimumSizeSubarraySum{
public:
    // LC - 209
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX , left = 0;
        double sum = 0 ;
        for(int i = 0 ; i < nums.size() ; ++i){
            sum += nums[i];
            while(sum >= target){
                sum = sum - nums[left];
                ++left;
                length = min(length,i - left + 2);
            }
        }
        return length == INT_MAX ? 0 : length ;
    }
};