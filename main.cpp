#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int ROWS = 100;
const int COLS = 100;

struct Point {
    int x;
    int y;
};

struct Circle {
    Point center;
    int radius;
};

void arrayInputHandler(auto arr, size_t rows, size_t cols, int mode) {
    if (mode == 1) {
        cout << "Input array line by line, use \"space\" as delimiter\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cin >> arr[i][j];
            }
        }
    } else if (mode == 2) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                arr[i][j] = rand() % 2000 - 1000;
            }
        }
    }
}

void arrayOutputHandler(auto arr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void moveMinElement(auto arr, size_t rows, size_t cols) {
    int min = INT32_MAX;
    size_t minRow = 0, minCol = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (arr[i][j] < min) {
                min = arr[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    for (size_t i = minRow; i > 0; --i) {
        swap(arr[i], arr[i - 1]);
    }
    for (size_t i = minCol; i > 0; --i) {
        swap(arr[0][i], arr[0][i - 1]);
    }
}

void pointsInputHandler(auto &points, size_t circlesNumber) {
    for (size_t i = 0; i < circlesNumber; ++i) {
        Point p{};
        cout << "Input x, y of point number " << i + 1 << ", use \"space\" as delimiter\n";
        cin >> p.x >> p.y;
        points.push_back(p);
    }
}

void circlesInputHandler(auto &circles, size_t pointsNumber) {
    for (size_t i = 0; i < pointsNumber; ++i) {
        Point p{};
        Circle c{};
        cout << "Input x, y of circle number " << i + 1 << ", use \"space\" as delimiter\n";
        cin >> p.x >> p.y;
        c.center = p;
        cout << "Input radius of circle number " << i + 1 << "\n";
        cin >> c.radius;
        circles.push_back(c);
    }

}

void findIntersections(auto points, auto circles) {
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            float si, sj, sk;
            float mi, mj, mk;
            si = points[j].x - points[i].x;
            sj = points[j].y - points[i].y;
            sk = 0;
            for (size_t k = 0; k < circles.size(); ++k) {


            }

        }
    }
}

int main() {
    srand(time(nullptr));
    int n;
    cout << "Select task: \n"
            "1 - Given a rectangular matrix. Rearrange the reduced element of the matrix in its upper left corner,\n"
            "    sequentially permuting rows and columns.\n"
            "    (static array)\n"

            "2 - Given a rectangular matrix. Rearrange the reduced element of the matrix in its upper left corner,\n"
            "    sequentially permuting rows and columns.\n"
            "    (dynamic array)\n"
            "3 - A set of points A and a set of circles B are given on the plane. Find two such different points\n"
            "    from A that the line passing through them intersects with the maximum number of circles from B.\n"
            "    (std::vector)\n";
    cin >> n;
    if (n == 1) {
        int arr[ROWS][COLS] = {0}, mode;
        size_t rows, cols = 0;
        cout << "Input number of rows and coll in array, use \"space\" as delimiter\n"
                "(max number of rows or cols is 100)\n";
        cin >> rows >> cols;
        cout << "Input mode: \n"
                "1 - Manual filling\n"
                "2 - Random filling\n";
        cin >> mode;
        arrayInputHandler(arr, rows, cols, mode);
        cout << "Entered array: \n";
        arrayOutputHandler(arr, rows, cols);
        moveMinElement(arr, rows, cols);
        cout << "Result array: \n";
        arrayOutputHandler(arr, rows, cols);
    } else if (n == 2) {
        size_t rows, cols = 0;
        cout << "Input number of rows and coll in array, use \"space\" as delimiter\n";
        cin >> rows >> cols;
        int** arr = new int*[rows];
        for (size_t i = 0; i < rows; ++i) {
            arr[i] = new int[cols];
        }
        cout << "Input mode: \n"
                "1 - Manual filling\n"
                "2 - Random filling\n";
        int mode;
        cin >> mode;
        arrayInputHandler(arr, rows, cols, mode);
        cout << "Entered array: \n";
        arrayOutputHandler(arr, rows, cols);
        moveMinElement(arr, rows, cols);
        cout << "Result array: \n";
        arrayOutputHandler(arr, rows, cols);
        for (size_t i = 0;  i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    } else if (n == 3) {
        vector <Point> points;
        vector <Circle> circles;
        size_t pointsNumber, circlesNumber;
        cout << "Input number of points\n";
        cin >> pointsNumber;
        cout << "Input number of circles\n";
        cin >> circlesNumber;
        pointsInputHandler(points, pointsNumber);
        circlesInputHandler(circles, circlesNumber);
        findIntersections(points, circles);
    } else {
        cout << "Incorrect input\n";
        return -1;
    }
    return 0;
}
