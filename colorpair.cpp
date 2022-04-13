#include "colorpair.h"
#include <iomanip>  
using namespace TelCoColorCoder;

const char* TelCoColorCoder::MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
int TelCoColorCoder::numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* TelCoColorCoder::MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int TelCoColorCoder::numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

ColorPair::ColorPair(MajorColor major, MinorColor minor) : m_majorColor(major), m_minorColor(minor) {

}

MajorColor ColorPair::getMajor() {
    return m_majorColor;
}

MinorColor ColorPair::getMinor() {
    return m_minorColor;
}

std::string ColorPair::ToString() {
    std::string colorPairStr = MajorColorNames[m_majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[m_minorColor];
    return colorPairStr;
}

ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);

    return ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}

void TelCoColorCoder::printColorCodeReferenceManual()
{
    std::cout << "----------------------------- " << std::endl;
    std::cout << " Color Pair reference Manual " << std::endl;
    std::cout << "----------------------------- " << std::endl;
    std::cout << "PairNumber | MajorColor | MinorColor " << std::endl;

    int maxPairCount = TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors;

    for (int pairNumber = 1; pairNumber <= maxPairCount; ++pairNumber)
    {
        TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
        std::cout << std::setw(6) << pairNumber << " \t   | \t " << colorPair.ToString().c_str() << std::endl;
    }
}
