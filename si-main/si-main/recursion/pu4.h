float rec(float x)
{
  float l=0.01;
  float y;
  float k=1.0/2.0;
  while(x>=-1.2)
  {
    y=2*x*powf(1-powf((x*k),2),k);
    x=x-l;
    printf("\t %f\n",y);
  }
  return x;
}
