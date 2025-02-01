#include "SizeChooser.hpp"
#include <iostream>

using namespace std;

int main()
{
    using namespace ZhuiZi;
    SizeList testsl = {
        {"XXS", {150, 76, 62, 34}},
        {"XS", {155, 80, 66, 36}},
        {"S", {160, 84, 70, 38}},
        {"M", {165, 88, 74, 40}},
        {"L", {170, 92, 78, 42}},
        {"XL", {175, 96, 82, 44}},
        {"XXL", {180, 100, 86, 46}},
        {"XXXL", {185, 104, 90, 48}},
    };
    cout << "TestSizeList:\n";
    printSizeList(testsl);
    SizeVector testsv = {172, 95, 80, 43};
    cout << "ChooseSize:\n";
    try {
        printSizeInfo(chooseSize(testsl, testsv));
    } catch (const char *c) {
        cout << c << endl;
    }

    return 0;
}
