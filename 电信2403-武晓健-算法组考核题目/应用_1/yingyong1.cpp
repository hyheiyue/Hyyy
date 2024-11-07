
#include <iostream>
#include <string>
#include <numeric>
#include <limits>//有空格
//#include"qqq.hpp"
//#include "../includes/hello.hpp"//
class youli//有理数的类
{public:
long long int shang;//分子
long long int xia;//分母
    youli()//初始化
    {
    shang=0;xia=0;
    }
    youli(long long int a,long long int b)//初始化
    {
        shang=a;
        xia=b;

    }
    
    youli  operator+(youli&b)//重载+
    {youli c;
        c.xia=xia*b.xia;
        shang=shang*b.xia;
        b.shang=b.shang*xia;
        c.shang=shang+b.shang;

return c.yuefen();
    }
    youli yuefen()//约分
    {youli c;
        c.shang=shang;
        c.xia=xia;
    int  m=std::gcd(c.shang,c.xia);
        c.shang=c.shang/m;
        c.xia=c.xia/m;

return c;
   }
    friend std::ostream&operator<<(std::ostream&os,youli a);//构建与io的友元关系，以重载<<

};
    std::ostream&operator<<(std::ostream&os,youli a)//重载<<以输出分子/分母形式的有理数
 {
    int  q=a.shang%a.xia;
    int m=((a.shang-q)/a.xia);
    a.shang =q;
 if(m!=0)
 {if(a.shang!=0)
    {
        os<<m<<" "<<a.shang<<"/"<<a.xia<<" ";
        return os;
    }  
    else
        {
            os<<m<<" ";
            return os;
        }
    
 }
 if(m=0)
{   if(a.shang>0)
    {   os<<a.shang<<"/"<<a.xia<<"  ";
    return os;
    }   
 }  int o=0;
    os<<o<<" ";
    return os;
 };

int main()
{   int N;
    std::cout<<"输入整数N(<=100)\n";
    std::cin>>N;
    if(N>100)
    {
        std::cout<<"没让你输入这么大的！！！！\n";
        return 0;
    }
    else if(N<=0)
    {
        std::cout<<"让你输入正整数！！！\n";
        return 0;
    }
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');//读取回车之前
    youli *shu[N];
    std::cout<<"请输入"<<N<<"个有理数,用空格隔开\n";
    for(int i=0;i<N;i++)
    {  
        long long int a,b,c;
        char q;
      std::string in,a1,b1;
      std::cin>>in;
      size_t gang=in.find('/');
      size_t kong=in.find(' ');
      if(gang!=std::string::npos)
      {
        a1=in.substr(0,gang);
        b1=in.substr(gang+1,kong);//用‘/’区分分子分母
      }
       
        a=std::stoll(a1);
        b=std::stoll(b1);
        shu[i]=new youli(a,b);//赋值
        

    }
    youli tol,tem;
    tol=*(shu[0]);
    for(int j=1;j<N;j++)//求和
    {
        tem=*(shu[j]);
        tol=tem+tol;
       
    }
    std::cout<<"有理数和为："<<tol;
    
   


}