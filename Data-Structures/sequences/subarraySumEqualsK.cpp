#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SubarraySumEqualsK{
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0 , running_sum = 0 ;
        unordered_map<int,int> state ;
        state[0] = 1;
        for(int i = 0 ; i < nums.size() ; ++i){
            running_sum += nums[i];
            int target = running_sum - k ;
            if(state.find(target) != state.end()){
                count += state[target];
            }
            state[running_sum]++;
        }
        return count ;
    }
};