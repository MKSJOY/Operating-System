#include<iostream> 

using namespace std; 
 
void wait_time(int proccesses[], int n, 
			int bt[], int wt[], int quantum) 
{
	int remain_burst_time[n]; 
	for (int i = 0 ; i < n ; i++) 
		remain_burst_time[i] = bt[i]; 
	int t = 0; 
	while (1) 
	{ 
		bool it = true; 
	
		for (int i = 0 ; i < n; i++) 
		{ 
			if (remain_burst_time[i] > 0) 
			{ 
				it = false; 
				if (remain_burst_time[i] > quantum) 
				{ 
					t += quantum; 
					remain_burst_time[i] -= quantum; 
				}
				else
				{ 
					t = t + remain_burst_time[i]; 
					wt[i] = t - bt[i]; 
					remain_burst_time[i] = 0; 
				} 
			} 
		} 
		if (it == true) 
		break; 
	} 
} 

void turn_around_time(int proccesses[], int n, 
						int bt[], int wt[], int tat[]) 
{ 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
void avg_time(int proccesses[], int n, int bt[], 
									int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	wait_time(proccesses, n, bt, wt, quantum); 
	turn_around_time(proccesses, n, bt, wt, tat); 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << "  " << i+1 << "\t\t\t" <<" "<< bt[i] <<"\t\t\t\t"
			<< wt[i] <<"\t\t\t\t" <<" "<< tat[i] <<endl; 
	} 
	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 
int main() 
{ 
int n, time_slice;
    cout<<"How Many proccesses do you want: ";
    cin>>n;
    int burst_time[n], priority_time[n], proccesses[n];
    int cmpletion_time[n], waiting_time[n];
    cout<<"\n Enter Burst Time of proccesses:";
    for(int i=0; i<n; i++){
        cout<<"\nproccess id ["<<i<<"]:";
        cin>>burst_time[i];
        proccesses[i]=i+1;
    }
    cout<<"Enter Time Quantam: ";
    cin>>time_slice; 
	avg_time(proccesses, n, burst_time, time_slice); 
	return 0; 
} 
