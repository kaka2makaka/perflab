#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<double> nums;
    double num = 0.0;
    while(cin >> num) {
        nums.push_back((double)num);
    }
    ifstream myfile(argv[1]);
    if(myfile.is_open()) {
        while (myfile >> num) {
            nums.push_back(num);
        }
    }
    nth_element(nums.begin(), nums.begin() + nums.size() / 2 + 1, nums.end(), greater<double>());
    cout << fixed;
    cout << setprecision(2) << (double) nums[nums.size() / 10.0] << endl;
    cout << setprecision(2) << (double) nums[nums.size() / 2.0] << endl;
    cout << setprecision(2) << (double) *max_element(nums.begin(), nums.end()) << endl;
    cout << setprecision(2) << (double) *min_element(nums.begin(), nums.end()) << endl;
    cout << setprecision(2) << (double) accumulate(nums.begin(), nums.end(), 0) / nums.size() << endl;
}
