#include <bits/stdc++.h>
using namespace std;
 
// Function to print the
// element in queue
void printQueue(queue<int>& Q)
{
    // Traverse the stack
    while (!Q.empty()) {
 
        // Print top element
        cout << Q.front() << ' ';
 
        // Pop top element
        Q.pop();
    }
}
 
// Driver Code
int main()
{
    // Initialise queue
    queue<int> Q;
 
    // Insert element
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
 
    // Print elements
    printQueue(Q);
    return 0;
}