#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <errno.h>

using namespace std;

int main(int argc, char *argv[])
{
    int count = atoi(argv[1]);
    long long hit_points = 0;
    long long iterations = 0;
    long long counter = 0;
    long long iters = 0;
    long double pi_calc = 0;

    string filepath;
    ifstream calc_result;

    for (int i = 0; i < count; i++)
    {
        filepath = "calc_result/single/pi_calc." + to_string(i) + ".out";
        calc_result.open(filepath);
        if (calc_result.is_open())
        {
            calc_result >> counter >> iterations;
            hit_points += counter;
            iters += iterations;
            calc_result.close();
        }
        else
        {
            cout << "Opening Error: " << filepath << " - " << strerror(errno) << endl;
            return -1;
        }
    }

    pi_calc = (long double)hit_points / iters * 4;
    cout << setprecision(15) << pi_calc << endl;

    return 0;
}