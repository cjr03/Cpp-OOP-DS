//
//  Recursion Program
//
//  Created by Cole Roberts on 4/3/23.
//

#include <iostream>
#include <assert.h>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

void triangle(ostream& outs, unsigned int m, unsigned int n){
    if (m > n) return;
    for(unsigned int x = 0; x < m; ++x) outs << '*';
    outs << "\n";
    triangle(outs, m+1, n);
    for(unsigned int x = 0; x < m; ++x) cout << '*';
    outs << "\n";
}

void numbers(ostream& outs, const string& prefix, unsigned int levels) {
    if (levels == 0) {
        outs << prefix << endl;
        return;
    }
    for (unsigned int i = 1; i <= 9; i++) numbers(outs, prefix + to_string(i) + ".", levels-1);
}

unsigned int recursive_fibonacci(unsigned int n) {
    if (n == 0 or n == 1) return n;
    else return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int fib_iterative(int n) {
    if(n == 1 || n == 2)
        return 1;
    int A[2][2] = { { 1, 1 },{ 1, 0 } };
    int B[2][2] = { { 1, 1 },{ 1, 0 } };
    int temp[2][2];
    while (n >= 2) {
         for (int i = 0; i < 2; i++)
             for (int k = 0; k < 2; k++) {
                 temp[i][k] = 0;
                 for (int j = 0; j < 2; j++)
                     temp[i][k] += A[i][j] * B[j][k];
              }
         for (int i = 0; i < 2; i++)
             for (int j = 0; j < 2; j++)
                 B[i][j] = temp[i][j];
         n--;
    }
    return B[0][1];
}

bool bears(int n) {
    if (n == 42) return true;
    if (n < 42) return false;
    if (n % 2 == 0 and bears(n / 2)) return true;
    if ((n % 10) * ((n % 100) / 10) != 0 && (n % 10) * ((n % 100) / 10) != n && bears(n - (n % 10) * ((n % 100) / 10))) return true;
    if (n % 5 == 0 and bears(n - 42)) return true;
    return false;
}

int main() {
    cout << "Cole Roberts\t\tCIST 004B\n\nTriangle Test:\n\n";
    triangle(cout, 3, 5);
    cout << "\n\nSection Numbers Test:\n\n";
    numbers(cout, "THERBLIG", 2);
    cout << "\n\nBear Picnic Test:\n\n" << boolalpha << setw(4) << "bears 250 = " << bears(250) << "\nbears 42 = " << bears(42) << "\nbears 84 = " << bears(84) << "\nbears 53 = " << bears(53) << "\nbears 41 = " << bears(41) << "\n\n\nFibonacci Test:\n\n  n     Recursive          Time     Iterative          Time\n";
    for (int n = 1; n <= 45; ++n) {
        high_resolution_clock::time_point start_time_r = high_resolution_clock::now();
        int result_r = recursive_fibonacci(n);
        high_resolution_clock::time_point end_time_r = high_resolution_clock::now();
        duration<float> time_span_r = end_time_r - start_time_r;
        high_resolution_clock::time_point start_time_i = high_resolution_clock::now();
        int result_i = fib_iterative(n);
        high_resolution_clock::time_point end_time_i = high_resolution_clock::now();
        duration<float> time_span_i = end_time_i - start_time_i;
        cout << right << setw(3) << n << right << setw(14) << result_r << right << setw(14) << fixed << setprecision(9) << time_span_r.count() << right << setw(14) << result_i << right << setw(14) << fixed << setprecision(9) << time_span_i.count() << endl;
    }

    
}
