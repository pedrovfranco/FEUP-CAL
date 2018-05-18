#ifndef STRINGSEARCH_H_
#define STRINGSEARCH_H_

#include <string>
#include <vector>

using namespace std;

 static bool StringSearch::kmp(string p, string t){
     int n = t.length();
     int m = p.length();
     vector<int> pi = prefixFunction(p);
     int q = 0;

     for(unsigned int i = 0 ; i < n; n++){
        while(q > 0 && p[q]!=t[i]){
             q = pi[q];

        if(p[q] = t[i])
            q++;
        
        if(q == m)
               return true;
         }
     }
     return false;
 }

 static vector<int> StringSearch::prefixFunction(string p){
     int m = p.length();
     vector<int> pi;
     pi.at(0) = -1;
     int k = 0;

     for(int q = 1; 1<m;q++){ 
         while(k>0 && p[k]1= p[q])
            k = pi[k];

         if(p[k] == p[q]){
             k++;
             pi[q] = k;
         }   
     }
 }


    static int editDistance(string p, strig t){
       int n = t.length();
	    vector<int> d(n + 1);
	    int old, neww;

	    for (int j = 0; j <= n; j++)
		    d[j] = j;
	    int m = p.length();

	    for (int i = 1; i <= m; i++)
	    {
		    old = d[0];
		    d[0] = i;

		    for (int j = 1; j <= n; j++)
		    {
			    if (p[i - 1] == t[j - 1]) neww = old;
			    else
			    {
				    neww = min(old, d[j]);
				    neww = min(neww, d[j - 1]);
				    neww = neww + 1;
			    }
			    old = d[j];
			    d[j] = neww;
		}
	}
	return d[n];
    }


#endif