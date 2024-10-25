#include<iostream>
#include<algorithm>

void prt(int a[],int n)
{
for(int i=0;i<n;i++)
{
    std::cout<<a[i]<<" ";
}std::cout<<"\n";}
void paixu1(int a[],int n)
{for(int j=0;j<100;j++){
for(int i=0;i<n-1;i++)
{
    
    if(a[i]<a[i+1])
    {

std::swap(a[i],a[i+1]);
    }
}}
prt(a,n);

}
void paixu2(int a[],int n)
{int b[n];

std::sort(a,a+n,[](int q,int p)
{
    return q>p;
});
prt(a,n);
}
void paixu3(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
    int m=a[i];
    int j=i-1;
    while (j>=0&&a[j]<m)
    {
    a[j+1]=a[j];
    j=i-1;
    }
    
  }prt(a,n);
}
int main()
{ const int TOL=15;
 int shuzi[]={1,0,64,100,160,3,50,61,23,16,44,87,19,94,2};
    std::cout<<"原数据:\n";
prt (shuzi,TOL);
std::cout<<"第一种方法:\n";
paixu1(shuzi,TOL);
std::cout<<"第二种方法\n";
paixu2(shuzi,TOL);
std::cout<<"第三种方法\n";

paixu3(shuzi,TOL);
    return 0;
}