#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main()
{
    int a;
    cout << "Enter a number : ";
    cin >> a;
    fork();
    if(a%2 == 0)
        cout << a << " is even." << endl;
    else 
        cout << a << " is odd." << endl;

    return 0;
}