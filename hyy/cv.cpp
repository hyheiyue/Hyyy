
#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
#include<random>
// int beta=50;
// int alpha =10;
// cv::Mat imgppp;
cv::Mat img3;
cv::Mat img2,img11;
int beta ,alpha;
//int tol;
int suiji (int a,int b)//生成随机数
{ 
  std::random_device zhongzi;
  std::mt19937 suiji(zhongzi());
  std::uniform_int_distribution<>sj(a,b);
  int shu=sj(suiji);
  return shu;
}
double suiji (double a,double b)//随机数
{ 
  std::random_device zhongzi;
  std::mt19937 suiji(zhongzi());
  std::uniform_real_distribution<>sj(a,b);
  double shu=sj(suiji);
  return shu;
}
void touming(cv::Mat &img)//转4通道并赋给白像素alpha=0
{
  cv::cvtColor(img,img,cv::COLOR_BGR2BGRA);
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
cv::Vec4b&img2=img.at<cv::Vec4b>(i,j);
if((img2[0]==255&&img2[1]==255&&img2[2]==255))
{
  img2[3]=0;
}
else{
  img2[3]=255;
}
  }
 }
 }
 void touming2(cv::Mat &img)//转4通道并赋给白像素alpha=0
{
  cv::cvtColor(img,img,cv::COLOR_BGR2BGRA);
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
cv::Vec4b&img2=img.at<cv::Vec4b>(i,j);
if((img2[0]==0&&img2[1]==0&&img2[2]==0))
{
  img2[3]=0;
  
}else
{
  img2[3]=255;//设置非透明
}


    
   }
 }
 }
void tihuan(cv::Mat &img,cv::Mat &iimg)//叠加画面
{
for(int i=0;i<img.rows;i++)
{
  for(int j=0;j<img.cols;j++)
  {
    cv::Vec4b img2=img.at<cv::Vec4b>(i,j);
      if(img2[3]>0)
      {
 cv::Vec4b &img3 = iimg.at<cv::Vec4b>(i, j);
                
  
img3[0] = img3[0] * (1 - img2[3] / 255.0) + img2[0] * (img2[3] / 255.0); //加权融合
img3[1] = img3[1] * (1 - img2[3] / 255.0) + img2[1] * (img2[3] / 255.0); 
img3[2] = img3[2] * (1 - img2[3] / 255.0) + img2[2] * (img2[3] / 255.0); 
      }
    
  }
}
}
void xuanzhuan(cv::Mat &img)//随机旋转
{double x=10;
double y=10;
  cv::Point center(145,88);
  
  double jiao=suiji(1,360);
  cv::Mat bian=cv::getRotationMatrix2D(center,jiao,1.0);
  cv::warpAffine(img,img,bian,cv::Size(250,250));
  
}
void toushi(cv::Mat const &img)//随机透视
{
  float x[4];
  float y[4];
  x[0]=suiji(0,90);
  x[1]=suiji(270,360);
  x[2]=suiji(270,360);
  x[3]=suiji(0,90);
  y[0]=suiji(0,86);
  y[1]=suiji(0,86);
  y[2]=suiji(258,344);
  y[3]=suiji(258,344);


cv::Point2f yuan[4];
cv::Point2f hou[4];
yuan[0]=cv::Point2f(0.0);
yuan[1]=cv::Point2f(360,0);
yuan[2]=cv::Point2f(360,344);
yuan[3]=cv::Point2f(0,344);
hou[0]=cv::Point2f(x[0],y[0]);
hou[1]=cv::Point2f(x[1],y[1]);
hou[2]=cv::Point2f(x[2],y[2]);
hou[3]=cv::Point2f(x[3],y[3]);
cv::Mat jv=cv::getPerspectiveTransform(yuan,hou);
cv::warpPerspective(img,img,jv,img.size(),8,1);//8 =cv::WARP_FILL_OUTLIERS     1=cv::BORDER_CONSTANT
}
void daxiao(cv::Mat &img)//随机大小
{double m=suiji(0.5,1.0);
  cv::resize(img,img,cv::Size(),m,m);
}
cv::Mat  chuli(cv::Mat zhen,cv::Mat pan)
{
touming(zhen);
xuanzhuan(zhen);
    cv::cvtColor(pan,pan,cv::COLOR_BGR2BGRA);
     
touming(pan);

     cv::Mat zhen2=pan(cv::Rect(35,84,zhen.cols,zhen.rows));//35和84直接赋值是因为可以算出盘和针的rows和cols但不知道来指针轴的位置，所以只能赋值试位置
 
 tihuan(zhen,zhen2);
 daxiao(pan);
 toushi(pan);
 return pan;
 

}
void tianjia(cv::Mat &pan,cv::Mat &mengban)//添加到主画面
{
  int x=suiji(0,630);
 int y=suiji(0,400);
 long long int sum=0;
 
 for(int i=y;i<y+344;i++)
 {for(int j=x;j<x+360;j++)
 {cv::Vec4b &img = mengban.at<cv::Vec4b>(i, j);
//  if(img[0]==0&&img[1]==0&&img[2]==0)
//  {
//  sum++;
 
//  }
if(img[3]==0)
{
   sum++;
}
 }
 }
 if(sum>123000)//防止重叠
 {
   cv::Mat mengban2=mengban(cv::Rect(x,y,pan.cols,pan.rows));
     tihuan(pan,mengban2);
     return ;
 }


tianjia(pan,mengban);

    
}
cv::Mat liang(cv::Mat img)
{int beta3=suiji(-20,20);
  img.convertTo(img,-1,1,beta3);
  return img;
}
cv::Mat duibi(cv::Mat img)
{double ab=suiji(0.5,1.5);
cv::addWeighted(img,ab,cv::Mat::zeros(img.size(),img.type()),0,0,img);
return img;
}
void genggai(int,void*)//滑动条
{
int beta2=beta-100;//亮度
double alpha2=alpha/100.0;//对比度

img3.convertTo(img2,-1,alpha2,beta2);//参数变换
//img2.copyTo(img);
cv::imshow("shuchu",img2);

}
// void mouse(int event,int x,int y,int flags,void*)//鼠标操作
// { char key;

//   if(event==1)//左键增加对比度
//   { 
//     //img11.convertTo(img2,-1,1.1,100);
//     cv::addWeighted(img11,1.5,cv::Mat::zeros(img11.size(),img11.type()),0,0,img2);
//     img2.copyTo(img11);
    
//   }
//   if(event==2)//右键减小对比度
//   { 
//     //img11.convertTo(img2,-1,0.9,100);
//     cv::addWeighted(img11,0.5,cv::Mat::zeros(img11.size(),img11.type()),0,0,img2);
//     img2.copyTo(img11);
    
//   }
//   if(event==3)//中键展示原画面
//   {
//     cv::imshow("shuchu",img3);
   
//     return;
//   }
 
 
//  // cv::imshow("shuchu",img2);
// }


void xitong(cv::Mat &pan,cv::Mat &zhen,cv::Mat  &mengban,cv::Mat &mengban1,int&tol)
{
char key;
   cv::imshow("shuchu",mengban1);
     while(1)
   { //for(int i=0;i<3;i++)
   key=(char)cv::waitKey(0);
   if(key=='a')//按a添加表盘针
   {if(tol<4)//李江大头照只够放3个左右
   {
    tol++;
    {cv::Mat q;
      q=chuli(zhen,pan);
      tianjia(q,mengban);
      touming2(mengban);
    }

  cv::Mat ww=mengban1(cv::Rect(0,0,mengban.cols,mengban.rows));
  
  tihuan(mengban,ww);
 
  //tihuan(mengban,mengban1);

//  int beta=50;
//  int alpha=10;
// cv::namedWindow("shuchu",cv::WINDOW_AUTOSIZE);

// beta=100;
// alpha=100;
// img=mengban1;
// img.copyTo(img3);
// cv::createTrackbar("亮度","shuchu",&beta,200,genggai);
// cv::setMouseCallback("shuchu",mouse);
// cv::createTrackbar("对比度","shuchu",&alpha,200,genggai);
   


// cv::imshow("shuchu",mengban1);
//  mengban1.release();
//     zhen.release();
//     pan.release();
//     mengban.release();
    
//     cv::waitKey(0);
//     cv::destroyAllWindows;
    xitong(pan,zhen,mengban,mengban1,tol);
 

    }
    if(tol=4)
    {
      cv::putText(mengban1,"NO enough space or to be overed!!!",cv::Point(100,100),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(0,0,255),2);
      //std::cout<<"放不下了";
      xitong(pan,zhen,mengban,mengban1,tol);
      break;
    }
  
     }
    if(key=='s')//按s随机亮度
    {
liang(mengban1);
//cv::imshow("shuchu",liang(mengban1));
xitong(pan,zhen,mengban,mengban1,tol);
break;

    }
    if(key=='d')//按d随机对比度
    {
duibi(mengban1);
xitong(pan,zhen,mengban,mengban1,tol);
break;
    }
    else
    {
    return ;
    }
return ;
    
   }
    
}
int main()
{   //cv::Mat mengban=cv::imread("/home/hy/cv/3FC3F1EC395F486894F4929297B4C383.jpg");//(1000,1000,CV_8UC4,cv::Scalar(0,255,255));
    cv::Mat mengban(750,998,CV_8UC4,cv::Scalar(0,0,0));
    cv::cvtColor(mengban,mengban,cv::COLOR_BGR2BGRA);
    cv::Mat pan=cv::imread("/home/hy/cv/2.png");//表盘
    
     
    cv::Mat zhen=cv::imread("/home/hy/cv/1.png");//指针
    cv::Mat mengban1=cv::imread("/home/hy/cv/3FC3F1EC395F486894F4929297B4C383.jpg");//李江大头照
 cv::cvtColor(mengban1,mengban1,cv::COLOR_BGR2BGRA);
     //digui(zhen,pan,mengban);
//      char key;
      cv::imshow("shuchu",mengban1);
//      while(1)
//    { //for(int i=0;i<3;i++)
//    key=(char)cv::waitKey(0);
//    if(key=='a')
//    {
//     {cv::Mat q;
//       q=chuli(zhen,pan);
//       tianjia(q,mengban);
//       touming2(mengban);
//     }
   
    

   
//  int y1=mengban.rows;
 
 
//   cv::Mat ww=mengban1(cv::Rect(0,0,mengban.cols,mengban.rows));
  
//   tihuan(mengban,ww);
// //tianjia(mengban,mengban1);
// //  int beta=50;
// //  int alpha=10;
// cv::namedWindow("shuchu",cv::WINDOW_AUTOSIZE);

//  beta=100;
//  alpha=100;
//  img=mengban1;
//  img.copyTo(img3);
//  cv::createTrackbar("亮度","shuchu",&beta,200,genggai);
//  cv::setMouseCallback("shuchu",mouse);
//  cv::createTrackbar("对比度","shuchu",&alpha,200,genggai);
   


// // cv::imshow("shuchu",mengban1);
//  mengban1.release();
//     zhen.release();
//     pan.release();
//     mengban.release();
    
//     cv::waitKey(0);
//     cv::destroyAllWindows;
//    }
//     }
    //std::cout<<x1<<"  "<<y1;
    int tol=0;
    
   xitong(pan,zhen,mengban,mengban1,tol);
   mengban1.release();
    zhen.release();
    pan.release();
    mengban.release();
    
    cv::waitKey(0);
    cv::destroyAllWindows;
   

    return 0;
    
   
}