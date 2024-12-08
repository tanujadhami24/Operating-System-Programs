
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    int sumeven = 0, sumodd = 0, i;
    pid_t n = fork();  // Create a child process

    if (n < 0) { 
        // Fork failed
        cerr << "Fork failed!" << endl;
        return 1;
    } 
    else if (n > 0) { 
        // Parent process
        for (i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                sumeven += i;
            }
        }
        cout << "Parent Process!!!" << endl;
        cout << "Sum of even numbers = " << sumeven << endl;
    } 
    else { 
        // Child process
        for (i = 0; i < 10; i++) {
            if (i % 2 != 0) {
                sumodd += i;
            }
        }
        cout << "Child Process!!!" << endl;
        cout << "Sum of odd numbers = " << sumodd << endl;
    }

    return 0;
}
