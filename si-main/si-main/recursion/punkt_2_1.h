void func(int maxc,int minc,int i)
{
  int s;
  printf("s[%d]=",(i+1));
  scanf("%d",&s);
  if ((s>maxc)&&(s%3==0))
    maxc=s;
  if ((s<minc)&&(s%2==0))
    minc=s;
  i++;
  if (i<10)
    func(maxc,minc,i);
  if (i>=10)
    printf("max= %d,min= %d\n",maxc,minc);
}
