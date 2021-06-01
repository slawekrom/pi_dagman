#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    float x_value;
    float y_value;
    float distance;
    int seed = atoi(argv[1]);
    long long iterations = atoll(argv[2]), hit_count = 0;
    auto start_time = std::chrono::high_resolution_clock::now();
    srand(seed);

    for (long long i = 0; i < iterations; i++)
    {
        x_value = rand() / float(RAND_MAX);
        y_value = rand() / float(RAND_MAX);
        distance = x_value * x_value + y_value * y_value;
        if (distance <= 1)
        {
            hit_count++;
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << hit_count << ' ' << iterations << " time " << time / std::chrono::milliseconds(1) << endl;
    return 0;
}