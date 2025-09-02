#include "Utility.h"

void Utility::Srand()
{
    srand(time(NULL));
}
short Utility::getRandomNumberFrom_0_To_100()
{
    int randomNumber = rand() % 101; // random() % n = (result < n)
    return randomNumber;
}
long Utility::getRandomNumberInRange(const long& from , const long& to)
{
    int randomNumber = rand() % (to - from + 1); // [0 , From]
    randomNumber += from; // [From , To]
    return randomNumber;
}
short Utility::getRandomDigit()
{
    short randomDigit = rand() % 10;
    return randomDigit;
}
char Utility::getRandomSmallLetterCharacter()
{
    char randomChar = char(getRandomNumberInRange(97 , 122));
    return randomChar;
}
char Utility::getRandomCapitalLetterCharacter()
{
    char randomChar = char(getRandomNumberInRange(65 , 90));
    return randomChar;
}
char Utility::getRandomMixCharacter()
{

    RandomLetterCase randomLetterCase = RandomLetterCase(getRandomNumberInRange(Capital , Small));
    
    switch (randomLetterCase)
    {
        case Capital : return getRandomCapitalLetterCharacter();
        case Small   : return getRandomSmallLetterCharacter();

        default: return getRandomCapitalLetterCharacter();   
    }

}
char Utility::getRandomCharacter(RandomLetterCase randomLetterCase)
{
    switch (randomLetterCase)
    {
        case Capital : return getRandomCapitalLetterCharacter();
        case Small   : return getRandomSmallLetterCharacter();
        case Mix     : return getRandomMixCharacter();
    
        default: return getRandomMixCharacter();
    }
}
char Utility::getRandomSpecialCharacter()
{
    char randomChar = char(getRandomNumberInRange(32 , 47));
    return randomChar;
}
string Utility::getRandomString(RandomLetterCase randomLetterCase , short length)
{
    string randomString = "";
    for(int i = 1; i <= length; ++i)
    {   
        randomString += getRandomCharacter(randomLetterCase);
    }
    return randomString;
}
string Utility::getRandomKey()
{
    string randomKey = "";
    for(int i = 1; i <= 4; ++i)
    {
        randomKey += getRandomString(Mix , 4);
        if(i != 4)
            randomKey += '-';
    }
    return randomKey;
}
void Utility::printKeys(int keysNumber)
{
    for(int i = 1; i <= keysNumber; ++i)
    {
        cout << "Key[" << i << "]: ";
        cout << getRandomKey() << endl;
    }
}
template <typename Type>
void Utility::swap(Type& var_1 , Type& var_2)
{
    Type temporary = var_1;
    var_1 = var_2;
    var_2 = temporary;
}
template <typename Type>
void Utility::shuffleArray(Type arr[] , size_t arraySize)
{
    for(int i = 0; i < arraySize; ++i)
    {
        swap(arr[getRandomNumberInRange(0 , arraySize - 1)] , arr[getRandomNumberInRange(0 , arraySize - 1)]);
    }
}
void Utility::fillArrayWithRandomNumbers(int arr[] , size_t arrSize , int from , int to)
{
    for(int i = 0; i < arrSize; ++i)
    {
        arr[i] = getRandomNumberInRange(from , to);
    }    
}
void Utility::readArrayElements(int arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = readPositiveNumber("Element [" + to_string(i + 1) + "]: ");
    }
}

int Utility::findElementFrequencyOfArray(int checkElement, int arr[], int arrSize) {
    int counter = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] == checkElement) {
            counter++;
        }
    }
    return counter;
}

void Utility::displayArrayElements(int arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i];
        if (i != arrSize - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}
float Utility::readPositiveNumber(const string& msg)
{
    float number;
    cout << msg << ": ";
    cin >> number;
    while(cin.fail() || number < 0 || number == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "**Error! You Entered Invalid Value**\n";
        cout << msg << " Again: ";
        cin >> number;
    }
    return number;
}
int Utility::getMaxValueOfArray(int arr[], size_t arrSize) {
    int maxValue = arr[0];
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int Utility::getMinValueOfArray(int arr[], size_t arrSize) {
    int minValue = arr[0];
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

int Utility::getSumOfArray(int arr[], size_t arrSize) {
    int sum = 0;
    for (int i = 0; i < arrSize; ++i) {
        sum += arr[i];
    }
    return sum;
}
float Utility::getAverageOfArray(int arr[], size_t arrSize) {
    return float(getSumOfArray(arr, arrSize)) / arrSize;
}


bool Utility::readBooleanValue(const string& msg) {
    bool input;
    cout << msg << "?\n";
    cin >> input;
    return input;
}

void Utility::addElementForArray(int number, int arr[100], size_t& arrayLength) {
    arrayLength++;
    arr[arrayLength - 1] = number;
}

void Utility::fillArrayWithUserInput(int arr[100], size_t& arrayLength) {
    bool askUser = true;
    do {
        addElementForArray(readPositiveNumber("Please Enter Number"), arr, arrayLength);
        askUser = readBooleanValue("Do You Want More Numbers (NO[0] , YES[1])");
    } while (askUser);
}

void Utility::copyArray(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength) {
    for (int i = 0; i < baseArrayLength; i++) {
        addElementForArray(baseArray[i], drivedArray, drivedArrayLength);
    }
}

bool Utility::isOdd(int number) {
    return number % 2 != 0;
}

void Utility::copyArrayOddNumbers(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength) {
    for (int i = 0; i < baseArrayLength; i++) {
        if (isOdd(baseArray[i]))
            addElementForArray(baseArray[i], drivedArray, drivedArrayLength);
    }
}

void Utility::copyArrayPrimeNumbers(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength) {
    for (int i = 0; i < baseArrayLength; i++) {
        if (isPrime(baseArray[i]))
            addElementForArray(baseArray[i], drivedArray, drivedArrayLength);
    }
}

void Utility::copyArrayDistinctNumbers(int baseArray[100], int drivedArray[100], size_t baseArrayLength, size_t& drivedArrayLength) {
    for (int i = 0; i < baseArrayLength; i++) {
        if (!isExistInArray(drivedArray, drivedArrayLength, baseArray[i])) {
            addElementForArray(baseArray[i], drivedArray, drivedArrayLength);
        }
    }
}

void Utility::reversArray(int orignalArray[100], size_t length) {
    for (int i = 0; i < (length / 2); ++i) {
        swap(orignalArray[i], orignalArray[(length - 1) - i]);
    }
}

bool Utility::isPalindromeArray(int array[100], size_t length) {
    for (int i = 0; i < (length / 2); ++i) {
        if (array[i] != array[(length - 1) - i]) {
            return false;
        }
    }
    return true;
}

int Utility::countOddNumbersInArray(int array[100], size_t length) {
    int oddNumbersCounter = 0;
    for (int i = 0; i < length; ++i) {
        if (isOdd(array[i])) {
            ++oddNumbersCounter;
        }
    }
    return oddNumbersCounter;
}

int Utility::countEvenNumbersInArray(int array[100], size_t length) {
    int evenNumbersCounter = 0;
    for (int i = 0; i < length; ++i) {
        if (!isOdd(array[i])) {
            ++evenNumbersCounter;
        }
    }
    return evenNumbersCounter;
}

int Utility::countPositiveNumbersInArray(int array[100], size_t length) {
    int positiveNumbersCounter = 0;
    for (int i = 0; i < length; ++i) {
        if (!array[i] < 0 && array[i] != 0) {
            ++positiveNumbersCounter;
        }
    }
    return positiveNumbersCounter;
}

int Utility::countNegativeNumbersInArray(int array[100], size_t length) {
    int negativeNumbersCounter = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] < 0 && array[i] != 0) {
            ++negativeNumbersCounter;
        }
    }
    return negativeNumbersCounter;
}
bool Utility::isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

bool Utility::isExistInArray(int arr[100], size_t length, int number) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == number) return true;
    }
    return false;
}


int main() {

    return 0;
}