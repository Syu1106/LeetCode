#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
//思路1:遍历搜索符合条件的组合，时间复杂度o(n^2),空间复杂度o(1),运行速度慢且内存空间消耗大
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=0;
        vector<int>flag;
        flag.push_back(-1);
        flag.push_back(-1);
        for(i=0;i<nums.size();i++)
        {
            flag[0]=i;
            for(j=i+1;j<nums.size();j++)
                if(nums[i]+nums[j]==target)
                     {
                         flag[1]=j;
                         return flag ;
                     }
                     
        }
        return flag ;
    }
};

//思路2：遍哈希表，用哈希表存数组的值与下标，每到一个新的数，先查找哈希表里是否有target-this与现在的值配对，有则输出组合，没有则存入该数  
//时间复杂度o（n）,空间复杂度o(n),所需的额外空间取决于哈希表中存储的元素数量，该表中存储了 n 个元素。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>a;
        vector<int>flag={-1,-1};
        int i;
        for(i=0;i<nums.size();i++)
        {
            int complement = target -nums[i];
            if(a.find(complement)!=a.end())
            {
                flag[0]=a[complement];
                flag[1]=i;
                return flag;
            }
                
            else
                a[nums[i]]=i;
        }
        return flag ;
    }
};
