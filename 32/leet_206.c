/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode *preNode,*curNode,*tmp;
    
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
        return head;
    
    preNode=NULL;
    curNode=head;
    while (curNode)
    {
        tmp=curNode->next;
        curNode->next=preNode;
        preNode=curNode;
        curNode=tmp;
    }
    return preNode;
}