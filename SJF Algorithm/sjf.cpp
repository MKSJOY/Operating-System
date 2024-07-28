#include <iostream>

using namespace std;

int main(){

	int arr[100][4];
	int n, index, temp;
	float total=0, AWT, ATA;

	cout<<"How Many proccesses do you want: ";
	cin>>n;

	cout<<"Enter Burst Time of proccesses:"<<endl;
	for(int i=0; i<n; i++){
		cout<<"P"<<i+1<<": ";
		cin>>arr[i][1];
		arr[i][0]=i+1;
	}

	for(int i=0; i<n; i++){
		index=i;
		for(int j=i+1; j<n; j++)
			if(arr[j][1]<arr[index][1])
				index=j;
		temp=arr[i][1];
		arr[i][1]=arr[index][1];
		arr[index][1]=temp;

		temp=arr[i][0];
		arr[i][0]=arr[index][0];
		arr[index][0]=temp;
	}

	arr[0][2]=0;
	for(int i=1; i<n; i++){
		arr[i][2]=0;
		for(int j=0; j<i; j++)
			arr[i][2]=arr[i][2]+arr[j][1];
		    total=total+arr[i][2];
	}

	AWT=(float)total/n;
	total=0;
	cout<<"P  BT  WT TAT" << endl;

	for(int i=0; i<n; i++){
		arr[i][3]=arr[i][1]+arr[i][2];
		total= total+arr[i][3];
		cout<<"P"<<arr[i][0]<<"\t"<<arr[i][1]<<"\t"<<arr[i][2]<<" "<< arr[i][3]<<endl;
	}

	ATA=(float)total/n;
	cout<<"Average Turnaround Time= "<<ATA<<endl;
	cout<<"Average Waiting Time= "<<AWT<<endl;
}
