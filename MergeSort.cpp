#include <iostream>
using namespace std;

//use the middle position to join the two smaller lengthed arrays
void mergeArrays(int inputArray[], int leftMostSide, int middle, int rightMostSide){
    
    //create looping variables so each loop can keep tabs on the other
    int loopLeft,loopRight,mainArrayIndex;
    
    //create varibles to store the size of the new arrays
    int sizeofLeft = middle - leftMostSide + 1;
    int sizeofRight = rightMostSide - middle;

   //create temporary arrays to merge later
    int tempLeft[sizeofLeft],tempRight[sizeofRight];

    //fill left and right temp arrays by looping through the passed array and splitting it
    for (loopLeft = 0;loopLeft < sizeofLeft;loopLeft++)
        //start from the left most index [leftMostSide + 0] and stop at the middle..including the middle
        tempLeft[loopLeft] = inputArray[leftMostSide + loopLeft];
        cout << "Temp Left: ["<< loopLeft<<"] = "<< "["<<tempLeft[loopLeft] << "]"<<endl;
    

    //continue at the position just after the middle index and finish the array
    for (loopRight = 0; loopRight < sizeofRight; loopRight++)
        tempRight[loopRight] = inputArray[middle + 1 + loopRight];
        cout << "Temp Right: ["<< loopRight<<"] = "<< "["<<tempRight[loopRight] << "]"<<endl;

    

    loopLeft = 0;
    loopRight = 0;
    mainArrayIndex = leftMostSide;

    //fill populate the array sorted
    //compare the each position in the subarrays and replace the elements in the original array with the corect value
    while(loopLeft < sizeofLeft && loopRight < sizeofRight){

        //store smaller number from left
        if(tempLeft[loopLeft] <= tempRight[loopRight]){
            inputArray[mainArrayIndex] = tempLeft[loopLeft];
            loopLeft++;
        }
        
        //if larger, store from right
        else{
            inputArray[mainArrayIndex] = tempRight[loopRight];
            loopRight++;
        }
        //move to next position in main array
        mainArrayIndex++;
    }
        //if you havent reached the end of the left array, finish up
    while(loopLeft < sizeofLeft){
        inputArray[mainArrayIndex] = tempLeft[loopLeft];
        loopLeft++;
        mainArrayIndex++;
    }

    //if we havent reached the end of the right array, finish up
    while(loopRight < sizeofRight){
        inputArray[mainArrayIndex] = tempRight[loopRight];
        loopRight++;
        mainArrayIndex++;
    }
    
}
//this function packages the data nicely so the merge fucntion works better
void sortArrays(int inputArray[], int leftMostIndex, int rightMostIndex){

    if(leftMostIndex < rightMostIndex){

        // find the middle of the array
        int middleIndex = leftMostIndex + (rightMostIndex-leftMostIndex)/2;

        //now sort the leftMostside to middle
        sortArrays(inputArray, leftMostIndex, middleIndex);
        //sort right of middle to right most side
        sortArrays(inputArray, middleIndex+1, rightMostIndex );
        //merge both sides
        mergeArrays(inputArray, leftMostIndex, middleIndex, rightMostIndex);

    }
}
//print our answer...that is hopefully sorted
void printSortedArray(int inputArray[], int arraySize){
    
    int i;
    for ( i =0; i < arraySize; i++){
        cout << inputArray[i];
    }
    cout << endl;
}

int main(){
    int myArray[] = {1,3,5,7,9,2,4,6,8,0};
    int sizeofArray = sizeof(myArray)/sizeof(myArray[0]);
    //first and last index in array
    printSortedArray(myArray, sizeofArray);
    sortArrays(myArray, 0, sizeofArray-1);
    printSortedArray(myArray, sizeofArray);
    return 0;
}
