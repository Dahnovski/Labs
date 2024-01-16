
#include <iostream>
#include <random>

struct Vector {
    short* data;
    int size;


    Vector(int initialSize)
    {
        size = initialSize;
        data = new short[size];

        /*initializing generator for range of numbers(from 1 to 10)*/
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<short> dist(1, 10);

        for (int i = 0; i < size; i++) {
            /*generator works beetwen 1 and 10*/
            data[i] = dist(gen);
        }
    }

    ~Vector()
    {
        delete[] data;
    }

    void resize(int newSize)
    {
        short* newData = new short[newSize];
        for (int i = 0; i < newSize; i++) {
            if(i < size) {
                newData[i] = data[i];
            } else {
                newData[i] = 0;
            }
        }

        delete[] data;
        data = newData;
        size = newSize;
    }

    /*
     тут я верну ссылку - так я работаю не с копией
     (работа идет с оригинальным значением) и так я избегаю копирования
     -------------------------------------------------------------------
     а что касается квадратных скобок, то это перегрузка
     (Перегрузка - определение различных реализаций для функций(или оператора) с одинаковым именем например)
     Мы предоставили собственную реализацию оператора который вернет нам ссылку на элемент в векторе

     // показать пример

    */
    short& operator[](int index)
    {
        return data[index];
    }

    int sumOfEvenElements()
    {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if(data[i] % 2 == 0) {
                sum += data[i];
            }
        }

        return sum;
    }

};

int
main(void)
{
    /*я тут чуть не допустил механическую ошибку со стеком - как в первом задании
    (но в первом задании не критично)*/
    /*
    Vector vector1(15);
    Vector vector2(15);
    */

    /* перевыделил в динамической памяти (и потом обращаемся через указатель (поэтому стрелку используем) к данным) */

    Vector* vector1 = new Vector(15);
    Vector* vector2 = new Vector(15);


    /*output (only elements of vector with basic size)*/
    std::cout << "Let's see the vector's elements:" << std::endl;
    std::cout << std::endl;

    std::cout << "Elements of Vector 1: ";
    for (int i = 0; i < vector1->size; i++) {
        std::cout << vector1->data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements of Vector 2: ";
    for (int i = 0; i < vector2->size; i++) {
        std::cout << vector2->data[i] << " ";
    }
    std::cout << "\n" << std::endl;


    /*getting value by index*/
    short indexNumberForFirstVectorBeforeResizing = 3;
    short indexNumberForSecondVectorBeforeResizing = 2;
    std::cout << "Element in Vector 1 (before resizing) by index "
                                                << indexNumberForFirstVectorBeforeResizing
                                                << " = "
                                                << vector1->operator[](indexNumberForFirstVectorBeforeResizing)
                                                << std::endl;
    std::cout << "Element in Vector 2 (before resizing) by index "
                                                << indexNumberForSecondVectorBeforeResizing
                                                << " = "
                                                << vector2->operator[](indexNumberForSecondVectorBeforeResizing)
                                                << std::endl;
    std::cout << "\n" << std::endl;


    /*output (EVEN elements sum)*/
    std::cout << "SUM OF EVEN ELEMENTS IN Vector 1 = " << vector1->sumOfEvenElements() << std::endl;
    std::cout << "SUM OF EVEN ELEMENTS IN Vector 2 = " << vector2->sumOfEvenElements() << std::endl;
    std::cout << "\n" << std::endl;



    /*vector comparison*/
    if(vector1->size == vector2->size) {
        bool isEqual = true;
        for (int i = 0; i < vector1->size; i++) {
            if(vector1->data[i] != vector2->data[i]) {
                isEqual = false;
                break;
            }
        }
        if(isEqual) {
            std::cout << "VECTORS ARE EQUAL." << std::endl;
        } else {
            std::cout << "VECTORS ARE DIFFERENT" << std::endl;
        }
    } else {
        std::cout << "VECTORS ARE DIFFERENT BY SIZE";
    }

    std::cout << "\n" << std::endl;

    /*output after resizing vectors*/
    vector1->resize(5);
    vector2->resize(10);

    std::cout << "Elements of Vector 1 (after resizing): ";
    for (int i = 0; i < vector1->size; i++) {
        std::cout << vector1->data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements of Vector 2 (after resizing): ";
    for (int i = 0; i < vector2->size; i++) {
        std::cout << vector2->data[i] << " ";
    }
    std::cout << "\n" << std::endl;

    /*getting by index after resizing*/
    short indexNumberForFirstVectorAfterResizing = 4;
    short indexNumberForSecondVectorAfterResizing = 9;
    std::cout << "Element in Vector 1 (after resizing) by index "
                                                << indexNumberForFirstVectorAfterResizing
                                                << " = "
                                                << vector1->operator[](indexNumberForFirstVectorAfterResizing)
                                                << std::endl;
    std::cout << "Element in Vector 2 (after resizing) by index "
                                                << indexNumberForSecondVectorAfterResizing
                                                << " = "
                                                << vector2->operator[](indexNumberForSecondVectorAfterResizing)
                                                << std::endl;
    std::cout << "\n" << std::endl;

    delete vector1;
    delete vector2;

    return 0;
}