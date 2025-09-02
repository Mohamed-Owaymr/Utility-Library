# Utility Library  

## 📌 Overview  
The **Utility Library** is a C++ practice project I created to strengthen my understanding of **Object-Oriented Programming (OOP)** concepts, while also improving my skills in:  
- Working with **random numbers**.  
- Manipulating and analyzing **arrays**.  
- Using **templates** to **maximize code reusability**.  

This library is not meant to replace standard libraries, but to serve as a **learning tool** for building reusable helper functions and practicing clean code design.

---

## 🎯 Purpose  
- Practice **OOP fundamentals** such as encapsulation, static methods, and class organization.  
- Learn how to implement **random number generators** and create random data like characters, strings, and keys.  
- Work with **normal arrays** (not vectors) to better understand low-level array operations.  
- Explore **templates** (e.g., `swap`, `shuffleArray`) to make functions generic and reusable.  
- Build a **personal utility toolkit** that I can extend while learning new concepts.  

---

## 🛠 Features  

### 🔢 Random Category  
- Generate random numbers in ranges.  
- Get random characters (capital, small, mixed, special).  
- Generate random strings and random keys.  

### 🔄 Swap & Templates  
- Generic `swap` function using **templates**.  
- Generic `shuffleArray` for randomizing arrays of any type.  

### 📊 Array Category  
- Fill arrays with random numbers or user input.  
- Copy arrays (all numbers, odd numbers, prime numbers, distinct numbers).  
- Analyze arrays (frequency, max, min, sum, average).  
- Transform arrays (reverse, shuffle).  
- Check properties (palindrome, odd/even/positive/negative counts).  

---

## 🚀 Example Usage  

```cpp
#include "Utility.h"

int main() {
    // Initialize random seed
    Utility::Srand();

    // Generate a random number
    int randomNum = Utility::getRandomNumberInRange(10, 50);
    cout << "Random Number: " << randomNum << endl;

    // Swap using template
    int a = 5, b = 10;
    Utility::swap(a, b);
    cout << "After Swap: a = " << a << ", b = " << b << endl;

    // Work with arrays
    int arr[100];
    Utility::fillArrayWithRandomNumbers(arr, 5, 1, 20);
    Utility::displayArrayElements(arr, 5);

    return 0;
}
