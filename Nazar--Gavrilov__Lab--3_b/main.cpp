
#include <iostream>

class Stack
{
private:
    int* array;
    int size;
    int capacity;

public:
    /* constructor by default */
    Stack() : array(nullptr), size(0), capacity(0) {}

    /* constructor with parameter */
    Stack(int capacity) : size(0), capacity(capacity)
    {
        array = new int[capacity];
    }

    /* constructor of copy */
    Stack(const Stack& other) : size(other.size), capacity(other.capacity)
    {
        array = new int[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }

    ~Stack()
    {
        delete[] array;
    }

    Stack operator+ (const Stack& other) const
    {
        Stack result(size + other.size);
        for (int i = 0; i < size; ++i) {
            result.array[i] = array[i];
        }
        for (int i = 0; i < other.size; ++i) {
            result.array[size + i] = other.array[i];
        }
        result.size = size + other.size;
        return result;
    }

    Stack& operator= (const Stack& other)
    {
        delete[] array;
        size = other.size;
        capacity = other.capacity;
        array = new int[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }

        return *this;
    }

    /* operator () for returning new stack */
    Stack operator() (int n) const
    {
        Stack result(n);
        int start = (size > n) ? size - n : 0;
        for (int i = 0; i < n; ++i) {
            result.array[i] = array[start + i];
        }
        result.size = n;
        return  result;
    }

    /* тут у нас прототипы дружественных функций, а реализация ниже определена */
    friend bool operator==(const Stack& lhs, const Stack& rhs);
    friend bool operator!=(const Stack& lhs, const Stack& rhs);
    friend bool operator<(const Stack& lhs, const Stack& rhs);
    friend bool operator>(const Stack& lhs, const Stack& rhs);

    // Оператор "<<" для вывода объектов
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

    // Оператор ">>" для ввода объектов
    friend std::istream& operator>>(std::istream& is, Stack& stack);
};

/* сделал реализацию операторов сравнения */
bool operator==(const Stack& lhs, const Stack& rhs)
{
    int sum_lhs = 0, sum_rhs = 0;
    for (int i = 0; i < lhs.size; ++i) {
        sum_lhs += lhs.array[i];
    }
    for (int i = 0; i < rhs.size; ++i) {
        sum_rhs += rhs.array[i];
    }
    return sum_lhs == sum_rhs;
}

bool operator!=(const Stack& lhs, const Stack& rhs)
{
    int sum_lhs = 0, sum_rhs = 0;
    for (int i = 0; i < lhs.size; ++i) {
        sum_lhs += lhs.array[i];
    }
    for (int i = 0; i < rhs.size; ++i) {
        sum_rhs += rhs.array[i];
    }
    return sum_lhs != sum_rhs;
}

bool operator<(const Stack& lhs, const Stack& rhs)
{
    int sum_lhs = 0, sum_rhs = 0;
    for (int i = 0; i < lhs.size; ++i) {
        sum_lhs += lhs.array[i];
    }
    for (int i = 0; i < rhs.size; ++i) {
        sum_rhs += rhs.array[i];
    }
    return sum_lhs < sum_rhs;
}

bool operator>(const Stack& lhs, const Stack& rhs)
{
    int sum_lhs = 0, sum_rhs = 0;
    for (int i = 0; i < lhs.size; ++i) {
        sum_lhs += lhs.array[i];
    }
    for (int i = 0; i < rhs.size; ++i) {
        sum_rhs += rhs.array[i];
    }
    return sum_lhs > sum_lhs;
}

/*
     * operators for input and output
     * std::ostream: — базовый класс для потоков вывода (например, std::cout - стандартный вывод).
     * функция принимает два параметра - ссылка на объект(поток вывода 'os') и ссылку на объект класса который мы хотим вывести
*/
std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
    for (int i = 0; i < stack.size; ++i) {
        os << stack.array[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Stack& stack) {
    std::cout << "Enter the size of the stack: ";
    is >> stack.size;

    if (stack.size > stack.capacity) {
        delete[] stack.array;
        stack.capacity = stack.size;
        stack.array = new int[stack.capacity];
    }

    std::cout << "Enter the elements of the stack: ";
    for (int i = 0; i < stack.size; ++i) {
        is >> stack.array[i];
    }

    return is;
}

int
main()
{
    Stack stack1(3);
    std::cin >> stack1;
    std::cout << "Stack 1: " << stack1 << std::endl;

    Stack stack2(2);
    std::cin >> stack2;
    std::cout << "Stack 2: " << stack2 << std::endl;

    /* operators */
    Stack stack3 = stack1 + stack2;
    std::cout << "Stack 3 (stack1 + stack2): " << stack3 << std::endl;

    Stack stack4 = stack1(2);
    std::cout << "Stack 4 (last 2 elements of stack1): " << stack4 << std::endl;

    bool equal = (stack1 == stack2);
    std::cout << "Stack 1 == Stack 2: " << (equal ? "true" : "false") << std::endl;

    bool notEqual = (stack1 != stack2);
    std::cout << "Stack 1 != Stack 2: " << (notEqual ? "true" : "false") << std::endl;

    bool lessThan = (stack1 < stack2);
    std::cout << "Stack 1 < Stack 2: " << (lessThan ? "true" : "false") << std::endl;

    bool greaterThan = (stack1 > stack2);
    std::cout << "Stack 1 > Stack 2: " << (greaterThan ? "true" : "false") << std::endl;

    return 0;
}