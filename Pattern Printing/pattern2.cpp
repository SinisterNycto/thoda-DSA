/*  

*
**
***
****
*****
****
***
**
*


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int breakpoint = (2 * n - 1) / 2; // from this point, start in decreasing order
    
    for(int i = 0; i < (2 * n) - 1; i++){
        if(i <= breakpoint){
            for(int j = 0; j <= i; j++){
                cout << '*';
            }
        }
        
        else{
            for(int j = 0; j < (2 * n) - 1 - i; j++){
                cout << '*';
            }
        }
        cout << endl;
    }
    
    return 0;
}
