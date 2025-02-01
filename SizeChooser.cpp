#include "SizeChooser.hpp"
//#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

//using namespace ZhuiZi;
using namespace std;

double ZhuiZi::calculateLenghth(const SizeVector &v1, const SizeVector &v2)
{
    if (v1.size() != v2.size()) {
        throw "Error,Vector lenghth doesn't match";
    }
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        //sum = sum + pow(v1[i], 2) - pow(v2[i], 2);
        sum += pow((v1[i] - v2[i]), 2);
    }
    sum = sqrt(sum);
    return sum;
}

const ZhuiZi::SizeInfo &ZhuiZi::chooseSize(const SizeList &sl, const SizeVector &sv)
{
    double minLenghth = calculateLenghth(sl[0].sizeVector, sv);
    /*    int num = 0, i = 1;
    for_each(sl.begin() + 1, sl.end(), [&](const SizeInfo &si) -> void {
        
    });*/
    int num = 0;
    for (int i = 1; i < sl.size(); i++) {
        if (minLenghth > calculateLenghth(sl[i].sizeVector, sv)) {
            minLenghth = calculateLenghth(sl[i].sizeVector, sv);
            num = i;
        }
    }
    return sl[num];
}

void ZhuiZi::printSizeList(const SizeList &sl)
{
    for (int i = 0; i < sl.size(); i++) {
        cout << sl[i].sizeName << ':';
        for (int j = 0; j < sl[i].sizeVector.size(); j++) {
            cout << sl[i].sizeVector[j] << ' ';
        }
        cout << endl;
    }
}

void ZhuiZi::printSizeInfo(const SizeInfo &si)
{
    cout << si.sizeName << ':';
    for (int i = 0; i < si.sizeVector.size(); i++) {
        cout << si.sizeVector[i] << ' ';
    }
    cout << endl;
}
