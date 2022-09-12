#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int nprcss, bt[10], tat[10], wt[10];
    float ttat = 0, twt = 0;
    cout << "Enter the number of processes (max 10) : ";
    cin >> nprcss;
    cout << "Enter Burst time for each processes." << endl;
    for(int i=0; i<nprcss; i++)
    {
        cout << "(Burst Time) P[" << i+1 << "] : ";
        cin >> bt[i];
    }


    //waiting time for 1st process is 0
    wt[0] = 0;
    for(int i=1; i<nprcss; i++)
    {
        wt[i] = wt[i-1];
        wt[i] += bt[i-1];
        twt += wt[i];
    }

    //Calculating turn around time
    for(int i=0; i<nprcss; i++)
    {
        tat[i] = wt[i] + bt[i];
        ttat += tat[i];
    }
    cout << endl;
    cout << "===================== Processes Details =====================" << endl;
    cout << "Processes\t Burst Time\t Waiting Time\t Turn Around Time" << endl;
    for(int i=0; i<nprcss; i++)
    {
        cout << setw(5) << "P[" << i+1 << "]\t " << setw(14) << bt[i] << "\t " << setw(14)<< wt[i] << "\t " << setw(14) << tat[i] << endl; 
    }
    cout << "Average Waiting Time = " << twt/nprcss << endl;
    cout << "Average TurnAround Time = " << ttat/nprcss << endl;
    return 0;
}