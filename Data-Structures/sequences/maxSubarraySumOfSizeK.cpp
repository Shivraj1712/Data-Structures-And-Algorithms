#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxSubarraySumOfSizeK{
    // GFG - Maximum Subarray sum of size k 
    int maxSubarraySum(vector<int>& arr, int k) {
        int currSum = 0, maxSum =0 ;
        for(int i = 0 ; i < k ; ++i){
            currSum = currSum + arr[i];
        }
        maxSum = currSum;
        for(int i = k ; i < arr.size() ; ++i){
            currSum = currSum + arr[i] - arr[i-k];
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};