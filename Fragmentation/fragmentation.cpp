#include<bits/stdc++.h>

using namespace std;


int main(){
int n, m, j;
cout<<"Enter the number of memory: ";
cin>>m;
cout<<"Enter the number of file: ";
cin>>n;
int memory[m], file[n], result[n];
cout<<"Enter Memory Sizes: ";
for(int i=0; i<m; i++){
    cin>>memory[i];
}
cout<<"Enter File Sizes: ";
for(int i=0; i<n; i++){
    cin>>file[i];
}

/*for(int i=0; i<m; i++){
    cout<<memory[i]<<" ";
}
cout<<endl;
for(int i=0; i<m; i++){
    cout<<file[i]<<" ";
}*/

cout<<endl<<"First Fit: "<<endl;
int frag_f = 0;
for(j=0; j<m; j++){
    int flg[j] = {0};
    for(int i=0; i<n; i++){
    if(flg[j]==0){
    if(file[i]<=memory[j]){
    cout<<"File "<<file[i]<<" -> "<<memory[j];
    result[i] = memory[j] - file[i];
    frag_f = frag_f + result[i];
    flg[j] =1;
    file[i] = file[i+1];
    cout<<endl;
    }
    }
    }
}
cout<<"Total Fragmentation: "<<frag_f;



cout<<"\n\nWorst Fit:"<<endl;
int frag_w = 0;
sort(memory, memory+m, greater<int>());
for(int j=0; j<m; j++){
    int flg[j] = {0};
    for(int i=0; i<n; i++){
    if(flg[j]==0){
    if(file[i]<=memory[j]){
    cout<<"File "<<file[i]<<" -> "<<memory[j];
    result[i] = memory[j] - file[i];
    frag_w = frag_w + result[i];
    flg[j] =1;
    file[i] = file[i+1];
    cout<<endl;
    }
    }
    }
}
cout<<"Total Fragmentation: "<<frag_w;

int dif = frag_w - frag_f;
cout<<"\nThe differences between total fragmentations: "<<dif;

return 0;
}
