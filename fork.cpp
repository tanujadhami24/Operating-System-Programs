#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


using namespace std;
int main(){
    pid_t n;
    n = fork();
    
    if(n<0){
        perror("fork fail!!!");
        exit(1);
    }
    else if(n==0){
        cout << "I am child!!!";
    }
    else{
        cout << "Parent Process here!!!";
    }
    
return 0;
}   