#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int m, n;
    cout << "How many memory block you have: ";
    cin >> m;
    int memory[m];
    for (int i = 0; i < m; i++) {
        cin >> memory[i];
    }
    sort(memory, memory + m);
    cout << "\nMemory Block: ";
    for (int i = 0; i < m; i++) {
        cout << memory[i] << " ";
    }
    cout << "\nHow many memory file you have: ";
    cin >> n;
    int file[n];
    for (int i = 0; i < n; i++) {
        cin >> file[i];
    }
    cout << "\nFile: ";
    for (int i = 0; i < n; i++) {
        cout << file[i] << " ";
    }
    cout << endl;
    int sum = 0;
    int allocated[m] = {0};
    for (int i = 0; i < n; i++) {
        bool allocate = false;
        for (int j = 0; j < m; j++) {
            if (file[i] <= memory[j] && allocated[j] == 0) {
                cout << file[i] << " -> " << memory[j] << endl;
                int result = memory[j] - file[i];
                sum = sum + result;
                allocated[j] = 1;
                allocate = true;
                break;
            }
        }
        if (!allocate) {
            cout << "\nInvalid: No memory block for file " << file[i] << endl;
        }
    }
    cout << "\nTotal Fragmentation: " << sum;

    return 0;
}
