#pragma once
#include <iostream>
#include<cstdlib>  
#include<ctime>  
#include <limits>
using namespace std;


class Utility
{
private:
    // Helpers
    static float readPositiveNumber(const string& msg);
    static bool readBooleanValue(const string& msg);
    static bool isOdd(int number);
    static bool isPrime(int number);
    static bool isExistInArray(int arr[100], size_t length, int number);

public:
    //Random Category
    static void Srand();
    static short  getRandomNumberFrom_0_To_100();
    static long   getRandomNumberInRange(const long& from , const long& to);
    static short  getRandomDigit();
    enum RandomLetterCase {Capital = 1 , Small = 2 ,  Mix = 3};
    static char   getRandomSmallLetterCharacter();
    static char   getRandomCapitalLetterCharacter();
    static char   getRandomMixCharacter();
    static char   getRandomCharacter(RandomLetterCase randomLetterCase);
    static char   getRandomSpecialCharacter();
    static string getRandomString(RandomLetterCase randomLetterCase , short length);
    static string getRandomKey();
    static void   printKeys(int keysNumber);

    // Swap Category
    template <typename Type>
    static void swap(Type& var_1 , Type& var_2);

    // Array Category
    template <typename Type>
    static void shuffleArray(Type arr[] , size_t arraySize);
    static void fillArrayWithRandomNumbers(int arr[] , size_t arrSize , int from , int to);
    static void readArrayElements(int arr[], size_t arrSize);
    static int  findElementFrequencyOfArray(int checkElement, int arr[], int arrSize);
    static void displayArrayElements(int arr[], size_t arrSize);
    static int  getMaxValueOfArray(int arr[], size_t arrSize);
    static int  getMinValueOfArray(int arr[], size_t arrSize);
    static int  getSumOfArray(int arr[], size_t arrSize);
    static float getAverageOfArray(int arr[], size_t arrSize);
    static void addElementForArray(int number, int arr[100], size_t& arrayLength);
    static void fillArrayWithUserInput(int arr[100], size_t& arrayLength);
    static void copyArray(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength);
    static void copyArrayOddNumbers(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength);
    static void copyArrayPrimeNumbers(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength);
    static void copyArrayDistinctNumbers(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength);
    static void reversArray(int orignalArray[100], size_t length);
    static bool isPalindromeArray(int array[100], size_t length);
    static int countOddNumbersInArray(int array[100], size_t length);
    static int countEvenNumbersInArray(int array[100], size_t length);
    static int countPositiveNumbersInArray(int array[100], size_t length);
    static int countNegativeNumbersInArray(int array[100], size_t length);

    

};

