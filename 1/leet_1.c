/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MYKEY 32767
struct node
{
    int data,idx;
    struct node * next;
};

int* twoSum(int* nums, int numsSize, int target) 
{
    int tmp;
    struct node * hash_t=(struct node *)malloc(sizeof(struct node)*MYKEY);
    for (int i=0;i<MYKEY;i++)
    {
        (hash_t+i)->next=NULL;
    }
    struct node *ptr,*nextnode;
    
    int * a=(int *)malloc(2*sizeof(int));
    
    for (int i=0;i<numsSize;i++)
    {
        
        tmp=abs(target-nums[i])%(MYKEY);
        ptr=&hash_t[tmp];
      //  printf("%d--------\n",tmp);
        while (ptr->data+nums[i]!=target && ptr->next!=NULL)
            ptr=ptr->next;
      //  printf("111\n");
        if (ptr->next==NULL)
        {
            tmp=abs(nums[i])%MYKEY;
            ptr=&hash_t[tmp];
            // printf("%u\n",ptr);
            // printf("%d\n",(ptr-hash_t)/sizeof(struct node));
            while (ptr->next!=NULL)
                ptr=ptr->next;
            ptr->idx=i;
            ptr->data=nums[i];
            nextnode=(struct node *)malloc(sizeof(struct node));
            ptr->next=nextnode;
            
            //printf("%d\n",(hash_t+tmp)->data);
            nextnode->next=NULL;
            
        }
        else
        {
            //printf("%d\n",ptr->idx);
            a[0]=ptr->idx;
            a[1]=i;
            //printf("111\n");
            for (int i=MYKEY-1;i>=0;i--)
            {
                //printf("%d\n",i);
                ptr=(hash_t+i)->next;
                while (ptr!=NULL)
                {
                    nextnode=ptr;
                    ptr=ptr->next;
                    free(nextnode);
                }
            }
            free(hash_t);
            
            return a;
        }
    }
    return NULL;
}