# [题目描述](https://leetcode-cn.com/problems/add-two-numbers):  
给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。  
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。  
示例：  
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)  
输出：7 -> 0 -> 8  
原因：342 + 465 = 807  
# 本题考点：
  
   链表的用法
  
# 解题思路:

  1). 将较短的链表补零对齐再相加，考虑进位
  
  2). 先取出链表的值，其中一个链表已经到末尾时值取0，然后两值相加考虑进位

# 注意
  1). 最高位的进位也要考虑
  
  2). 存放和的链表头为空，最后delete释放掉


# 参考：
- [链表基本用法](https://blog.csdn.net/sinat_35512245/article/details/54600187)    
  1). 链表单元的结构
  
  ```c++  
    struct ListNode
    {
      int val;//值
      ListNode *next;
      ListNode(int x) 
      {
        val=x;
        next=NULL;
      }
    }
    ```
  2).链表head后面加一个节点p
  ```c++
  ListNode* head=new ListNode(0);
  ListNode* f=head;//用指针指链表的位置
  f->next=p;
  f=f->next;//f指向新的节点
  ```
  3).删除空的头节点
  ```c++
  f=head->next;
  delete head;
  ```
  
