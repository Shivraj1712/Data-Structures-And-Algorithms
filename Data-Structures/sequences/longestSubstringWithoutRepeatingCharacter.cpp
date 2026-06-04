#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LongestSubstringWithoutRepeatingCharacter{
public:
    // LC - 3
    int lengthOfLongestSubstring(string s) {
        int length = 0 , left = 0;
        if(s.size() == 0) return 0;
        unordered_set<char> set;
        for(int i = 0 ; i < s.size() ; ++i){
            if(set.find(s[i]) != set.end()){
                while(set.find(s[i]) != set.end()){
                    set.erase(s[left]);
                    ++left;
                }
                length = max(length,i - left + 1);
                set.insert(s[i]);
            }else{
                set.insert(s[i]);
            }
            length = max(length,i - left + 1);
        }
        return length;
    }
};