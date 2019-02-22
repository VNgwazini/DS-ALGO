//vector of variable length arrays
#include <iostream>
#include <vector>
#include <limits>

//using namespace std;

std::vector<std::vector<int> >myVector;

int N,q,arraySize;
int i,j;
//create and push vector
void addVector(){
std::vector<int> temp;
    int input;
    std::cout<<"Enter array size: "<<std::endl;
    std::cin >> arraySize;
    for(int i = 0; i<arraySize;i++){
        std::cout<<"Enter value for index "<< i << ": "<<std::endl;
        std::cin>>input;
        temp.push_back(input);
    }
    myVector.push_back(temp);
}
//print a value
void printValue(int i,int j){
    std::cout<<myVector[i][j]<<std::endl;
}

int main() {
    std::cout<<"Enter number of arrays 'space' number of queries"<<std::endl;;
    std::cin >> N >> q;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    for(int x = 0;x<q;x++){
        addVector();
    }

    for(int x = 0;x<q;x++){
    std::cout << "Enter index of Array: "<<std::endl;
    std::cin>>i;
    std::cout << "Enter index of Element: "<<std::endl;
    std::cin>>j;
    printValue(i,j);
    }
    
return 0;    
}
