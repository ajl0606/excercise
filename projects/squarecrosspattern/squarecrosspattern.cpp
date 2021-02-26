// savearraydifpat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
char arr[101][101];
void initarr(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = ' ';
        }
    }
}

void prspace(int total) {
    for (int i = 0; i < total; i++)
        std::cout << " ";
}

void prarray(int w, int l) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}

void prpat(int w, int l) {
    for (int i = 0; i < w; i++) {
        if (i == w - 1 || i == 0 || i == w / 2) {
            for (int j = 0; j < l; j++) {
                arr[i][j] = '*';
                std::cout << "*";
            }
            
        } else {
            std::cout << "*";
            prspace(l / 2 - 1);
            std::cout << "*";
            prspace(l / 2 - 1);
            std::cout << "*";            
            arr[i][0] = '*';
            arr[i][l / 2] = '*';
            arr[i][l - 1] = '*';
        }   
        std::cout << std::endl;
    }
}

int main(){
    int w;
    int l;
    std::cout << "choose an length that is an odd number from 5 to 101" << std::endl;
    std::cin >> l;
    if (l < 5 || l > 101) {
        std::cout << "invalid number";
        exit(0);
    }
    std::cout << "choose an width that is an odd number 5 to 101" << std::endl;
    std::cin >> w;
    if (w < 5 || w > 101) {
        std::cout << "invalid number";
        exit(0);
    }
    initarr(101);    
    prpat(l, w);
    std::cout << "printing array" << std::endl;
    prarray(l, w);
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

