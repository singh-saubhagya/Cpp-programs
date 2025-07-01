#include<stdio.h>
void fifo(int arr[],int size,int n)
{
    int frame[n],pf=0;
    for(int i=0;i<n;i++)
    {
        frame[i]=-1;
    }
    int counter=0,flag;
    for(int i=0;i<size;i++)
    {
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(frame[j]==arr[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[counter]=arr[i];
            counter=++counter%n;
            pf++;
        }
    }
    printf("The no of page faults is %d",pf);
}
int main()
{
    int arr[100],n,size;
    printf("Enter the frame size \t");
    scanf("%d",&n);
    printf("Enter the no of pages \t");
    scanf("%d",&size);
    printf("Enter the page no \n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
   fifo(arr,size,n);
    
}