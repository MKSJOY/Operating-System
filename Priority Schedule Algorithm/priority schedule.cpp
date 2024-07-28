#include <iostream>

using namespace std;

int main(){
    int n, pos, temp;
    cout<<"How Many proccesses do you want: ";
    cin>>n;
    int burst_time[n], priority_time[n], proccess[n];
    int cmpletion_time[n], waiting_time[n];
    cout<<"\n Enter Burst Time and Priority Time of proccesses:";
    for(int i=0; i<n; i++){
        cout<<"\nproccess id ["<<i<<"]:";
        cin>>burst_time[i]>>priority_time[i];
        proccess[i]=i+1;
    }
    
    for(int i=0;i<n;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(priority_time[j]<priority_time[pos])
                pos=j;
        }
        temp=priority_time[i];
        priority_time[i]=priority_time[pos];
        priority_time[pos]=temp;
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
        temp=proccess[i];
        proccess[i]=proccess[pos];
        proccess[pos]=temp;
    }
   
    for(int i=0; i<n; i++){
        if(i==0){
        cmpletion_time[i]=burst_time[i];
        }
        else{
        cmpletion_time[i]=cmpletion_time[i-1]+burst_time[i];
        }
    }
    
    for(int i=0; i<n; i++){
        waiting_time[i]=cmpletion_time[i]-burst_time[i];
    }
    
    cout<<"\n\nproccess id"<<"\t"<<"burst_time"<<"\t"<<"cmpletion_time"<<"\t"<<"turn_around_time"<<"\t"<<"waiting_time";
    for(int i=0; i<n; i++){
        cout<<"\nproccess["<<i<<"]:";
        cout<<"\t"<<burst_time[i]<<"\t\t\t"<<" "<<cmpletion_time[i]<<"\t\t\t\t"<<cmpletion_time[i]<<"\t\t\t\t\t"<<waiting_time[i];
    }
    double TA=0, WT=0;
    for(int i=0; i<n; i++){
        TA=TA+cmpletion_time[i];
        WT=WT+waiting_time[i];
    }
    cout<<"\n\nAverage Turn Around Time: "<<(TA/n)<<"\nAverage Waiting Time: "<<(WT/n);
    return 0;
}
S