#include <iostream>
using namespace std;

class node{
    public:
    int pId;
    int arrivalT;
    int burstT;
    int waitingT;
    int turnAt;
    node* next;
    node(){}
    node(int id, int at, int bt){
        arrivalT = at;
        burstT = bt;
        pId = id;
        waitingT = 0;
        turnAt = 0;
        next = 0;
    }
};


void displayPrcs(node* head){
    cout << "-------Processes-------" << endl;
    cout << "Process \tArrivalTime \tBurstTime" << endl;
    while(head != NULL){
        cout << "P[" << head->pId << "] : \t\t" << head->arrivalT << " \t\t" << head->burstT << endl;
        head = head->next;
    }
}

void displayCalc(node* head){
    cout << "===============Processes===============" << endl;
    cout << "Process \tArrivalTime \tBurstTime \tWaitingTime \tTurnAroundTime"<< endl;
    while(head != NULL){
        cout << "P["<<head->pId << "] :\t\t"<<head->arrivalT<<"\t\t"<<head->burstT<<"\t\t"<<head->waitingT<<"\t\t"<<head->turnAt << endl;
        head = head->next;
    }
}

node* timeCalc(node* head, float &avgwtime, float &avgttime){
    node* ptr = head;
    node* p = NULL;
    int count = 1;
    if(ptr->arrivalT == 0)
        ptr->waitingT = 0;
    else
        ptr->waitingT = ptr->arrivalT;
    ptr->turnAt = ptr->burstT;
    avgwtime = ptr->waitingT;
    avgttime = ptr->turnAt;
    while(ptr->next != NULL){
        p = ptr;
        ptr = ptr->next;
        ptr->waitingT = p->waitingT + p->burstT;
        ptr->turnAt = ptr->waitingT + ptr->burstT;
        avgwtime += ptr->waitingT;
        avgttime += ptr->turnAt;
        count++;
    }
    avgwtime = avgwtime/count;
    avgttime = avgttime/count;
    return head;
}
node* insertLL(node* head){
    int at, bt;
    int pcount = 1;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        cout << "Enter Arrival Time P[" << pcount << "] : ";
        cin >> at;
        cout << "Enter Burst Time P[" << pcount << "] : ";
        cin >> bt;
        node* t = new node(pcount, at, bt);
        if(head == NULL)
            head = t;
        else{
            node* ptr = head;
            node* p = NULL;
            if(at < ptr->arrivalT || (at == ptr->arrivalT && bt < ptr->burstT)){
                t->next = head;
                head = t;
            }
            else{
                while(at > ptr->arrivalT && ptr->next != NULL){
                    p = ptr;
                    ptr = ptr->next;
                }
                while(at == ptr->arrivalT && bt >= ptr->burstT && ptr->next != NULL){
                    p = ptr;
                    ptr = ptr->next;
                }
                if(at > ptr->arrivalT || (at == ptr->arrivalT && bt >= ptr->burstT)){
                    ptr->next = t;
                }
                else{
                    p->next = t;
                    t->next = ptr;
                }
            }
        }
        pcount += 1;
        cout << "y to continue(anything else to exit) : ";
        cin >> ch;

    }
    displayPrcs(head);
    return head;
}

int main(){
    node* head = NULL;
    float avgwtime = 0;
    float avgttime = 0;
    head = insertLL(head);
    cout << "\nCalculating Waiting Time and TurnAround Time" << endl;
    head = timeCalc(head, avgwtime, avgttime);
    displayCalc(head);
    cout << endl;
    cout << "Average Waiting time = " << avgwtime << endl;
    cout << "Average TurnAround time = " << avgttime << endl;
    return 0;
}