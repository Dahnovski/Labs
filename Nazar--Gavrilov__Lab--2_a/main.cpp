//
//  main.cpp
//  Lab__2_Gavrilov--Nazar---Task-1
//
//  Created by Nazar Dahnovski on 07.11.2023.
//


#include <iostream>
#include <cstring>

class String {
private:
    char* str;

public:
    String() {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* initialStr) {
        str = new char[strlen(initialStr) + 1];
        strcpy(str, initialStr);
    }

    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    ~String() {
        delete[] str;
    }

    void copyStringFromAnotherObject(const String& other)
    {
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    bool compareStrings(const String& other) const
    {
        return strcmp(str, other.str) == 0;
    }

    bool findSubstring(const String& substring) const
    {
        return strstr(str, substring.str) != nullptr;
    }

    int counterOfSymbols() const
    {
        return strlen(str);
    }

    void printString() const
    {
        std::cout << str << std::endl;
    }
};

int
main()
{
    String str1("Hey, John!");
    String str2(str1);
    String str3;

    str3.copyStringFromAnotherObject("Hey, Olga!");

    str1.printString();
    str2.printString();
    str3.printString();

    if (str1.compareStrings(str2)) {
        std::cout << "str1 and str2 are equal." << std::endl;
    } else {
        std::cout << "str1 and str2 are not equal." << std::endl;
    }

    if (!str1.compareStrings(str3)) {
        std::cout << "str1 and str3 are not equal." << std::endl;
    } else {
        std::cout << "str1 and str3 are equal." << std::endl;
    }

    if (str1.findSubstring(String("John"))) {
        std::cout << "Substring found in str1." << std::endl;
    } else {
        std::cout << "Substring not found in str1." << std::endl;
    }

    std::cout << "Length of str1: " << str1.counterOfSymbols() << std::endl;

    return 0;
}