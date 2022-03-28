#include <iostream>
using namespace std;

void createMatr(int** &arr, int row, int cols) {

    arr = new int* [row];

    for (int i = 0; i < row; i++) {
        arr[i] = new int[cols];
    }
        
}

void fill(int** &arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void print(int** &arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void delMatr(int** &arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[]arr[i];
    }
    delete[]arr;
}

int** addRowEnd(int**& arr, int& row, int cols) {
    int** temp = nullptr;
    createMatr(temp, row+1, cols);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < cols; i++) {
        temp[row][i] = 0;
    }

    delMatr(arr, row);
    row++;
    return temp;
}

int** addRowFirst(int**& arr, int& row, int cols) {
    int** temp = nullptr;
    createMatr(temp, row + 1, cols);

    for (int i = 1; i < row+1; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = arr[i-1][j];
        }
    }
    for (int i = 0; i < cols; i++) {
        temp[0][i] = 0;
    }

    delMatr(arr, row);
    row++;
    return temp;
}

int** addInsetRow(int**& arr, int& row, int cols, int key) {
    int** temp = nullptr;
    createMatr(temp, row + 1, cols);

    for (int i = 0; i < row + 1; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < key) {
                temp[i][j] = arr[i][j];
            }
            else if (i == key) {
                temp[i][j] = 0;
            }
            else {
                temp[i][j] = arr[i - 1][j];
            }
        }
    }

    delMatr(arr, row);
    row++;
    return temp;
}

int** delRow(int**& arr, int& row, int cols, int key) {
    int** temp = nullptr;
    createMatr(temp, row - 1, cols);

    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < key) {
                temp[i][j] = arr[i][j];
            }            
            else {
                temp[i][j] = arr[i + 1][j];
            }
        }
    }

    delMatr(arr, row);
    row--;
    return temp;
}

int main()
{
    
    /*Задание 1. Написать функцию, добавляющую строку двухмерному массиву в конец.
    Задание 2. Написать функцию, добавляющую строку двухмерному массиву в начало.
    Задание 3. Написать функцию, добавляющую строку двухмерному массиву в указанную позицию.
    Задание 4. Написать функцию, удаляющую строку двухмерного массива по указанному номеру.*/

    int row, cols, key;

    cout << "Enter row: ";
    cin >> row;
    cout << "Enter cols: ";
    cin >> cols;
    cout << endl;
    int** matr = nullptr;

    createMatr(matr, row, cols);
    fill(matr, row, cols);
    print(matr, row, cols);
    matr = addRowEnd(matr, row, cols);
    print(matr, row, cols);
    matr = addRowFirst(matr, row, cols);
    print(matr, row, cols);    
    cout << "Enter the insertion position: ";
    cin >> key;
    matr = addInsetRow(matr, row, cols, key);
    print(matr, row, cols);
    cout << "Enter the delete position: ";
    cin >> key;
    matr = delRow(matr, row, cols, key);
    print(matr, row, cols);
    delMatr(matr, row);
}