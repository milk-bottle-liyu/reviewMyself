/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL)
            return NULL;
        int count=0;
        ListNode * ptr=head,*final_head,*final_tail=NULL;
        while (ptr)
        {
            count++;
            ptr=ptr->next;
        }
        int left=k % count;
        int dont_move=count-left;
        if (left==0)
        {
            return head;
        }
        ptr=head;
        while (dont_move>0)
        {
            final_tail=ptr;
            ptr=ptr->next;
            dont_move--;
        }

        final_head=ptr;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        if (final_tail !=NULL)
            final_tail->next=NULL;
        if (count>1)
            ptr->next=head;
        ptr=final_head;

        return final_head;
    }
};
