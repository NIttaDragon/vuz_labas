#include <iostream>
class MQueue
{
public:
  int k = 10000;
  int *arr = new int [k];
  Queue(int);
  void show(int);
  void zap(int);
  void del(int);
  int kol(int);
  //void dob(int);
  ~Queue();
};
