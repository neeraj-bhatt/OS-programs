#include <iostream>
#include <iomanip>
using namespace std;

class Sjf{
    public:
    int n;
    void timecalc(int bt[], int wt[], int tat[], int n, float &twt, float &ttat);
    void sort(int arr[], int pId[]);
};

int check (int bt[], int n)
{
    int flag = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(bt[i]>bt[j])
            {
                flag = 1;
                break; 
            }
            else
                continue;
        }            
    }
    return flag;
}

void Sjf :: sort(int bt[], int pId[]) 
{
    //selection sorting
    int temp, min;
    for(int i=0; i<n-1; i++)
    {
        min = i;
        for(int j=1; j<n; j++)
            if(bt[j] < bt[i])
                min = j;
        //process ID
        temp = pId[i];
        pId[i] = pId[min];
        pId[min] = temp;
        //burst time
        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;
    }
}

void Sjf :: timecalc(int bt[], int wt[], int tat[], int n, float &twt, float &ttat)
{
    //waiting time for 1st process is 0
    wt[0] = 0;
    for(int i=1; i<n; i++)
    {
        wt[i] = wt[i-1];
        wt[i] += bt[i-1];
        twt += wt[i];
    }

    //Calculating turn around time
    for(int i=0; i<n; i++)
    {
        tat[i] = wt[i] + bt[i];
        ttat += tat[i];
    }
}
int main()
{
    float ttat = 0, twt = 0;
    Sjf obj;
    cout << "Enter the number of processes (max 10) : ";
    cin >> obj.n;
    int pId[obj.n], bt[obj.n], tat[obj.n], wt[obj.n];
    cout << "Enter Burst time for each processes." << endl;
    for(int i=0; i<obj.n; i++)
    {
        pId[i] = i+1;
        cout << "(Burst Time) P[" << i+1 << "] : ";
        cin >> bt[i];
    }

    if(check(bt, obj.n) == 1)
    {
        obj.sort(bt, pId);
        obj.timecalc(bt, wt, tat, obj.n, twt, ttat);
    }
    else
    {
        obj.timecalc(bt, wt, tat, obj.n, twt, ttat);
    }
    cout << endl;
    cout << "===================== Processes Details =====================" << endl;
    cout << "Processes\t Burst Time\t Waiting Time\t Turn Around Time" << endl;
    for(int i=0; i<obj.n; i++)
    {
        cout << setw(5) << "P[" << pId[i] << "]" << setw(16) << bt[i] << setw(16)<< wt[i] << setw(16) << tat[i] << endl; 
    }
    cout << "Average Waiting Time = " << twt/obj.n << endl;
    cout << "Average TurnAround Time = " << ttat/obj.n << endl;
    return 0;
}