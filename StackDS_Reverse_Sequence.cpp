//reversal of values using stack data structure
#include <iostream>
#include <stack>
using namespace std;

stack<int> myStack;
int N;

void fillStack(){
    int input;
    for(int i = 0;i<N;i++){
        cout << "Enter a number into the sequence you wish to reverse: " <<endl;
        cin >> input;
        myStack.push(input);
    }
}

void printStack(){
    for(int i = 0;i < N; i++){
        cout << myStack.top()<< " ";
        myStack.pop();
    }
    cout << endl;
}

int main() {
    cout << "How many items to do wish to reverse?"<<endl;
    cin >> N;
    fillStack();
    printStack();
    return 0;
}
