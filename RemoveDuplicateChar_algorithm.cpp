//algorithm to remove duplicate char from string using nested loops and counters
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

//the function type must be of the same type as what i'm returning/// since that is a pointer to an array of char, the function must also be a pointer to an array----------any array is passed by 
char *removeDuplicates(char str[], int n){
    int index = 0;

    //use j to traverse the array index by index
    for (int j = 0; j < n;j++){

        //traverse the same array entirely by index each time the index changes in the j loop
        int k;   
        for ( k = 0; k < j; k++){
            //if the value at index j is equal to value at index k, do nothing and move on to the next index j. This is becuase the array at the time this nested loop is executed is already existent. Remember we are creating a new temporary array where we add a letter only if its the first time we encounter it in the loop. Meaning this specific loop will not get 

            if(str[j]==str[k]){

                    break;
                }
            } 
        //
        if(k == j){

            str[index++] = str[j];
            
            }
    }
    return str;
}


int main(){
    string inputString;
    cout << "Enter a string I will remove duplicates! Cool right?" << endl;
    cin >> inputString;
    //char str[] = "Vusumuzi Ngwazini";
    int l = inputString.length();
    //make an empty char array the size of the input string
    char char_array[l+1];

    //copy string elements to array
    strcpy(char_array, inputString.c_str());

    int n = sizeof(char_array)/sizeof(char_array[0]);
    //the moment we've all been waiting for....
    cout << removeDuplicates(char_array, n)<<endl;

    return 0;
}

