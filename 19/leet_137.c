#define MYKEY 39271

struct node
{
    int val;
    int count;
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
        if (nums[i]==-2147483648)
        {
            tmp=abs(nums[i]+MYKEY)%(int)MYKEY;
            printf("%d:%d ",i+1,tmp);
        }
        else
            tmp=abs(nums[i])%(int)MYKEY;
        
        if (hash_t[tmp]==NULL)
        {
            hash_t[tmp]=malloc(sizeof(struct node));
            hash_t[tmp]->val=nums[i];
            hash_t[tmp]->count=1;
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
            // if (ptr==hash_t[tmp])
            // {
            //     hash_t[tmp]=ptr->next;
            // }
            // else
            // {
            //     recorder->next=ptr->next;
            // }
            // free(ptr);
            ptr->count++;
        }
        else
        {
            recorder->next=malloc(sizeof(struct node));
            recorder->next->val=nums[i];
            recorder->next->next=NULL;
            recorder->next->count=1;
        }
        
    }
    
    int rc=0;
    for (int i=0;i<MYKEY;i++)
        if (hash_t[i]!=NULL)
        {
            ptr=hash_t[i];
            while (ptr )
            {
                if (ptr->count==1)
                    rc=ptr->val;
                recorder=ptr->next;
                free(ptr);
                ptr=recorder;
            }
        }
    return rc;
}