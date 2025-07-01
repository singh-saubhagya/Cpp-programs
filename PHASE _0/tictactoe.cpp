#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
int arr[3][3];
int moves[9]={0};
int temp[3];
void initialize()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]=0;
        }
    }
}
bool is_sequence_valid()
{
    
    for(int i=0;i<2;i++)
    {
        if(temp[i]!=temp[i+1])
        {
            return false;
        }
    }
    return true;
}
pair<bool,int> is_game_ended()
{
  bool flag=false;
  for(int row=0;row<3;row++)
  {
    for(int col=0;col<3;col++)
    {
        temp[col]=arr[row][col];
    }
    if(is_sequence_valid())
    {
        flag=true;
        return {flag,1};
    }
  }
  for(int col=0;col<3;col++)
  {
    for(int row=0;row<3;row++)
    {
        temp[row]=arr[row][col];
    }
    if(is_sequence_valid())
    {
        flag=true;
        return {flag,1};
    }
  }
  for(int diag=0;diag<3;diag++)
    {
        temp[diag]=arr[diag][diag];
    }
    if(is_sequence_valid())
    {
        flag=true;
        return {flag,1};
    }
    
  for(int diag=0;diag<3;diag++)
    {
        temp[diag]=arr[2-diag][diag];
    }
    if(is_sequence_valid())
    {
        flag=true;
       return {flag,1};
    }
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(arr[row][col]==0)
            {
                return {false,0};
            }
            else
            {
                flag=true;// no space is vacant now for moves to play
            }
        }
    }
    return {flag,0};

}
void print_state()
{
 for(int row=0;row<3;row++)
  {
    for(int col=0;col<3;col++)
    {
        cout<<arr[row][col];
        if(col==0|| col==1)
        {
            cout<<"|";
        }
    }
    cout<<endl;
    if(row!=2)
    {for(int col=0;col<3;col++)
    {
      if(col!=2)
      cout<<"_"<<"|";
      else
       cout<<"_";

    }
    cout<<endl;
}
    
  }
}
void available_moves()
{
for(int k=0;k<9;k++)
        {
            if(moves[k]==0)
            {
                switch(k)
                {
                    case 0:
                    cout<<"0: TL"<<tab;
                    break;
                    case 1:
                    cout<<"1: TM"<<tab;
                    break;
                    case 2:
                    cout<<"2: TR"<<tab;
                    break;
                    case 3:
                    cout<<"3: LM"<<tab;
                    break;
                    case 4:
                    cout<<"4: M"<<tab;
                    break;
                    case 5:
                    cout<<"5:RM"<<tab;
                    break;
                    case 6:
                    cout<<"6: BL"<<tab;
                    break;
                    case 7:
                    cout<<"7: BM"<<tab;
                    break;
                    case 8:
                    cout<<"8: BR"<<tab;
                    break;
                }
            }
           
        }
        cout<<endl;
}
void startgame()
{
    int i=rand()%2+1;
    print_state();
    for(int j=0;j<9;j++)
    {
        
        cout<<flush;
        cout<<endl<<"It's"<<tab<<i<<tab<<"chance to move"<<endl;
        cout<<flush;
        cout<<"available moves"<<endl;
        cout<<flush;
        available_moves();
        cout<<flush;
          int x;
          cin>>x;
          while(moves[x]==1)
          {
            cout<<flush;
            cout<<"Wrong move"<<endl;
             cout<<flush;
            available_moves();
             cout<<flush;
            cin>>x;
          }
          moves[x]=1;
          arr[x/3][x%3]=i;
          print_state();
          if(j>=4)
          {
            pair<bool,int> flag= is_game_ended();
            if(flag.first==true)
            {
                cout<<"GAME ENDS"<<endl;
                if(flag.second=1)
                {
                    cout<<endl<<"Game is won by "<<i<<endl;
                }
                else
                cout<<endl<<"Game tied"<<endl;
                return ;
            }
          }
          if(i==1)
          i=2;//changing turn
          else
          i=1;
          
    }
   
}
signed main()
{
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  startgame();

}