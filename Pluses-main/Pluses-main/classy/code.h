#include <string>
using namespace std;

class Matrica
{
    public:
        void set_a(int matrix_a[4][4]) // Установка матрицы
        {
          for (int i=0;i<4;i++)
              {
                  for (int j=0;j<4;j++)
                  {
                    a[i][j] = matrix_a[i][j];
                  }
              }
        }

    private:
        int a[4][4]; // Матрица
};
