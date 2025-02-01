#ifndef SIZECHOOSER_HPP
#define SIZECHOOSER_HPP

#include <string>
#include <vector>

namespace ZhuiZi {
typedef std::vector<double> SizeVector;
struct SizeInfo
{
    std::string sizeName = "\0";
    SizeVector sizeVector;
};
typedef std::vector<SizeInfo> SizeList;
const SizeInfo &chooseSize(const SizeList &sl, const SizeVector &sv);
bool readFromFile(SizeList &sl, const std::string &file);
bool writeToFile(const SizeList &sl, const std::string &file);
double calculateLenghth(const SizeVector &v1, const SizeVector &v2);
void printSizeList(const SizeList &sl);
void printSizeInfo(const SizeInfo &si);
} // namespace ZhuiZi

#endif // SIZECHOOSER_HPP
