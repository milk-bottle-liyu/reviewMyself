/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    int sizeA=0,sizeB=0;
    
    struct ListNode *tmp;
    tmp=headA;
    while (tmp)
    {
        sizeA++;
        tmp=tmp->next;
    }
    tmp=headB;
    while (tmp)
    {
        sizeB++;
        tmp=tmp->next;
    }
    
    if (sizeA==0 || sizeB==0)
        return NULL;
    
    int sizeTmp;
    if (sizeA <sizeB)
    {
        tmp=headA;headA=headB;headB=tmp;
        sizeTmp=sizeA;sizeA=sizeB;sizeB=sizeTmp;
    }
    
    while (sizeA!=sizeB)
    {
        headA=headA->next;
        sizeA--;
    }
    
    while (headA && headA!=headB)
    {
        headA=headA->next;
        headB=headB->next;
    }
    
    return headA;
}