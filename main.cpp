#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Windows.h"

using namespace std;

const int ROWS = 100;
const int COLS = 100;

struct Point {
    double x;
    double y;
};

struct Circle {
    Point center;
    double radius;
};

struct Segment {
    Point p1, p2;
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


int intersect(const Segment& seg, const Circle& circle, Point& p1, Point& p2) {
    int intersections = 0;
    double dx = seg.p2.x - seg.p1.x;
    double dy = seg.p2.y - seg.p1.y;
    double a = dx * dx + dy * dy;
    double b = 2 * (dx * (seg.p1.x - circle.center.x) + dy * (seg.p1.y - circle.center.y));
    double c = circle.center.x * circle.center.x + circle.center.y * circle.center.y + seg.p1.x * seg.p1.x + seg.p1.y * seg.p1.y - 2 * (circle.center.x * seg.p1.x + circle.center.y * seg.p1.y) - circle.radius * circle.radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return 0;
    }
    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    if (t1 >= 0 && t1 <= 1) {
        intersections++;
    }
    if (t2 >= 0 && t2 <= 1) {
        intersections++;
    }
    return intersections;
}

void findIntersections(auto points, auto circles) {
    int max = -1;
    size_t max_i = 0;
    size_t max_j = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double A = points[j].y - points[i].y;
            double B = points[i].x - points[j].x;
            double C = points[j].x * points[i].y - points[i].x * points[j].y;
            int summ = 0;
            for (size_t k = 0; k < circles.size(); ++k) {
                double x0 = circles[k].center.x;
                double y0 = circles[k].center.y;
                double r = circles[k].radius;
                double x1, x2, y1, y2;
                double a = (A * A / B * B) + 1;
                double b = (2 * A * C) / (B * B) - 2 * A / B - 2
                if (a == 0) {
                    if (circles[k].radius * circles[k].radius - (((-c) / b) - y0) * (((-c) / b) - y0) < 0) {
                        continue;
                    }
                    x1 = sqrt(circles[k].radius * circles[k].radius - (((-c) / b) - y0) * (((-c) / b) - y0)) + x0;
                    x2 = -(sqrt(circles[k].radius * circles[k].radius - (((-c) / b) - y0) * (((-c) / b) - y0)) + x0);
                } else if (b == 0) {
                    if (circles[k].radius * circles[k].radius - (((-c) / a) - x0) * (((-c) / a) - x0) < 0) {
                        continue;
                    }
                    y1 = sqrt(circles[k].radius * circles[k].radius - (((-c) / a) - x0) * (((-c) / a) - x0)) + y0;
                    y2 = -(sqrt(circles[k].radius * circles[k].radius - (((-c) / a) - x0) * (((-c) / a) - x0)) + y0);
                } else {
                    double C = c * c + b * b * y0 * y0 - 2 * b * c * y0 + a * a * x0 * x0 - 2 * a * c * x0 - a * a * r * r;
                    double D = B * B - 4 * A * C;
                    if (D < 0) {
                        continue;
                    }
                    x1 = (-B + sqrt(D)) / (2 * A);
                    x2 = (-B - sqrt(D)) / (2 * A);
                    y1 = (-c - a * x1) / b;
                    y2 = (-c - a * x2) / b;
                    if (((x1 <= max(points[i].x, points[j].x)) && (x1 >= min(points[i].x, points[j].x))) &&
                        ((y1 <= max(points[i].y, points[j].y)) && (y1 >= min(points[i].y, points[j].y)))) {
                            summ += 1;
                            cout << x1 << " " << x2 << " " <<  y1 << " " <<  y2;
                    }
                    if (((x2 <= max(points[i].x, points[j].x)) && (x2 >= min(points[i].x, points[j].x))) &&
                        ((y2 <= max(points[i].y, points[j].y)) && (y2 >= min(points[i].y, points[j].y)))) {
                            summ += 1;
                            cout << x1 << " " << x2 << " " <<  y1 << " " <<  y2;
                    }
                }
            }

        }

    }
}

int main() {
    SetConsoleOutputCP(65001);
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