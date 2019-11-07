#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int intTime(const string& t) {
    auto n = t.find(':');
    int time = stoi(t.substr(0, n));
    int min = stoi(t.substr(n + 1));
    return time * 60 + min - 480;
}

int main(int argc, const char * argv[]) {
    vector<int> times(721);
    ifstream myfile(argv[1]);
    string timeIn, timeOut;
    while (myfile >> timeIn >> timeOut) {
        times[intTime(timeIn)]++;
        times[intTime(timeOut) + 1]--;
    }
    int cur = 0;
    int maxY = -1;
    for (int i = 0; i < 720; i++) {
        cur += times[i];
        if (maxY < cur) {
            maxY = cur;
        }
    }
    cur = 0;
    vector<int> in, out;
    bool flag = false;
    for (int i = 0; i < 720; i++) {
        cur += times[i];
        if (cur == maxY) {
            if (!flag) {
                flag = true;
                in.push_back(i);
            }
        } else {
            if (flag) {
                out.push_back(i - 1);
                flag = false;
            }
        }
    }
    for (int i = 0; i < in.size(); ++i) {
        cout << (in[i] + 480) / 60 << ':' << setw(2) << setfill('0') << (in[i]) % 60;
        cout << ' ';
        cout << (out[i] + 480) / 60 << ':' << setw(2) << setfill('0') << (out[i] % 60);
        cout << endl;
    }
}
