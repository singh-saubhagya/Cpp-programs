#include<stdio.h>
void optimal(int arr[],int size,int n)
{
    int flag1,flag2,flag3,counter=0,pf=0;
    int frame[n],age[n];
    for(int i=0;i<n;i++)
    {
        frame[i]=-1;
        age[i]=0;
    }
    for(int i=0;i<size;i++)
    {   
        flag1=0,flag2=0;
        for(int j=0;j<n;j++)
        {
            if(frame[j]==arr[i])
            {
                flag1=1;
                flag2=1;
                
                break;
            }
        }
        if(flag2==0)
        {
            
            for(int k=0;k<n;k++)
            {
                if(frame[k]==-1)
                {
                    frame[k]=arr[i];
                    flag1=1;
                    pf++;
                      for(int l=0;l<n;l++)
            {
                printf("%d \n",frame[l]);
            }
            printf("\n");
                    break;

                }
            }
        }
        if(flag1==0)
        {
            int x;
            for(int m=i+1;m<size;m++)
            {
            for(int k=0;k<n;k++)
            {
                x=0;
                
                    if(frame[k]==arr[m])
                    {
                        age[k]=++counter;
                        x=1;
                        break;
                    }
                }
                if(x==0)
                {
                    age[m]=-1;//not found;
                }
            }
            for(int k=0;k<n;k++)
            {
                if(age[k]==-1)
                {
                    frame[k]=arr[i];
                    flag3=1;
                    break;
                }

            }
            if(flag3==0)
            {
             int max=0;
                for(int m=1;m<n;m++)
                {
                    if(age[max]<age[m])
                    max=m;
                }
                frame[max]=arr[i];
            }
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
    optimal(arr,size,n);
    
}