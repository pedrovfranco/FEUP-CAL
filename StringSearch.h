#ifndef STRINGSEARCH_H_
#define STRINGSEARCH_H_

#include <string>
#include <vector>

using namespace std;

class StringSearch {
    public:
        static void kmp(string p, string t);

    private:
        static vector<int> prefixFunction(string p);
        static int editDistance(string p, strig t);
};


#endif