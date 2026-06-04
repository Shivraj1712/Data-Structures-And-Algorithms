#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaximumNoOfAVowelsInSubString{
public:
    // LC - 1456
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int curr = 0 , maxVal = 0 ;
        for(int i = 0 ; i < k ; ++i){
            if(vowels.find(s[i]) != string::npos) ++curr;
        }
        maxVal = curr;
        for(int i = k ; i < s.size() ; ++i){
            if(vowels.find(s[i-k]) != string::npos) --curr;
            if(vowels.find(s[i]) != string::npos) ++curr;
            maxVal = max(curr,maxVal);
        }
        return maxVal;
    }
};