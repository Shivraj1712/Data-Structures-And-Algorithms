#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ContainerWithMostWater{
public:
    // LC - 11
    int maxArea(vector<int>& h) {
        int i = 0 , j = h.size() - 1;
        int curr = 0 , maxVal = 0;
        while(i <= j){
            curr = min(h[i],h[j]) * (j-i);
            maxVal = max(curr,maxVal);
            (h[i] < h[j]) ? ++i : --j;
        }
        return maxVal;
    }
};