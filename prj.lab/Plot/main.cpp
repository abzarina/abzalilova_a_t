#include <cmath>
#include <vector>
#include <matplot/matplot.h>
#include <iostream>
#include <chrono>
#include <unordered_map>

std::vector<int> data;
std::vector<std::vector<double>> Z;
std::chrono::time_point<std::chrono::system_clock> start, end;
std::chrono::duration<double> elapsed_seconds;
int M = 20;

void sol1(long long n) {
    std::vector<int> as(200001, -1);
    for (int i = 0; i < n; i += 1) {
        int idx = 0;
        idx = data[i];
        as[idx] = n - i - 1;
    }
}

void sol2(long long n) {
    std::unordered_map<int, int> unique;
    unique.reserve(200001);
    long long idx_unique = n;
    for (long long i = n - 1; 0 <= i; i -= 1) {
        if (unique[data[i]] == 0) {
            idx_unique = data[i];
            ++unique[idx_unique];
        }
    }
}

void check_time(int por) {
    using namespace matplot;
    Z = std::vector<std::vector<double>>(2);
    for (int k = 0; k < M; ++k) {

        data = std::vector<int>(0);
        long long n;
        n = rand()%10 * por;

        for (int i = 0; i < n; ++i) {
            data.push_back(rand() % 200001);
        }


        start = std::chrono::system_clock::now();
        sol1(n);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        Z[0].push_back(elapsed_seconds.count());

        //-----------------------------

        start = std::chrono::system_clock::now();
        sol2(n);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        Z[1].push_back(elapsed_seconds.count());
    }

    auto b = bar(Z);
    save("img/test_i.jpg");

}

int main() {
    using namespace matplot;
    int por;
    std::cin >> por;
    srand(time(nullptr));
    check_time(por);
    return 0;
}