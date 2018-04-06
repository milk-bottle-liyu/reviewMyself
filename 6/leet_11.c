#define min(x,y) x<y?x:y
#define max(x,y) x<y?y:x

int maxArea(int* height, int heightSize) 
{
    int tmp=0;
    
    int left=0,right=heightSize-1;
    while (left<right)
    {
        
        if ((min(height[left],height[right]))*(right-left)>tmp)
            tmp=(min(height[left],height[right]))*(right-left);
        
        if (height[left]<height[right])
            left++;
        else
            right--;
    }
    
    return tmp;
    
}