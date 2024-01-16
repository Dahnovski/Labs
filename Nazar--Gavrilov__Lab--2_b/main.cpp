
//
//  main.cpp
//  Lab__2_Gavrilov--Nazar---Task-2
//
//


#include <iostream>
#include <cstddef>
#include <cmath>
#include <limits>
#include <algorithm>

class Matrix {
private:
    double* data;
    size_t rows;
    size_t cols;
    int error;

public:
    Matrix() : data(nullptr), rows(0), cols(0), error(0) {}

    Matrix(size_t size) : rows(size), cols(size), error(0), data(nullptr) {
        data = new double[rows * cols];
        if (!data) {
            error = 1;
        }
    }

    Matrix(size_t numRows, size_t numCols) : rows(numRows), cols(numCols), error(0), data(nullptr) {
        data = new double[rows * cols];
        if (!data) {
            error = 1;
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), error(other.error), data(nullptr) {
        data = new double[rows * cols];
        std::copy(other.data, other.data + rows * cols, data);
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] data;
            rows = other.rows;
            cols = other.cols;
            error = other.error;
            data = new double[rows * cols];
            std::copy(other.data, other.data + rows * cols, data);
        }
        return *this;
    }

    ~Matrix() {
        delete[] data;
    }

    double getElementByIndex(size_t i, size_t j) const {
        if (i < rows && j < cols) {
            return data[i * cols + j];
        }
        return std::numeric_limits<double>::quiet_NaN();
    }

    bool setValue(size_t i, size_t j, double value) {
        if (i < rows && j < cols) {
            data[i * cols + j] = value;
            return true;
        } else {
            return false;
        }
    }

    bool add(const Matrix& other, Matrix& result) const {
        if (rows == other.rows && cols == other.cols) {
            result = Matrix(rows, cols);
            if (result.getInfoAboutError() != 0) {
                return false; // Allocation failed
            }

            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result.data[i * cols + j] = data[i * cols + j] + other.data[i * cols + j];
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool subtract(const Matrix& other, Matrix& result) const {
        if (rows == other.rows && cols == other.cols) {
            result = Matrix(rows, cols);
            if (result.getInfoAboutError() != 0) {
                return false; // Allocation failed
            }

            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    result.data[i * cols + j] = data[i * cols + j] - other.data[i * cols + j];
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool multiply(double scalar, Matrix& result) const {
        result = Matrix(rows, cols);
        if (result.getInfoAboutError() != 0) {
            return false; // Allocation failed
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i * cols + j] = data[i * cols + j] * scalar;
            }
        }
        return true;
    }

    void showMatrix() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i * cols + j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    int getInfoAboutError() const {
        return error;
    }
};

int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    A.setValue(0, 0, 1);
    A.setValue(0, 1, 2);
    A.setValue(1, 0, 3);
    A.setValue(1, 1, 4);

    B.setValue(0, 0, 5);
    B.setValue(0, 1, 6);
    B.setValue(1, 0, 7);
    B.setValue(1, 1, 8);

    std::cout << "Matrix A:" << std::endl;
    A.showMatrix();
    std::cout << "Matrix B:" << std::endl;
    B.showMatrix();

    std::cout << "Element at (0, 1) in Matrix A: " << A.getElementByIndex(0, 1) << std::endl;
    std::cout << "Element at (1, 0) in Matrix B: " << B.getElementByIndex(1, 0) << std::endl;

    Matrix C;
    if (A.add(B, C)) {
        std::cout << "Matrix A + B:" << std::endl;
        C.showMatrix();
    } else {
        std::cout << "Matrix addition failed. Error code: " << A.getInfoAboutError() << std::endl;
    }

    Matrix D;
    if (A.subtract(B, D)) {
        std::cout << "Matrix A - B:" << std::endl;
        D.showMatrix();
    } else {
        std::cout << "Matrix subtraction failed. Error code: " << A.getInfoAboutError() << std::endl;
    }

    Matrix E;
    if (A.multiply(2, E)) {
        std::cout << "2 * Matrix A:" << std::endl;
        E.showMatrix();
    } else {
        std::cout << "Matrix multiplication failed. Error code: " << A.getInfoAboutError() << std::endl;
    }

    return 0;
}