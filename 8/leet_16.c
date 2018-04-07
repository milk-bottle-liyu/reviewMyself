/*
    the quick sort code is from:
        https://blog.csdn.net/zhengqijun_/article/details/53038831
*/
void swap(int *a, int *b)    
{  
    int temp;  
  
    temp = *a;  
    *a = *b;  
    *b = temp;  
  
    return ;  
}  

void quicksort(int array[], int begin, int end)  
{  
    int i, j;  
  
    if(begin < end)  
    {  
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！  
        j = end;        // array[end]是数组的最后一位  
            
        while(i < j)  
        {  
            if(array[i] > array[begin])  // 如果比较的数组元素大于基准数，则交换位置。  
            {  
                swap(&array[i], &array[j]);  // 交换两个数  
                j--;  
            }  
            else  
            {  
                i++;  // 将数组向后移一位，继续与基准数比较。  
            }  
        }  
  
        /* 跳出while循环后，i = j。 
         * 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin] 
         *                           -->  array[i+1] ~ array[end] > array[begin] 
         * 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。 
         * 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！ 
         */  
  
        if(array[i] >= array[begin])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！  
        {  
            i--;  
        }  
  
        swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]  
          
        quicksort(array, begin, i);  
        quicksort(array, j, end);  
    }  
}  

int threeSumClosest(int* nums, int numsSize, int target) 
{
    quicksort(nums,0,numsSize-1);
    int idx=0,front,rear;
    int looprc=nums[0]+nums[1]+nums[2]-target;
    int tmp;
    int rc=looprc;
    for (idx=0;idx<numsSize-2;idx++)
    {
        // printf("%d\n",idx);
        front=idx+1;
        rear=numsSize-1;
        looprc=nums[idx]+nums[front]+nums[rear]-target;
        while (front<rear )
        {
            if (abs(looprc) >= abs(nums[idx]+nums[front]+nums[rear]-target))
            {
                looprc=nums[idx]+nums[front]+nums[rear]-target;
            }
            
            if (nums[idx]+nums[front]+nums[rear]-target>=0)
                rear--;
            else
                front++;
        }
        if (abs(looprc)<abs(rc))
            rc=looprc;
    }
    return rc+target;
}