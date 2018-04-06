/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    if (l1==NULL)
        return l2;
    if (l2==NULL)
        return l1;
    int carry=0;
    struct ListNode *rc=NULL,*tmpNode,*tail;
    
    while (l1!=NULL || l2!=NULL || carry!=0)
    {
        tmpNode=malloc(sizeof(struct ListNode));
        tmpNode->val=(l1!=NULL?l1->val:0)+(l2!=NULL?l2->val:0)+carry;
        //printf("%d\n",tmpNode->val);
        carry=tmpNode->val/10;
        tmpNode->val%=10;
        tmpNode->next=NULL;
        l1=l1==NULL?NULL:l1->next;
        l2=l2==NULL?NULL:l2->next;
        if (rc==NULL)
        {
            rc=tmpNode;
            tail=rc;
        }
        else
        {
            tail->next=tmpNode;
            tail=tail->next;
        }
        
    }
   // printf("%d\n",rc->val);
    return rc;
}