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
    long long all_hit_counts = 0, all_iterations = 0, hit_count, iterations;
    long double pi_estimation;
    string filepath;
    ifstream results;

    for (int i = 0; i < count; i++)
    {
        filepath = "result/partial/pi_estimation." + to_string(i) + ".out";
        results.open(filepath);
        if (results.is_open())
        {
            results >> hit_count >> iterations;
            all_hit_counts += hit_count;
            all_iterations += iterations;
            results.close();
        }
        else
        {
            cout << "niepowodzenie otwarcia pliku: " << filepath << " - " << strerror(errno) << endl;
            return -1;
        }
    }

    pi_estimation = (long double)all_hit_counts / all_iterations * 4;
    cout << setprecision(15) << pi_estimation << endl;

    return 0;
}