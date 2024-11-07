#include <iostream>
#include <opencv2/opencv.hpp>

/*通过识别动态的像素快来识别车辆的思路来自个人自主思考，通过二值化边缘检测来实现对目标提取的思路来源于同济大学视觉组培训视频和对rm视觉ai的提问，函数70%都是问的gpt，个人暂时没有认识这么多的函数*/

void touming(cv::Mat &img)//转4通道并赋给黑色像素alpha=0以透明
{
  cv::cvtColor(img,img,cv::COLOR_BGR2BGRA);//转4通道
  for(int i=0;i<img.rows;i++)//遍历所有像素
  {
    for(int j=0;j<img.cols;j++)
    {
    cv::Vec4b&img2=img.at<cv::Vec4b>(i,j);// .at提取
    if(img2[0]==0&&img2[1]==0&&img2[2]==0)//判断是否黑色
{
    img2[3]=0;
}

    
   }
 }
 }
void tihuan(cv::Mat &img,cv::Mat &iimg)
{
for(int i=0;i<img.rows;i++)
{
  for(int j=0;j<img.cols;j++)//遍历所有像素
  {
    cv::Vec4b img2=img.at<cv::Vec4b>(i,j);// .at提取
    
      if(img2[3]>0)
      {
    cv::Vec4b &img3 = iimg.at<cv::Vec4b>(i, j);// .at提取
                
  
    img3[0] = img3[0] * (1 - img2[3] / 255.0) + img2[0] * (img2[3] / 255.0); //加权融合
    img3[1] = img3[1] * (1 - img2[3] / 255.0) + img2[1] * (img2[3] / 255.0); 
    img3[2] = img3[2] * (1 - img2[3] / 255.0) + img2[2] * (img2[3] / 255.0); 
      }
    
  }
}
}
/*本来想用边缘检测的结果附加到原视频，但是效果不太好，main里面没删掉就注释了*/


int main()//识别思路是识别移动的像素块，
{   cv::VideoCapture vid("/home/hy/cv/car.mp4");//读取视频
    cv::Mat img,iimg;
    int width=static_cast<int>(vid.get(cv::CAP_PROP_FRAME_WIDTH));
    int height=static_cast<int>(vid.get(cv::CAP_PROP_FRAME_HEIGHT));
    int fps=static_cast<int>(vid.get(cv::CAP_PROP_FPS));//get基础数据
    cv::Ptr<cv::BackgroundSubtractor>ground=cv::createBackgroundSubtractorMOG2();//背景剑法器
     while (true)
    {
        vid>>img;
        if(img.empty())
        {
            break;
        }
        //cv::imshow("t",img);
        //img.convertTo(img,-1,1,20);
        ground->apply(img,iimg);//应用背景减法器，输出动态的前景，形成二值画面
        cv::morphologyEx(iimg,iimg,cv::MORPH_OPEN,cv::Mat());//开运算降噪，去除小噪声的干扰
        cv::morphologyEx(iimg,iimg,cv::MORPH_CLOSE,cv::Mat());//逆向开运算闭运算，补齐小孔；
        std::vector<std::vector<cv::Point>>lunkuo;//定义轮廓向量
        cv::findContours(iimg,lunkuo,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);//检测轮廓，赋给轮廓向量外部轮廓和轮廓端点以确定轮廓属性
        for (const auto&A:lunkuo)//常量引用
        {
           if(cv::contourArea(A)>60)//用轮廓面积过滤小的噪声
           {
            cv::Rect kuang=cv::boundingRect(A);//得到轮廓的外接框，赋给kuang变量
            cv::rectangle(img,kuang,cv::Scalar(0,255,0),0.5);//画框
            std::string car="car";
            cv::Point xy(kuang.x,kuang.y-1);//通过框的坐标定义car字符法坐标
            cv::putText(img,car,xy,cv::FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(0,255,0),0.1);//绘制字符car
           }
        }
      // cv::imshow("1",img);
       touming(iimg);
      //cv::cvtColor(img,img,cv::COLOR_BGR2BGRA);
        
   
      cv::Mat iimg2=img(cv::Rect(0,0,iimg.cols,iimg.rows));
      //tihuan(iimg,iimg2);
      cv::imshow("2",img);//输出
      //img.convertTo(img,-1,1.4,-20);
      // cv::Mat ronghe;
      // cv::addWeighted(img,0.7,iimg,0.3,0,ronghe);
        
        
      cv::imshow("1",iimg);
      // cv::imshow("3",ronghe);
        
      cv::waitKey(300/fps);//原视频不流畅，压缩时长提升帧数
        
    }
   return 0;
    

}
