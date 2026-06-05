#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaximumSubarray{
public: 
    // LC - 53
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN , curr = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            curr += nums[i];
            maxVal = max(maxVal,curr);
            if(curr < 0) curr = 0;
        }
        return maxVal;
    }
};