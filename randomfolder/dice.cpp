#include <iostream>
#include <vector>
#include <string>

using namespace std;

void roll_dice(int &top, int &front, int &right, int &left, int &back, int &bottom, char direction) {
    int temp;
    switch(direction) {
        case 'N':
            temp = top;
            top = front;
            front = bottom;
            bottom = back;
            back = temp;
            break;
        case 'S':
            temp = top;
            top = back;
            back = bottom;
            bottom = front;
            front = temp;
            break;
        case 'E':
            temp = top;
            top = left;
            left = bottom;
            bottom = right;
            right = temp;
            break;
        case 'W':
            temp = top;
            top = right;
            right = bottom;
            bottom = left;
            left = temp;
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    vector<int> results(T);
    
    for (int t = 0; t < T; ++t) {
        int A[6];
        for (int i = 0; i < 6; ++i) {
            cin >> A[i];
        }
        
        string S;
        cin >> S;
        
        int top = A[0], front = A[1], right = A[2], left = A[3], back = A[4], bottom = A[5];
        
        for (char command : S) {
            roll_dice(top, front, right, left, back, bottom, command);
        }
        
        results[t] = top;
    }
    
    for (int result : results) {
        cout << result << '\n';
    }
    
    return 0;
}
