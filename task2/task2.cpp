#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct pt {
    double x, y;
    pt() {
        x = 0.0;
        y = 0.0;
    }
};

bool operator == (const pt& p1, const pt& p2) {
    return (abs(p1.x - p2.x) < numeric_limits<double>::epsilon() && abs(p1.y - p2.y) < numeric_limits<double>::epsilon());
};

double dist(const pt& p1, const pt& p2) {
    return sqrt(((double)p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool is_in_seg(const pt& p, const pt& p1, const pt& p2) {
    return ((double) dist(p1, p) + dist(p2, p) - dist(p1, p2)) < numeric_limits<double>::epsilon();
}
long double area(const pt& p1, const pt& p2, const pt& p3) {
    double a = dist(p1, p2);
    double b = dist(p2, p3);
    double c = dist(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool is_in_quadro(const pt& p, const pt& p1, const pt& p2, const pt& p3, const pt& p4) {
    double x = abs((area(p1, p2, p3) + area(p1, p4, p3)) -
    (area(p, p1, p2) + area(p, p2, p3) + area(p, p3, p4) + area(p, p4, p1)));
    return x < numeric_limits<double>::epsilon();
}

int pos(pt p, const vector<pt>& quadro) {
    for (int i = 0; i < 4; ++i) {
        if (p == quadro[i]) {
            return 0;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (is_in_seg(p, quadro[i], quadro[(i + 1) % 4])) {
            return 1;
        }
    }
    if (is_in_quadro(p, quadro[0], quadro[1], quadro[2], quadro[3])) {
        return 2;
    }
    return 3;
}

int main(int argc, char* argv[]) {
    double x, y;
    ifstream file1(argv[1]);
    ifstream file2(argv[2]);
    vector<pt> quadro(4);
    vector<pt> points;
    quadro.reserve(4);
    int i = 0;
    while (i < 4) {
        file1 >> x >> y;
        quadro[i].x = x;
        quadro[i].y = y;
        i++;
    }
    while (file2 >> x >> y) {
        pt p;
        p.x = x;
        p.y = y;
        points.push_back(p);
    }
    for (const pt& p : points) {
        cout << pos(p, quadro) << endl;
    }
}
