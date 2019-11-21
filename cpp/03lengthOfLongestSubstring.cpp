//滑动窗口，时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,t=0,n=s.size(),f=-1;
        vector<char>a;
        char b;
        t=0;
        while(j<n)
        {
            b=s[j];
            for(int i1=i;i1<j;i1++)
            {
                if(b==s[i1])
                f=i1;                
            }
            
            if(f==-1)
            {
                j=j+1;
            }
            else
            {
                i=f+1;
                j=j+1;
            }
            if(t<(j-i))
                t=j-i;
            f=-1;  
        }
       return t; 
    }
};
//滑动窗口+hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,t=0,n=s.size(),i=0;
        vector<int>map(256,-1);
        while(right<n)
        {
            i=s[right]-0;   //当前字符
            if(map[i]>=left)   //当前字符在滑动窗口出现过
                left=map[i]+1;  //挪动左边界
            map[i]=right;    //存当前字符的位置       
            right++;
            if(t<(right-left))
                t=right-left;
        }
       return t; 
    }
};

int main()
{
    string s=" ";
    Solution A;
    cout<<A.lengthOfLongestSubstring(s);
    system("pause");
    return 0;
}
