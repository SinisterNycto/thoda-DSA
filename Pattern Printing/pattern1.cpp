#include <bits/stdc++.h>
using namespace std;

/*
   A
  ABA
 ABCBA
ABCDCBA
*/

int main()
{
    int n = 4;
    
    for(int i = 0; i < n; i++){
        // spaces order: 3 2 1
        for(int j = 0; j < n - 1 - i; j++){
            cout << " ";
        }
        
        // letters order: 1 3 5 7
        char ch = 'A';
        int breakpoint = ((2 * i) + 1) / 2;
        for(int j = 0; j < (2 * i) + 1; j++){
            cout << ch;
            if(j >= breakpoint){
                ch--;
            }
            else ch++;
        }
        
        // spaces order: 3 2 1
        for(int j = 0; j < n - 1 - i; j++){
            cout << " ";
        }
        
        cout << endl;
    }
    

    return 0;
}
