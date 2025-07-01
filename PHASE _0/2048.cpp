#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
int arr[4][4];
int res[4];
/*
The main approach of this question is pointing out the 
critical part of the logic i.e what is the most difficult,
implicit part of the problem and how are you going to code it.
using fundamental approach and reuse code is also a thing we should keep in mind 
while writing code for a complex problem
*/

/*
More things to do in the code:
Improve the implementation of finding the random position in which the new no will be inserted after the state is changed.
*/
void generate_no()
{
    int i,j;
    i=rand()%4;
    j=rand()%4;
    while(arr[i][j]!=0)
    { 
    i=rand()%4;
    j=rand()%4;
    }
    if(rand()%2)
    {
        arr[i][j]=2;

    }
    else
    {
        arr[i][j]=4;

    }
    
}

void initialize()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            arr[i][j]=0;
        }
    }
    generate_no();
    generate_no();
}
void print_the_state()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
            cout<<arr[i][j]<<tab;
            else
            cout<<'.'<<tab;
        }
        cout<<endl;
    }
    cout<<endl;
}

void arrayafterswipe()
{
   
    int pn=3;
    
    for(int i=2;i>=0;i--)
    {
        if(res[i]!=0)
        {
            
                if(res[i]==res[pn])
                {
                    res[pn]*=2;
                    res[i]=0;
                    pn--;
                }
                else if (res[pn]==0)
                {
                    res[pn]=res[i];
                    res[i]=0;

                }
                else
                {
                    res[pn-1]=res[i];
                    pn--;
                    if(i!=pn)
                    res[i]=0;
                }
            

        }
    }
}
bool is_game_ended()
{
  bool flag=true;
  for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]==0)
            flag=false;
            else if(arr[i][j]==2048)
            { 
            flag=true;
            return flag;
            }
        }
    } 
    return flag;   
}
bool swipeleft()
{

    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            res[3-col]=arr[row][col];  
        }
        arrayafterswipe();
        for(int col=0;col<4;col++)
        {         
         arr[row][col]=res[3-col];
        }
        
    }
    return is_game_ended();

}

bool swiperight()
{
   
     for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            res[col]=arr[row][col];
            
            
        }
         arrayafterswipe();
         for(int col=0;col<4;col++)
         {
            arr[row][col]=res[col];
         }
         
    }
   return is_game_ended();
}

bool  swipeup()
{
     bool flag=false;
     for(int col=0;col<4;col++)
    {
        for(int row=0;row<4;row++)
        {
            res[3-row]=arr[row][col];
            
           
        }
        arrayafterswipe();
         for(int row=0;row<4;row++)
         {
             arr[row][col]=res[3-row];
         }
         
    }
   return {is_game_ended()};
}

bool swipedown()
{
    bool flag=false;
  for(int col=0;col<4;col++)
    {
        for(int row=0;row<4;row++)
        {
            res[row]=arr[row][col];
            
            
        }
        arrayafterswipe();
         for(int row=0;row<4;row++)
         {
             arr[row][col]=res[row];
         }
        
    }   
    return {is_game_ended()};
}
struct check_for_avail_moves// structure
{
    bool swipeleft()
    {
    bool flag=false;
    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            res[3-col]=arr[row][col];  
        }
        arrayafterswipe();
        for(int col=0;col<4;col++)
        {
            if(arr[row][col]!=res[3-col])
            {
                
                flag=true;//state change
                return flag;
            }
           

        }
        
    }
    return flag;

}

bool swiperight()
{
     bool flag=false;
     for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            res[col]=arr[row][col];
            
            
        }
         arrayafterswipe();
         for(int col=0;col<4;col++)
         {
            if(arr[row][col]!=res[col])
            {
                flag=true;
                return flag;
            }
            

         }
         
    }
   return flag;
}

bool  swipeup()
{
     bool flag=false;
     for(int col=0;col<4;col++)
    {
        for(int row=0;row<4;row++)
        {
            res[3-row]=arr[row][col];
            
           
        }
        arrayafterswipe();
         for(int row=0;row<4;row++)
         {
            if( arr[row][col]!=res[3-row])
            {
                flag=true;
                return flag;
            }
            
         }
         
    }
   return flag;
}

bool swipedown()
{
    bool flag=false;
  for(int col=0;col<4;col++)
    {
        for(int row=0;row<4;row++)
        {
            res[row]=arr[row][col];
            
            
        }
        arrayafterswipe();
         for(int row=0;row<4;row++)
         {
            if( arr[row][col]!=res[row])
            {
                flag=true;
                return flag;
            }
             
         }
        
    }   
    return flag;
}
};  

void startgame()
{
 char ch;
 while(1)
 {
map<char,int> moves;
print_the_state();
check_for_avail_moves x;
cout<<"What action do you want to take?";
if(x.swipeleft())
{
    moves['L']=1;
}
else
moves['L']=0;
if(x.swiperight())
{
    moves['R']=1;
}
else
moves['R']=0;
if(x.swipeup())
{
   moves['U']=1;
}
else
moves['U']=0;
if(x.swipedown())
{
    moves['D']=1;
}
else
moves['D']=0;
while(1)
{
    cout<<endl;
    for(pair<char,int> x:moves)
    {
        if(x.second==1)
        {
            cout<<x.first<<tab;
        }
        
    }
    cout<<endl;
    cout<<flush;
    cin>>ch;
    if(moves[ch]!=1)
    {
        cout<<"This move is not allowed , go for another available moves";
        continue;
    }
    else
    break;
 
}
    // cout<<endl;
    // cout<<flush;
    // cin>>ch;  
 bool flag;
 switch(ch)
 {
    case 'L':
    flag=swipeleft();
    break;
 
    case 'R':
    flag=swiperight();
    break;
 
    case 'U':
    flag=swipeup();
    break;
 
    case 'D':
    flag=swipedown();
    break;


    default :
    break;
 }
 if(flag == true )
 {cout<<endl<<"Game Ends"<<endl;
 break;}
 else
 generate_no();
  
 }
}
signed main()
{
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  initialize();
  startgame();

}
