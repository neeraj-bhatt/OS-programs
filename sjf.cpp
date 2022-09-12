#include <iostream>
#include <iomanip>
using namespace std;


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

//Selection Sorting
void sort(int arr[],int pId[], int n)
{
    int temp, tempId, min;
    for(int i=0; i<n-1; i++)
    {
        min = i;
        for(int j=i+1; j<n; j++)
            if(arr[j]<arr[i])
                min = j;
        //Process ID
        tempId = pId[i];
        pId[i] = min+1;
        pId[min] = tempId;
        //Process burst time
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void timecalc(int bt[], int wt[], int tat[], int n, float &twt, float &ttat)
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
    int nprcss, pId[10], bt[10], tat[10], wt[10];
    float ttat = 0, twt = 0;
    cout << "Enter the number of processes (max 10) : ";
    cin >> nprcss;
    cout << "Enter Burst time for each processes." << endl;
    for(int i=0; i<nprcss; i++)
    {
        pId[i] = i+1;
        cout << "(Burst Time) P[" << i+1 << "] : ";
        cin >> bt[i];
    }



    if(check(bt, nprcss) == 1)
    {
        sort(bt, pId, nprcss);
        timecalc(bt, wt, tat, nprcss, twt, ttat);
    }
    else
    {
        timecalc(bt, wt, tat, nprcss, twt, ttat);
    }
    cout << endl;
    cout << "===================== Processes Details =====================" << endl;
    cout << "Processes\t Burst Time\t Waiting Time\t Turn Around Time" << endl;
    for(int i=0; i<nprcss; i++)
    {
        cout << setw(5) << "P[" << pId[i] << "]\t " << setw(14) << bt[i] << "\t " << setw(14)<< wt[i] << "\t " << setw(14) << tat[i] << endl; 
    }
    cout << "Average Waiting Time = " << twt/nprcss << endl;
    cout << "Average TurnAround Time = " << ttat/nprcss << endl;
    return 0;
}