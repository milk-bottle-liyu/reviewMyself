int evalRPN(char** tokens, int tokensSize)
{
    if (tokensSize==0)
        return 0;
    
    int stack[5000],top=0,tmp,idx;
    for (int i=0;i<tokensSize;i++)
    {
        switch (tokens[i][0])
        {
            case '+':
                top--;
                stack[top-1]=stack[top-1]+stack[top];
                continue;
            case '*':
                top--;
                stack[top-1]=stack[top-1]*stack[top];
                continue;
            case '/':
                top--;
                stack[top-1]=stack[top-1]/stack[top];
                continue;
            case '-':
                if (tokens[i][1]=='\0')
                {
                    top--;
                    stack[top-1]=stack[top-1]-stack[top];
                    continue;
                }
            default:
                tmp=0;
                if (tokens[i][0]=='-')
                    idx=1;
                else
                    idx=0;
                while (tokens[i][idx]!='\0')
                {
                    tmp=tmp*10+tokens[i][idx]-'0';
                    idx++;
                }
                if (tokens[i][0]=='-')
                    tmp=0-tmp;
                stack[top]=tmp;
                top++;
        }
    }
    
    return stack[0];
    
}