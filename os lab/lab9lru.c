#include <stdio.h>
void lru(int arr[],int size,int n)
{
    int counter=0,pf=0,frame[n],flag;
    int age[n];
    for(int i=0;i<n;i++)
    {
        frame[i]=-1;
        age[i]=0;

    }
    for(int i=0;i<size;i++)
    {
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==frame[j])
            {
                flag=1;
                age[j]=counter++;
                break;
            }
        }
        if(flag==0)
        {
            int min=0;
            for(int j=1;j<n;j++)
            {
                if(age[min]>age[j])
                {
                    min=j;
                }
            }
            frame[min]=arr[i];
            age[min]=++counter;
            pf++;
            for(int l=0;l<n;l++)
            {
                printf("%d \n",frame[l]);
            }
            printf("\n");

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
    lru(arr,size,n);
    
}