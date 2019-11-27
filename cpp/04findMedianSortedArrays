#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }        
        int hi=nums1.size()-1,lo=0,m1=nums1.size()-1,n1=nums2.size()-1;       
        float median=-10000; 
        int mid=-1,t=-1;//nums1取第mid个，nums2取第t个
        int lmax1,rmin1,lmax2,rmin2;
        while(lo<=hi)
        {            
            mid = (nums1.size()>0)? ((lo+hi)/2):-1;     //第一个为空时，mid=-1
            t = (nums1.size()+nums2.size()+1)/2- 2 - mid;
            lmax1 = (mid >= 0) ? nums1[mid] : INT_MIN;
            rmin1= (mid < m1) ? nums1[mid+1] : INT_MAX;
            lmax2 = (t>= 0) ? nums2[t] : INT_MIN;
            rmin2 = (t < n1) ? nums2[t+1] : INT_MAX;
            if(lmax1>rmin2)        //mid要左移
            {                
                hi=mid-1;             
            }
            else if(lmax2>rmin1)         //mid要右移
            {               
                lo=mid+1; 
            }
            else  break;//不需要挪动了
         }
        hi= (hi==-1)? -2:hi;//hi=-1,lo=0时，要让mid=-1
        mid = (nums1.size()>0)? ((lo+hi)/2):-1;     //第一个为空时，mid=-1
        t = (nums1.size()+nums2.size()+1)/2- 2 - mid;
        lmax1 = (mid >= 0) ? nums1[mid] : INT_MIN;
        rmin1= (mid < m1) ? nums1[mid+1] : INT_MAX;
        lmax2 = (t>= 0) ? nums2[t] : INT_MIN;
        rmin2 = (t < n1) ? nums2[t+1] : INT_MAX;
        if((nums1.size()+nums2.size())%2==0)
        {
            median=(max(lmax1,lmax2)+min(rmin1,rmin2))/2.0;
        }
        else
        {
            median=max(lmax1,lmax2);           
        }            
        return median;        
    }
};
int main()
{
    vector<int>a={1,2};
    vector<int>b={3,4};
    Solution A;
    cout<< A.findMedianSortedArrays(a,b)<< endl;
    system("pause");
    return 0;
}
