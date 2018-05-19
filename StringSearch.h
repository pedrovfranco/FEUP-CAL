#ifndef STRINGSEARCH_H_
#define STRINGSEARCH_H_

#include <string>
#include <vector>

using namespace std;

class StringSearch {
    public:
        static bool kmp(string p, string t);
        static int editDistance(string p, string t);
        static double getPercentageEditDistance(string p, string t);

    private:
        static vector<int> prefixFunction(string p);
};


#endif