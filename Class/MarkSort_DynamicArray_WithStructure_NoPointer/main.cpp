/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 28th, 2020, 1:16 PM
 * Purpose:  Example of a Dynamic Array with Structures
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries
#include "array.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void filAray(Array &,int);
void prntAry(const Array &,int);
void markSrt(Array &);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=100;
    int perLine=10;
    Array array;
    
    //Initialize all known variables
    filAray(array,size);
    cout<<"Before Sorting"<<endl;
    prntAry(array,perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    markSrt(array);
    
    //Display the Inputs/Outputs
    cout<<"After Sorting"<<endl;
    prntAry(array,perLine);

    //Clean up the code, close files, deallocate memory, etc....
    delete []array.data;
    
    //Exit stage right
    return 0;
}

//Function Implementations
void markSrt(Array &a){
    //Find the smallest element in List i
    for(int i=0;i<a.size-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<a.size;j++){
            //Logic swap
            if(a.data[i]>a.data[j]){
                a.data[i]=a.data[i]^a.data[j];
                a.data[j]=a.data[i]^a.data[j];
                *(a.data+i)=a.data[i]^a.data[j];
            }
        }
    }
}


void prntAry(const Array &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size;i++){
        cout<<a.data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void filAray(Array &array,int n){
    //Declare and allocate the array
    n=n<2?2:n;
    array.data=new int[n];
    array.size=n;
    for(int i=0;i<n;i++){
        array.data[i]=rand()%90+10;//2 Digit Random Array
    }
}