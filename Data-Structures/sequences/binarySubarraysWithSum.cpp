#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BinarySubarraysWithSum{
public: 
    // LC - 930
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0 , running_sum = 0 ;
        unordered_map<int,int> state ;
        state[0] = 1;
        for(int i = 0 ; i < nums.size() ; ++i){
            running_sum += nums[i];
            int target = running_sum - goal;
            if(state.find(target) != state.end()){
                count += state[target];
            }
            state[running_sum]++;
        }
        return count ;
    }
};