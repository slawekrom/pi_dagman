#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>

#define R 10

using namespace std;

bool hit(uniform_real_distribution<double> &distribution, default_random_engine &generator)
{
    double x = distribution(generator);
    double y = distribution(generator);
    double distance = sqrt(x*x + y*y);
    return distance <= R;
}

int main(int argc, char *argv[])
{
    int seed = atoi(argv[1]);
    long long iterations = atoll(argv[2]), hit_count = 0;
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(-R, R);

    for (long long i = 0; i < iterations; i++)
        if (hit(distribution, generator))
            hit_count++;

    cout << hit_count << ' ' << iterations << endl;
    return 0;
}