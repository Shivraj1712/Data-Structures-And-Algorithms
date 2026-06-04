#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TwoSumIIinputArrayIsSorted{
public:
    // LC - 167 
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0 , j = numbers.size() - 1;
        while(i < j){
            long long sum = (long long) numbers[i] + numbers[j];
            if(sum == target) return {i+1,j+1};
            else if(sum < target) ++i;
            else j--;
        }
        return {};
    }
};