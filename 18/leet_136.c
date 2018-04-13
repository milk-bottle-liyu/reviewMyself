#define MYKEY 39271

struct node
{
    int val;
    struct node * next;
};

int singleNumber(int* nums, int numsSize)
{
    printf("%d\n",numsSize);
    if (numsSize==0)
        return 0;
    struct node * hash_t[MYKEY];
    for (int i=0 ;i<MYKEY;i++)
        hash_t[i]=NULL;
    
    int tmp;
    struct node *ptr,*recorder;
    for (int i=0;i<numsSize;i++)
    {
        // printf("%d ",i);
        tmp=abs(nums[i])%MYKEY;
        if (hash_t[tmp]==NULL)
        {
            hash_t[tmp]=malloc(sizeof(struct node));
            hash_t[tmp]->val=nums[i];
            hash_t[tmp]->next=NULL;
            
            continue;
        }
        ptr=hash_t[tmp];
        recorder=ptr;
        while (ptr!=NULL && ptr->val!=nums[i])
        {
            recorder=ptr;
            ptr=ptr->next;
        }
        if (ptr!=NULL)
        {
            // printf("%d:%d\n",i,nums[i]);
            if (ptr==hash_t[tmp])
            {
                hash_t[tmp]=ptr->next;
            }
            else
            {
                recorder->next=ptr->next;
            }
            free(ptr);
        }
        else
        {
            recorder->next=malloc(sizeof(struct node));
            recorder->next->val=nums[i];
            recorder->next->next=NULL;
        }
        
    }
    
    int rc=0;
    for (int i=0;i<MYKEY;i++)
        if (hash_t[i]!=NULL)
        {
            printf("%d\n",i);
            rc=hash_t[i]->val;
            free(hash_t[i]);
            return rc;
        }
    return 0;
}