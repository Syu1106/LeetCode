
# [题目描述](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/):  
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。  
```
示例 1:  
输入: "abcabcbb"  
输出: 3   
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。  
```
```
示例 2:  
输入: "bbbbb"  
输出: 1  
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。 
```
# 本题考点：
  
  滑动窗口跟hash表
  
# 解题思路:

  1). 滑动窗口：left跟right记录不重复子串的边界，当前字符有两种情况①在子串中出现过，则left移动到出现过的位置+1;②没有出现过。两种情况最后都right+1。t记录right-left的最大值。
  
  2). 思路1是通过遍历子串查找是否重复，可以将查找改进成hash表，数组map大小256，初始化为-1，下标i为字符，map[i]记录字符出现过的位置。如果map[i]>=left,则移动left。

# 注意
  1). ""和" "的输出是否正确
  
  2). t=right-left还是right-left+1要想清楚

# 参考：
 1). 使用数组代替hash表 
 ```
int [26] 用于字母 ‘a’ - ‘z’ 或 ‘A’ - ‘Z’
int [128] 用于ASCII码
int [256] 用于扩展ASCII码hash表
``` 
 2).数值初始化：vector<int>map(256,-1)  
 3).当前字符换成整数：s[i]-0
  

  
