# [题目描述](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/):  
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。  

给定两个大小为m和n的有序数组nums1和nums2。  

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为O(log(m + n))。  

你可以假设nums1和nums2不会同时为空。  
```
示例1：
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

```
```
示例 2:  
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
```
# 本题考点：
  
  二分法，难点在边界条件的判断
  
# 解题思路:

  1).中位数的含义是：将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。
  2).将数组A与数组B分别在位置i跟j进行划分，使len(left_part)=len(right_part)并且max(left_part)≤min(right_part)  
　　　　　　　　　　　　　　　left_part　　　|　　　right_part  
　　　　　　　　　　　　A[0],A[1],...,A[i-1],A[i]　|　A[i+1],...,A[m-1]  
　　　　　　　　　　　　B[0],B[1],...,B[j-1],B[j]　|　B[j+1],...,B[n-1]  
  3).i+j=(A.size()+B.size()+1)/2-2,所以i确定后，j也自动确定了。
  4).题目有时间复杂度的要求，所以采用二分法确定i的位置  
  5).需要考虑一些边界条件:  
　　　①比较的时候会用到下标[i]跟[i+1]，当i<0（A全部被划分在右边）或者i=A.size()-1时，数组的下标溢出。用leftmax=INT_MIN,rightmin=INT_MAX。    
　　　②当i=0挪到i=-1时，lo=0，hi=-1,(lo+hi)/2仍然为0，所以当hi=-1时，令hi=-2,则i=-1(数组A全部分到右边）  
　　　③判断跳出可能是划分位置满足条件了，也可能是hi<lo，所以要对i,j再重新赋值  
  6).当A.size()+B.size()为偶数时，median=(max(lmax1,lmax2)+min(rmin1,rmin2))/2.0;奇数median=max(lmax1,lmax2);
# 注意
  1).一定要小心数组的下标溢出  
  2).特殊情况：一个数组为空；有一个数组全部被划分在左边或者右边。

# 参考：
 1). 二分法
```
while(lo<=hi) //循环条件
{
      mid=(lo+hi)/2
      if() lo=mid+1 //右移
      if() hi=mid-1 //左移
      else break;//找到了划分位置
}
``` 
