#include <bits/stdc++.h>
using namespace std;

// ensures only legal moves happen
void moveDisk(stack<int> &from, stack<int> &to, char s, char d) {
    // if source empty
    if(from.empty()) {
        int disk = to.top();
        to.pop();
        from.push(disk);
        cout << "Move disk " << disk << " from " << d << " to " << s << endl;
    }
    
    // if destination empty
    else if(to.empty()) {
        int disk = from.top();
        from.pop();
        to.push(disk);
        cout << "Move disk " << disk << " from " << s << " to " << d << endl;
    }
    
    // if source top > destination top; cannot place big rod on top of small
    else if(from.top() > to.top()) {
        int disk = to.top();
        to.pop();
        from.push(disk);
        cout << "Move disk " << disk << " from " << d << " to " << s << endl;
    }
    
    // normal move
    else {
        int disk = from.top();
        from.pop();
        to.push(disk);
        cout << "Move disk " << disk << " from " << s << " to " << d << endl;
    }
}

void towerOfHanoiIterative(int n) {
    stack<int> src, aux, dest; // stacks represent rods
    char S = 'S', A = 'A', D = 'D';

    // push disks into source
    for(int i = n; i >= 1; i--)
        src.push(i);

    int totalMoves = pow(2, n) - 1;

    // if even, swap aux and dest names
    if(n % 2 == 0) // move sequence changes for even disks
        swap(A, D);

    for(int i = 1; i <= totalMoves; i++) {
        // there are only 3 diff. pairs: S->D, S->A, A->D   
        if(i % 3 == 1)
            moveDisk(src, dest, S, D);

        else if(i % 3 == 2)
            moveDisk(src, aux, S, A);

        else
            moveDisk(aux, dest, A, D);
    }
}

int main() {

    int n = 3;
    towerOfHanoiIterative(n);

    return 0;
}
