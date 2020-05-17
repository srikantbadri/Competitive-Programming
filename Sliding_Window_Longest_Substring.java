/***
Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


**/
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> map = new HashMap<>();
        int start=0;
        int end=0;
        int count=0;
        int len=s.length();
        int maxLen=0;
        while(end<len){
            char c=s.charAt(end);
            map.put(c,map.getOrDefault(c,0)+1);
            if(map.get(c)>1)
                count++;    
            end++;
            while(count>0){
                char c1=s.charAt(start);
                if(map.get(c1)>1){
                    count--;
                }
                map.put(c1,map.get(c1)-1);
                start++;
            }
            maxLen=Math.max(maxLen,end-start);
        }
        return maxLen;
    }
}
