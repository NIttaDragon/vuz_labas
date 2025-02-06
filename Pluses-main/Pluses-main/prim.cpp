#include <iostream>
#include <cstring>

const int N = 97;
const int M = 26;

using namespace std;

int main()
{
    int count[M] = { 0 };
    char a[7] = { 'a', 'f', 'g', 'a', 'r', 'h', 'b' };
    char b[5] = { 'd', 'f', 'd', 'a', 'a' };
    char c[12];
    for (int i = 0; i < 7; i++)
        count[a[i]-N]++;
    for (int j = 0; j < 5; j++)
        count[b[j]-N]++;
    int k = 0;
    for (int i = 0; i < M; i++)
    {
        if (count[i] == 0)
            continue;
        else
            for (int j = 0; j < count[i]; j++)
                c[k++] = (char)(i + N);
    }
    cout << "Target array:\n";
    for (int i = 0; i < k; i++)
        cout << c[i];
    cout << "\n";
    return 0;
}
