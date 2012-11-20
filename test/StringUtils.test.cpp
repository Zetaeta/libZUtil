
#include <string>
#include <vector>
#include <iostream>

#include "StringUtils.hpp"

using namespace Util;
using namespace std;

void testDemangle() {
    const string mangled = "_ZN4Util21InvalidFileDescriptorD2Ev";
    const string expected = "Util::InvalidFileDescriptor::~InvalidFileDescriptor()";

    string demangled = demangle(mangled);

    if (demangled != expected) {
        cerr << "StringUtils.demangle test failed!\n";
        cerr << "Mangled: " << mangled << '\n';
        cerr << "Expected: " << expected << '\n';
        cerr << "Got: " << demangled << '\n';
        exit(1);
    }

}

void testToLower() {
    const string upper = "HellO WoRlD";
    const string expected = "hello world";

    string lower = toLower(upper);
    if (lower != expected) {
        cerr << "StringUtils.toLower test failed!\n";
        cerr << "Upper: " << upper << '\n';
        cerr << "Expected: " << expected << '\n';
        cerr << "Got: " << lower << '\n';
        exit(1);
    }
}

void testSplit() {
    const string orig = "I am a cat";
    const vector<string> expected = {"I", "am", "a", "cat"};

    auto split = Util::split(orig, " ");
    if (split != expected) {
        cerr << "StringUtils.testSplit test failed!\n";
        cerr << "Original: " << orig << '\n';
        cerr << "Expected: " << expected << '\n';
        cerr << "Got: " << split << '\n';
        exit(1);
    }
}

int main() {
    testDemangle();
    testToLower();
    testSplit();
    cout << "StringUtils.test complete!\n";
}

