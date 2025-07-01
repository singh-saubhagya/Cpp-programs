#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    double result;
    char op;
    cout<<"Enter the two intergers"<<endl;
    cin>>x>>y;
    cout<<"Type the symbol of the operation which you have to performed "<<endl;
    cin>>op;
    switch(op)
    {
        case '+':
        result = x+y;        cout<<"The addition of "<<x<<" and "<<y<<" are "<<result<<endl;
        break;
        case '-':
        result=x-y;
        cout<<"The subtraction of"<<x<<" and "<<y<<" are "<<result<<endl;
        break;
        case '*':
        result=x*y;
        cout<<"The multiplication of"<<x<<" and "<<y<<" are "<<result<<endl;
        break;
        case '/':
        
        result=(double(x))/y;
        cout<<"The division of"<<x<<" and "<<y<<" are "<<result<<endl;
        break;
        case '%':
        result=x%y;
        cout<<"The modulus of"<<x<<" and "<<y<<" are "<<result<<endl;
        break;
        default:
        cout<<"The input operator is not valid "<<endl;

    }
}