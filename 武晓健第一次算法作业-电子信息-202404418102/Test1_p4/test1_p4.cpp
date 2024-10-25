#include<iostream>
#include<string>
#include<fstream>
#include <vector>
struct  robo
{std::string name;
std::string  num;
std::string wh;
std::string v;
std::string chicun;
std::string sp;
 void show()const
 {
     std::cout<<"名称:"<<name<<"编号:"<<num<<"电量:"<<wh<<"电压:"<<v<<"尺寸:"<<chicun <<"特殊属性:"<<sp<<"\n";
 }

};
struct xitong
{
std::vector<robo>A;
void tianjia(const robo& a)
{
   A.push_back(a);
}
void showall()const
{
    for(const auto&a:A)
    {
    a.show();
    }
}
;
void shuru(int*n)

{int p=0;

std::cout<<"输入要添加的车（机器人）的信息个数";
std::cin>>p;
    robo a;
    for(int i=*n;i<(*n+p);i++)
  { std::cout<<"依次输入车（机器人）的名称，编号，电量，电压，尺寸，特殊属性(编号对应相应兵种）\n";
    std:: cin>>a.name;
    std:: cin>>a.num;
     std:: cin>>a.wh;
     std:: cin>>a.v;
     std:: cin>>a.chicun;
     std:: cin>>a.sp;
    A.push_back(a);
}
    }
 void fenlei(const std::string& num)const
{
for(const auto&a:A)
{
    if(a.num==num)
    {
        a.show();
       
    }
    
}




}
 void shanchu(const std::string &name)
 {
    for(auto i=A.begin();i!=A.end();++i)
    {
if(i->name==name)
{
    A.erase(i);
    std::cout<<"已删除\n";
    return;
}
    }std::cout<<"没找到喵\n";
 }
 void save(const std::string&kk)const
 {
    std::ofstream in(kk);
    if(!in)
    {
        std::cout<<"打开失败\n";
        return ;
    }
    for(const auto&a:A)
    {
        in<<a.name<<" "<<a.num<<" "<<a.wh<<" "<<a.v<<" "<<a.chicun<<" "<<a.sp<<"\n"; 
       
    } in.close();

 }
 void zairu(const std::string &jj)
 {
    std::ifstream out(jj);
    if(!out)
    {
        std::cout<<"没有这个文件\n";
        return;
    }robo a;
    while(out>>a.name>>a.num>>a.wh>>a.v>>a.chicun>>a.sp)
    {
        A.push_back(a);
    }out.close();
 }void xiugai(const std::string &hh)
 {
    for(auto&a:A)
    {
        if(a.name==hh)
        {
            std::cout<<"修改："<<a.name<<"的信息\n";
            std::cout<<"输入新的编号，修改前："<<a.num<<"修改后：";
            std::cin>>a.num;
            std::cout<<"输入新的电量，修改前："<<a.wh<<"修改后：";
            std::cin>>a.wh;
            std::cout<<"输入新的电压，修改前："<<a.v<<"修改后：";
            std::cin>>a.v;
            std::cout<<"输入新的尺寸，修改前："<<a.chicun<<"修改后：";
            std::cin>>a.chicun;
            std::cout<<"输入新的特殊属性，修改前："<<a.sp<<"修改后：";
            std::cin>>a.sp;
            std::cout<<"修改成功\n";
        }
    }
 }
 
 
    };
void glxt(int *shu,xitong m)
{
int xuanze;
std::cout<<"0.退出系统\n1.添加信息\n2.展示全部信息\n3.分类展示信息\n4.删除信息\n5.信息载入文件\n6.读取文件信息\n7.修改信息\n输入编号以选择\n￣￣￣￣￣＼／￣￣￣￣\n　　　　∧＿∧　　　　\n　　;;（´・ω・） 　\n　＿旦_(っ(,,■)＿＿\n　|l￣l||￣しﾞしﾞ￣|i\n";
std::cin>>xuanze;

switch (xuanze)
{
case 0:
{
std::cout<<"退出系统\n"<<"☆ *  .   ☆\n    . ∧＿∧  ∩  * ☆\n* ☆ ( ・∀・)/ .\n  . ⊂     ノ* ☆\n☆ * (つ / .☆\n    (ノ\n";
break;
}
    case 1:
    {
        m.shuru(shu);
        glxt(shu,m);
        break;
    
    }
    case 2:
    {
   
        m.showall();
        glxt(shu,m);
        break;
    }
    case 3:
    {
        std::cout<<"输入要查询的兵种编号\n";
        std::string ff;
        std::cin>>ff;
        m.fenlei(ff);
        glxt(shu,m);
        break;
    }
    case 4:
    {
        std::cout<<"输入要删除信息的车(机器人)的名称\n";
        std::string ll;
        std::cin>>ll;
        m.shanchu(ll);
        glxt(shu,m);
        break;

    }
    case 5:
    {
        std::cout<<"输入要将信息保存到的完整文件名,如果没有该文件会新建一个文件\n";
        std::string kk;
        std::cin>>kk;
        m.save(kk);
        glxt(shu,m);
        break;

    }
    case 6:
    {
        std::cout<<"输入要读取信息的完整文件名\n";
        std::string jj;
        std::cin>>jj;
        m.zairu(jj);
        glxt(shu,m);
        break;
    }case 7:
    {
        std::cout<<"输入要修改的车（机器人）的名称\n";
        std::string hh;
        std::cin>>hh;
        m.xiugai(hh);
        glxt(shu,m);
    }


}
}

int main()
{;
    std::string key;
    int gg=0;
    int *shu=&gg;
   
    

xitong m;
std::cout<<"请正确输入您所在的战队名称以进入系统\n";
std::cin>>key;
if(key!="崇实")
{
    std::cout<<"不认识喵\n"<<"退出系统\n"<<"☆ *  .   ☆\n    . ∧＿∧  ∩  * ☆\n* ☆ ( ・∀・)/ .\n  . ⊂     ノ* ☆\n☆ * (つ / .☆\n    (ノ\n";
    return 0;
}
else
{
glxt(shu,m);

}


}