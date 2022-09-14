#include <iostream>
#include <iomanip>
using namespace std;

class Fcfs{
    public:
    int n;
    void waitingt(int wt[], int bt[], float &twt);
    void turnaroundt(int tt[], int bt[], int wt[], float &ttat);
};

void Fcfs :: waitingt(int wt[], int bt[], float &twt)
{
    wt[0] = 0; //waiting time for first process is 0
    for(int i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        twt += wt[i];
    }
}
void Fcfs :: turnaroundt(int tat[], int bt[], int wt[], float &ttat)
{
    for(int i=0; i<n; i++)
    {
        tat[i] = wt[i] + bt[i];
        ttat += tat[i];
    }
}

int main()
{
    Fcfs obj;
    float ttat = 0, twt = 0;
    cout << "Enter the number of processes : ";
    cin >> obj.n;
    int bt[obj.n], tat[obj.n], wt[obj.n];
    cout << "Enter Burst time for each processes." << endl;
    for(int i=0; i<obj.n; i++)
    {
        cout << "(Burst Time) P[" << i+1 << "] : ";
        cin >> bt[i];
    }
    obj.waitingt(wt, bt, twt);
    obj.turnaroundt(tat, bt, wt, ttat);
    cout << endl;
    cout << "===================== Processes Details =====================" << endl;
    cout << "Processes\t Burst Time\t Waiting Time\t Turn Around Time" << endl;
    for(int i=0; i<obj.n; i++)
    {
        cout << setw(5) << "P[" << i+1 << "] " << setw(16) << bt[i] << setw(16) << wt[i] << setw(16) << tat[i] << endl; 
    }
    cout << "Average Waiting Time = " << twt/obj.n << endl;
    cout << "Average TurnAround Time = " << ttat/obj.n << endl;
    return 0;
}