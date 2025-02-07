#include "SizeChooser.hpp"
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
    int v1_size = int(v1.size());
    for (int i = 0; i < v1_size; i++) {
        sum += pow((v1[i] - v2[i]), 2);
    }
    sum = sqrt(sum);
    return sum;
}

const ZhuiZi::SizeInfo &ZhuiZi::chooseSize(const SizeList &sl, const SizeVector &sv)
{
    double minLenghth = calculateLenghth(sl[0].sizeVector, sv);
    int num = 0;
    int sl_size  = int(sl.size());
    for (int i = 1; i < sl_size; i++) {
        if (minLenghth > calculateLenghth(sl[i].sizeVector, sv)) {
            minLenghth = calculateLenghth(sl[i].sizeVector, sv);
            num = i;
        }
    }
    return sl[num];
}

void ZhuiZi::printSizeList(const SizeList &sl)
{
	int sl_size  = int(sl.size());
    for (int i = 0; i < sl_size; i++) {
        cout << sl[i].sizeName << ':';
        int tmpSize = int(sl[i].sizeVector.size());
        for (int j = 0; j < tmpSize; j++) {
            cout << sl[i].sizeVector[j] << ' ';
        }
        cout << endl;
    }
}

void ZhuiZi::printSizeInfo(const SizeInfo &si)
{
    cout << si.sizeName << ':';
    int tmpSize = int(si.sizeVector.size());
    for (int i = 0; i < tmpSize; i++) {
        cout << si.sizeVector[i] << ' ';
    }
    cout << endl;
}

bool ZhuiZi::readFromFile(SizeList &sl, const std::string &file) {
	//TODO(need to support .csv files)
	;
}

bool ZhuiZi::writeToFile(const SizeList &sl, const std::string &file) {
	//TODO(need to support .csv files)
	;
}
