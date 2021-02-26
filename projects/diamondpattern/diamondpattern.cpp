// arraypattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int replace = 15;
char arr[replace][replace];
void prsp(int spa) {
    for (int i = 0; i < spa; i++) {
        std::cout << " ";
    }
}

void prst(int sta) {
    for (int i = 0; i < sta; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void arrinit() {
    for (int i = 0; i < replace; i++) {
        for (int j = 0; j < replace; j++) {
            arr[i][j] = ' ';
        }
    }
}
void printarr() {
    for (int i = 0; i < replace; i++) {
        for (int j = 0; j < replace; j++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}

void prpat(int tl) {
    int numst = 1;
    int numsp = tl / 2;
    for (int i = 0; i < tl; i++) {
        prsp(numsp);
        prst(numst);

        for (int j = 0; j < numst; j++) {
            arr[numsp + j][i] = '*';
        }

        if (i >= tl / 2) {
            numst = numst - 2;
            numsp++;
        //bottom half
        } else {
            numst = numst + 2;
            numsp--;
        //top half    
        }
    }
}

int main() {
    arrinit();
    int a;
    std::cout << "please enter a number from 3 to " << replace << std:: endl;
    std::cin >> a;
    if (a < 3 || a > replace) {
        std::cout << "invalid" << std::endl;
        exit(0);
    }


    if ( (a % 2) == 0 ) {
        a++;
        std::cout << "even numbers are not allowed so i added one to your number" << std::endl;
    }
    prpat(a);
    std::cout << "testing array" << std::endl;
    printarr();
    /*
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j];
        
        }
        std::cout << std::endl;
    }
    */
}

//void prpat(int t) {
 //   int c = 1;
 //   int b = totl / 2;
 //   for(int i = 0)
//}


   

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

