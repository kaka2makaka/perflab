#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    string file1 = string(argv[1]) + '/' + "Cash1.txt";
    string file2 = string(argv[2]) + '/' + "Cash2.txt";
    string file3 = string(argv[3]) + '/' + "Cash3.txt";
    string file4 = string(argv[4]) + '/' + "Cash4.txt";
    string file5 = string(argv[5]) + '/' + "Cash5.txt";
    ifstream f1(file1.c_str());
    ifstream f2(file2.c_str());
    ifstream f3(file3.c_str());
    ifstream f4(file4.c_str());
    ifstream f5(file5.c_str());
    vector<double> visitors(16);
    double vis_now;
    int i = 0;
    while (f1 >> vis_now) {
        visitors[i]+= (double)vis_now;
        f2 >> vis_now;
        visitors[i]+=vis_now;
        f3 >> vis_now;
        visitors[i]+=vis_now;
        f4 >> vis_now;
        visitors[i]+=vis_now;
        f5 >> vis_now;
        visitors[i]+=vis_now;
        ++i;
    }
    cout << distance(max_element(visitors.begin(), visitors.end()), visitors.begin()) + 1 << endl;
}
