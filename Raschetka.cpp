#include <fstream>
#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
using namespace std;

const string FILE_OF_VECHERINKI = "input1.txt";
#define V 350

int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream fin(FILE_OF_VECHERINKI, ios::in);
    int N=0;
    int t;
    int K;
    fin >> N;
    int n = N;
    fin >> K;
    int M;
    M = N + K + 2;
    int arr[V][V];

    /// ///////////////////////////////
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
    }
    int x;
    int f=0;
    int z;
    int p;
    int c = 0;
    int g = 0;
    int m=0;
    int h = (N+1)* (N+1);
    

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            fin >> x;
            arr[i][j] = x;
        }
    }
    if (N > K)
    {
        cout << "Не сильно связный граф!";
    }
    else
    {
        queue <int> Queue;
        int nodes[50];
        for (int w = 0; w <= N; w++)
        {
         for (int i = 0; i <= N; i++)
         {
            nodes[i] = 0;
         }
        
            Queue.push(w);
            while (!Queue.empty())
            {
                int node = Queue.front();
                Queue.pop();
                nodes[node] = 2;
                for (int j = 0; j <= K; j++)
                {
                    for (int i = 0; i <= N; i++)
                    {
                        if (arr[node][j] == 1 && arr[i][j] == -1 && nodes[i] == 0)
                        {
                            Queue.push(i);
                            nodes[i] = 1;
                            
                        }
                    }
                    
                }
                //cout << node + 1 << endl;
                f++;
            }
        }
        if (f == h) cout << "Сильно связный граф, ура!";
        else  cout << "Не сильно связный!";
    }
    
    return 0;
}