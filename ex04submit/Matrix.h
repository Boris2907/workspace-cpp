#ifndef DS_MATRIX_H
#define DS_MATRIX_H

#include "Ratio.h"
#include <iostream>
#include <string>

namespace ds_course
{
    template <class T>
    class Matrix
    {
    private:
        
        int rows; // row count
        int cols; // column count
    public:
        T** a;
        Matrix(int rr, int cc);
        int getRows();
        int getCols();

        bool operator==(const ds_course::Matrix<T>& rhs);
        void operator+(const ds_course::Matrix<T>& rhs);
        void operator-(const ds_course::Matrix<T>& rhs);
        void operator*(const ds_course::Matrix<T>& rhs);

        friend std::istream& operator>>(std::istream& input, ds_course::Matrix<T>& m)
        {
            for (int i = 0; i < m.getRows(); i++)
                for (int j = 0; j < m.getCols(); j++)
                    input >> m.a[i][j];
            return input;
        }
    };
} 

template <class T>
ds_course::Matrix<T>::Matrix(int rr, int cc) : rows(rr), cols(cc)
{
    a = new T * [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
}

template <class T>
int ds_course::Matrix<T>::getRows() { return rows; }

template <class T>
int ds_course::Matrix<T>::getCols() { return cols; }


template <class T>
bool ds_course::Matrix<T>::operator==(const ds_course::Matrix<T>& rhs)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (!(a[i][j] == rhs.a[i][j]))
                return false;
    return true;
}

template <class T>
void ds_course::Matrix<T>::operator+(const ds_course::Matrix<T>& rhs) {
    Matrix<T> newMatr(rows, rhs.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatr.a[i][j] = a[i][j] + rhs.a[i][j];

            if (i != rows && j != cols) {
                if (j == cols-1) {
                std::cout << newMatr.a[i][j] << std::endl;
                }
                else {
                    std::cout << newMatr.a[i][j] << " ";
                }
            }    
        }    
    }                      
}

template <class T>
void ds_course::Matrix<T>::operator-(const ds_course::Matrix<T>& rhs) {
    Matrix<T> newMatr(rows, rhs.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatr.a[i][j] = a[i][j] - rhs.a[i][j];

           
            if (i != rows && j != cols) {
                if (j == cols-1) {
                std::cout << newMatr.a[i][j] << std::endl;
                }
                else {
                    std::cout << newMatr.a[i][j] << " ";
                }
            }    
        }    
    }     
}

template <class T>
void ds_course::Matrix<T>::operator*(const ds_course::Matrix<T>& rhs) {

    Matrix<T> newMatr(rows, rhs.cols);
    for ( int i = 0; i < rows; i++) {
        for (int j = 0; j< rhs.cols; j++) {
            for (int k = 0; k < cols; k++) {
                newMatr.a[i][j] = newMatr.a[i][j] + a[i][k]*rhs.a[k][j]; 
            }
        }
    }

    for (int i = 0; i < newMatr.rows; i++) {
        for (int j = 0; j < newMatr.cols; j++) {

            if (i == newMatr.rows && j == newMatr.cols) {
                 std::cout << newMatr.a[i][j];
            }
            else {
                if (j == newMatr.cols-1) {
                std::cout << newMatr.a[i][j] << std::endl;
                }
                else {
                    std::cout << newMatr.a[i][j] << " ";
                }
            }    
        }
     }
}
#endif /* DS_MATRIX_H */