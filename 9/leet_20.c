struct node
{
    char bracket;
    struct node * next;
};

bool isValid(char* s) 
{
    int idx=0;
    struct node * header=NULL,*tmp;
    int flag=1;
    while (s[idx]!='\0')
    {
        if (s[idx]=='(' || s[idx]=='[' || s[idx]=='{')
        {
            tmp=malloc(sizeof(struct node));
            tmp->bracket=s[idx];
            tmp->next=header;
            header=tmp;
        }
        else
        {
            if (header==NULL)
            {
                flag=0;
                break;
            }
            switch (s[idx])
            {
                case ')':
                    if (header->bracket=='(' )
                    {
                        // printf("asfsfsdaf\n");
                        tmp=header;
                        header=header->next;
                        free(tmp);
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    idx++;
                    continue;
                case ']':
                    if (header->bracket=='[' )
                    {
                        tmp=header;
                        header=header->next;
                        free(tmp);
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    idx++;
                    continue;
                case '}':
                    if (header->bracket=='{' )
                    {
                        tmp=header;
                        header=header->next;
                        free(tmp);
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    idx++;
                    continue;
            }
        }
        idx++;
        // printf("%d\n",flag);
    }
    
    if (header!=NULL)
        flag=0;
    while (header)
    {
        tmp=header;
        header=header->next;
        free(tmp);
    }
    
    return flag;
}