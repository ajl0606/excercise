// calculator project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int divide(int a, int b) {
    return a / b;
}

int multiply(int a, int b) {
    return a * b;
}

int main(){
    int num1;
    int num2;
    char sign;
    std::cout << "choose any number and a sign +, -, *,/ in a + b form" << std::endl;
    std::cin >> num1 >> sign >> num2;
    if (sign == '+'){
        std::cout << add(num1, num2);
    }
    if (sign == '-') {
        std::cout << subtract(num1, num2);
    }
    if (sign == '/') {
        std::cout << divide(num1, num2);
    }
    if (sign == '*') {
        std::cout << multiply(num1, num2);
    }
    if (sign != '+' && sign != '-' && sign != '*' && sign != '/') {
        exit(0);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

