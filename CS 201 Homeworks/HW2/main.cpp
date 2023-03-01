// Student Name: Gün TASTAN
// Section: 3
// Student ID: 22101850



#include <ctime>
#include <chrono>

#include <cstdlib>
#include <iostream>
#include <string>
#include "findMedian.h"



using namespace std;


int main (){

    srand((unsigned) time(NULL)); //Providing seed value for random number

    //Declare necessary variables
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;

    int sizeOfArray = 0;

    while (sizeOfArray<=1000){

    int* arr1= new int[sizeOfArray];
    int* arr2 = new int[sizeOfArray];
    int* arr3 = new int[sizeOfArray];


    for(int i=0; i<sizeOfArray;i++){
        int randomNumber1 = -600+ (rand()%1200);
        arr1[i]=randomNumber1;
        arr2[i]=randomNumber1;
        arr3[i]=randomNumber1;

    }
    cout<<"Timing of different algorithms for finding the median of an an integer array which has "<<sizeOfArray<< " elements."<<endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_1(arr1,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime ;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 1." << endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_2(arr2,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 2." << endl;


    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_3(arr3,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 3." << endl;


    delete [] arr1;
    delete [] arr2;
    delete [] arr3;


    cout<<"---------------------------------------"<<endl;



    sizeOfArray = sizeOfArray + 100;

}
    sizeOfArray = 2000; //Made it 1100 in the last loop, now making it 1000

    while (sizeOfArray<=5000){

    int* arr1= new int[sizeOfArray];
    int* arr2 = new int[sizeOfArray];
    int* arr3 = new int[sizeOfArray];


    for(int i=0; i<sizeOfArray;i++){
        int randomNumber1 = -3000+ (rand()%6000);
        arr1[i]=randomNumber1;
        arr2[i]=randomNumber1;
        arr3[i]=randomNumber1;

    }
    cout<<"Timing of different algorithms for finding the median of an an integer array which has "<<sizeOfArray<< " elements."<<endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_1(arr1,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime ;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 1." << endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_2(arr2,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 2." << endl;


    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_3(arr3,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 3." << endl;


    delete [] arr1;
    delete [] arr2;
    delete [] arr3;


    cout<<"---------------------------------------"<<endl;



    sizeOfArray = sizeOfArray + 1000;

}
    sizeOfArray= 10000;

    while (sizeOfArray<=25000){

    int* arr1= new int[sizeOfArray];
    int* arr2 = new int[sizeOfArray];
    int* arr3 = new int[sizeOfArray];


    for(int i=0; i<sizeOfArray;i++){
        int randomNumber1 = -15000+ (rand()%30000);
        arr1[i]=randomNumber1;
        arr2[i]=randomNumber1;
        arr3[i]=randomNumber1;

    }
    cout<<"Timing of different algorithms for finding the median of an an integer array which has "<<sizeOfArray<< " elements."<<endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_1(arr1,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime ;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 1." << endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_2(arr2,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 2." << endl;


    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_3(arr3,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 3." << endl;


    delete [] arr1;
    delete [] arr2;
    delete [] arr3;


    cout<<"---------------------------------------"<<endl;



    sizeOfArray = sizeOfArray + 5000;

}
    sizeOfArray =50000;

    while (sizeOfArray<=500000){

    int* arr1= new int[sizeOfArray];
    int* arr2 = new int[sizeOfArray];
    int* arr3 = new int[sizeOfArray];


    for(int i=0; i<sizeOfArray;i++){
        int randomNumber1 = -300000+ (rand()%600000);
        arr1[i]=randomNumber1;
        arr2[i]=randomNumber1;
        arr3[i]=randomNumber1;

    }
    cout<<"Timing of different algorithms for finding the median of an an integer array which has "<<sizeOfArray<< " elements."<<endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_1(arr1,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime ;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 1." << endl;

    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_2(arr2,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 2." << endl;


    startTime = std::chrono::system_clock::now();
    FIND_MEDIAN_3(arr3,sizeOfArray);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds for Algorithm 3." << endl;


    delete [] arr1;
    delete [] arr2;
    delete [] arr3;


    cout<<"---------------------------------------"<<endl;



    sizeOfArray = sizeOfArray + 25000;

}





return 0;
}
