//  Convert this program to C++
//  change to C++ io
//  change to one line comments
//  change defines of constants to const
//  change array to vector<>
//  inline any short function

#include <iostream>
#include <vector>
using namespace std;

const int N=40;

inline void sum(int& p, int n, vector<int> d)
{
    p = 0;
    // use iterator to calculate the sum of vector
    for (vector<int>::iterator it = d.begin(); it != d.end(); ++it)
        p += *it;
}
int main()
{
    int accum = 0;
    vector<int> data;

    // init vector
    for (int i = 0; i < N; ++i)
        data.push_back(i);
        
    // calculate sum
    sum(accum, N, data);
    
    // output result
    cout<<"sum is "<<accum<<endl;

    return 0;
}
