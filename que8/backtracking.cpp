//Implement n-queens problem using backtracking (recursive)
#include <iostream>
#include <chrono>

int grid[50][50];

void print(int n) {
    int a[n][2];
    for (int i = 0, count = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {
            std::cout << grid[i][j] << " ";
            if (grid[i][j] == 1) {
                a[count][0] = i;
                a[count][1] = j;
                count++;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "queen indices: ";
    for (int i = 0; i < n; i++) {
        std::cout << "[" << a[i][0] << ", " << a[i][1] << "],";
    }
    std::cout << std::endl << std::endl;
}

bool isSafe(int col, int row, int n) {
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}

bool solve(int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }
    bool res = false;
    for (int i = 0; i <= n - 1; i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            res = solve(n, row + 1) || res;
            grid[row][i] = 0;
        }
    }
    return res;
}
int main() {
    int n;
    std::cout << std::endl << "Enter the number of queen you want: ";
    std::cin >> n;
    std::cout << std::endl;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    bool res = solve(n, 0);
    if (res == false) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << std::endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::cout << "N-Queen's algorithm took " 
              << std::chrono::duration <double, std::milli> (end - start).count() 
              << " milliseconds to execute." << std::endl;
    return 0;
}