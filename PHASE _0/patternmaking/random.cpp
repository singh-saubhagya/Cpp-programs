#include<bits/stdc++.h>
using namespace std;
double x=1.41;
int  counttt=0;
double roundToDecimalPlaces(double value, int decimalPlaces) {
    double factor = pow(10.0, decimalPlaces);
    return round(value * factor) / factor;
}
void printpattern(double r,double c,double i,double j)
{
   double I,J;
   I=i/x - j/x;
   J=j/x + i/x;
//    //I=roundToDecimalPlaces(I,2);
  double tolerance = 1e-2; // Define a tolerance for floating-point comparison
    if (abs(I - 1.00) < tolerance /*||abs(I - 2.00) < tolerance*/) 
    {
        counttt++;
        cout<<'*';
    }
    else
     cout<<" ";
  }


int main()
{
    double r,c;
   // cin>>r>>c;
   r=3;
   c=3;
   
    for(double i=0;i<=r;i=i+0.01)
    {
        for(double j=0;j<=c;j=j+0.01)
        {
            printpattern(r,c,i,j);

        }
        cout<<endl;
    }
    cout<<endl<<counttt;
}