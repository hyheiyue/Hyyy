#include<iostream>
void suan(int n)
{   int x[55];
    int X[55];
    int x1[55];
    int x2[55];
    int x3[55];
    if(n==1)
    {x[1]=1;}
    if(n==2)
    {x[2]=2;}
    if(n==3)
    {x[3]=3;}
    if(n==4)
    {x[4]=4;X[4]=1;x1[4]=1;x2[4]=1;x3[4]=1;}
    if(n>4&&n<55)
    {x[4]=4;X[4]=1;x1[4]=1;x2[4]=1;x3[4]=1;
        for(int i=5;i<n+1;i++)
    {
    X[i]=X[i-1]+x3[i-1];
    x1[i]=X[i];
    x2[i]=x1[i-1];
    x3[i]=x2[i-1];
    x[i]=X[i]+x1[i]+x2[i]+x3[i];
    }
    }
    std::cout<<"第"<<n<<"年共有"<<x[n]<<"个元素x\n";

}
void qqq(int n)
{std::cout<<"输入整数n以计算元素x的个数(0<n<55)\n";
    std::cin>>n;
    if(n>0&&n<55)
    { suan(n);

        qqq(n);
    }
    else
    {
        std::cout<<"退出系统\n";
    }
}




int main()

{   int n;
std::cout<<"有一种神奇的元素x在今年春节诞生,此后它每年春节时都会分裂出其一个子元素称之为小x。每个小x从第四个春节(其诞生时的春节也算一个)开始,每年春节也分裂出一个子元素小x\n";
    qqq(n);
    return 0;
}