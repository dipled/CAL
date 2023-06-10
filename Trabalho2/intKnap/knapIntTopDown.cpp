#include <iostream>
#include <array>
using namespace std;
const int n = 4;
const int W = 7;

array<array<int,W+1>,n+1> m;
int w[W] = {2,1,6,5};
int v[W] = {10,7,25,24};
int knapIntTopDownRec(int j, int x)
{
    if(m[j][x] == -1)
    {
        if(w[j] > x)
        {
            m[j][x] = knapIntTopDownRec(j-1,x);
        }
        else
        {
            int uses =  v[j] + knapIntTopDownRec(j-1,x-w[j]);
            int doesntUse = knapIntTopDownRec(j-1,x);
            m[j][x] = max(uses,doesntUse);
        }
    }
    return m[j][x];
}


int knapIntTopDown()
{
    for(int x = 0; x < W+1; ++x)
    {
        m[0][x] = 0;
        for(int j = 1; j < n+1; ++j)
        {
            m[j][x] = -1;
            m[j][0] = 0;
        }
    }
    return knapIntTopDownRec(n, W);
}

int main()
{
    cout << knapIntTopDown();
     for(int i = 0; i < n+1; i++)
    {
        cout<<"\n";
        for(int j = 0; j < W+1; j++)
        {
            cout << m[i][j] << " ";
        }
    }
}