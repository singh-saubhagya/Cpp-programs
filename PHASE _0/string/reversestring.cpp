#include<bits/stdc++.h>
using namespace std;

//This is the most optimal solution without creating any string object creation 
//2nd optimal solution might be when using char array to store string
struct rvsstring{
string str;
void reverse(int st,int en)
{
    while(st<en)
    {
        char ch=str[en];
        str[en]=str[st];
        str[st]=ch;
        en--;
        st++;
    }
}
};
int main()
{   
    rvsstring random;
    string str1;
    int st=0;
    getline(cin,random.str);
    for(int i=0;i<=random.str.size();i++)
    {
     if( i==random.str.size() || random.str[i]==' ' )
    { 
     random.reverse(st,i-1);
     st=i+1;
    }
    
    }
    cout<<random.str;
}


// the below program will give tle for large strings due to string concatenation which takes O(n) n:length of the string
// so never use concatenation inside a loop as concatenation creates object of string class which takes time to get created and then copying .
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     string temp, str1, str;
//     getline(cin, str);
//     for (int i = 0; i <= str.size(); i++) {
//         if (i != str.size() && str[i] != ' ')
            
//             temp = str[i] + temp; 
//         else {
//             str1 = str1 + " " + temp;
//             temp.clear();
//         }
//     }
//     str1.erase(0, 1);
//     cout << str1;
// }