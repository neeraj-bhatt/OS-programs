#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
    int a = fork();
    if(a == 0)
        cout << "Child Process." << endl;
    else
        cout << "Parent Process." << endl;

    return 0;
}