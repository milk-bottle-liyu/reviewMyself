typedef struct {
    int maxSize;
    int top;
    int * data;
    int * mindata;
} MinStack;

#define quickWay 1

#if quickWay==1

MinStack* minStackCreate(int maxSize) {
    MinStack * rc;
    rc=(MinStack *)malloc(sizeof(MinStack));
    rc->maxSize=maxSize;
    rc->data=(int *)malloc(sizeof(int)*maxSize);
    rc->mindata=(int *)malloc(sizeof(int)*maxSize);
    rc->top=0;
    return rc;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top < obj->maxSize)
    {
        obj->data[obj->top]=x;
        if (obj->top==0)
        {
            obj->mindata[0]=x;
        }
        else
        {
            obj->mindata[obj->top]=obj->mindata[obj->top-1]>x?x:obj->mindata[obj->top-1];
        }
        obj->top++;
    }
    return;
}

void minStackPop(MinStack* obj) {
    if (obj->top>0)
    {
        obj->top--;
    }
    
}

int minStackTop(MinStack* obj) {
    if (obj->top==0)
        return 0;
    else
    {
        return obj->data[obj->top-1];
    }
    return 0;
    
}

int minStackGetMin(MinStack* obj) {
        int rc;
    if (obj->top==0)
        return 0;
    else
    {
        return obj->mindata[obj->top-1];
    }
    return rc;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}

#elif
/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack * rc;
    rc=(MinStack *)malloc(sizeof(int)*2+sizeof(int*));
    rc->maxSize=maxSize;
    rc->data=(int *)malloc(sizeof(int)*maxSize);
    rc->top=0;
    return rc;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top < obj->maxSize)
    {
        obj->top++;
        obj->data[obj->top-1]=x;
    }
    return;
}

void minStackPop(MinStack* obj) {
    if (obj->top>0)
    {
        obj->top--;
    }
    
}

int minStackTop(MinStack* obj) {
    if (obj->top==0)
        return 0;
    else
    {
        return obj->data[obj->top-1];
    }
    return 0;
    
}

int minStackGetMin(MinStack* obj) {
        int rc;
    if (obj->top==0)
        return 0;
    else
    {
        rc=obj->data[0];
        for (int i=1;i<obj->top;i++)
        {
            if (obj->data[i]<rc)
                rc=obj->data[i];
        }
    }
    return rc;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}

#endif
/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */