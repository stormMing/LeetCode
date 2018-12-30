/*21. Merge Two Sorted Lists
两个无头结点的有序单链表的合并
参考：https://blog.csdn.net/qq_39755395/article/details/80007481
*/

class Solution {//非递归
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        else if(l1 == NULL && l2 == NULL) return NULL;
        
        ListNode *Head= l1,*p = l1->next,*q = l2; //p循环的是主链表：第一个结点最小的那个
        if(l1->val > l2->val){
            Head = l2; //将l2选为主链表
            p = l2->next;
            q = l1;
        }
        ListNode *r = Head; //采用尾插法
        while(p && q){
            if(p->val < q->val){
                r->next = p;
                r = p;
                p = p->next;
            }
            else{
                r->next = q;
                r = q;
                q = q->next;
            }
        }
        
        if(p){
            r->next = p;
        }
        if(q){
            r->next = q;
        }
        return Head;
    }
};

class Solution {//两个无头结点的有序单链表的合并
public:
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { //递归算法
    if(l1 == NULL) return l2;
    else if(l2 == NULL) return l1;
    else if(l1 == NULL && l2 == NULL) return NULL;
    
    ListNode *Head= l1,*p = l1->next,*q = l2;
    if(l1->val > l2->val){
        Head = l2;
        p = l2->next;
        q = l1;
    }
    
    Head->next = mergeTwoLists(p,q);//Head->next是p q中较小的那个
    return Head;
  }
}；
