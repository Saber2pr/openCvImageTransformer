#include "imagetransformer.h"

ImageTransformer::ImageTransformer()
{
}

bool ImageTransformer::convertMatToAlphabetic(Mat image)
{
    //字符画数组
    unsigned char codeLib[4] = {' ','#','$','^'};
    //拼接字符串
    string string_Frame = "";

    if(image.empty())
    {//读取失败
        cout<<"check the frame of video >>> "<<endl;
        return false;
    }
    Mat image_gray;
    cvtColor(image, image_gray, CV_BGR2GRAY);//转换为单通道图

    Mat image_gray_sm, image_update;
    //调整灰度图大小（关键，用于适配输出区域大小, 很多时候输出杂乱就是这里设置Size的大小问题）
    //我用的qtcreator,取Size(image_gray.cols / 5, image_gray.rows / 12)刚好，视频帧宽高为{width:574, height: 424}。
    resize(image_gray,image_gray_sm,Size(image_gray.cols / 5, image_gray.rows / 12),0,0,INTER_LINEAR);

    //读取宽高
    image_update = image_gray_sm;
    int row = image_update.rows;//行（即像素高）
    int col = image_update.cols;//列数（即像素宽）

    for (int i = 0; i< row; i++)
    {//遍历行

        for (int j = 0; j< col;j++)
        {//遍历列，如果非单通道cols只有一半

            int percent = image_update.at<unsigned char>(i,j) / 225;//判断当前位置像素点灰度值
            string_Frame += codeLib[percent * sizeof(codeLib)];//拼接字符
        }
        string_Frame += "\n";
    }
    //输出帧字符串
    cout << string_Frame << endl;

    return true;
}

bool ImageTransformer::convertMatToAlphabetic(std::string imagePath)
{
    //字符画数组
    unsigned char codeLib[4] = {' ','#','$','^'};
    //拼接字符串
    string string_Frame = "";

    Mat image = imread(imagePath);
    if(image.empty())
    {//读取失败
        cout<<"check the frame of video >>> "<<endl;
        return false;
    }
    Mat image_gray;
    cvtColor(image, image_gray, CV_BGR2GRAY);//转换为单通道图

    //调整灰度图大小（关键，用于适配输出区域大小）
    Mat image_gray_sm, image_update;
    resize(image_gray,image_gray_sm,Size(image_gray.cols, image_gray.rows/3),0,0,INTER_LINEAR);

    //读取宽高
    image_update = image_gray_sm;
    int row = image_update.rows;//行（即像素高）
    int col = image_update.cols;//列数（即像素宽）

    for (int i = 0; i< row; i++)
    {//遍历行

        for (int j = 0; j< col;j++)
        {//遍历列，如果非单通道cols只有一半

            int percent = image_update.at<unsigned char>(i,j) / 225;//判断当前位置像素点灰度值
            string_Frame += codeLib[percent * sizeof(codeLib)];//拼接字符
        }
        string_Frame += "\n";
    }
    //输出帧字符串
    cout << string_Frame << endl;

    return true;
}

bool ImageTransformer::convertMatToGrayLoadToLocal(string imagePath, string loadPath)
{
    Mat image = imread(imagePath);//读取原图
    if(image.empty())
    {//读取失败
        cout<<"check the path of photo >>> "<<endl;
        return false;
    }

    Mat image_gray;
    cvtColor(image, image_gray, CV_BGR2GRAY);//转换为单通道图

    imwrite(loadPath, image_gray);//保存到本地目录

    imshow("show_gray_jpg", image_gray);//显示灰度图
    imshow("show_normal_jpg", image);//显示原图

    waitKey(3000);//pause 3 seconds

    return true;
}

void ImageTransformer::videoPlayer(std::string videoPath)
{

    //打开视频文件
    VideoCapture capture(videoPath);

    //isOpen判断视频是否打开成功
    if(!capture.isOpened())
    {
        cout<<"Movie open Error"<<endl;
    }

    //获取视频帧频
    double rate=capture.get(CV_CAP_PROP_FPS);
    cout<<"fps:"<<" "<<rate<<endl;

    //获取总帧数
    int total_rate = (int)capture.get(CV_CAP_PROP_FRAME_COUNT);
    cout<<"framesCount:"<<" "<<total_rate<<endl;//输出帧总数

    Mat frame;
    namedWindow("Movie Player");
    while(true)
    {
        //读取视频帧
        if(!capture.read(frame)){
            cout << "readVideoFrameError >>> " << endl;
            break;
        }

        imshow("Movie Player",frame);

        char c = waitKey(33);//帧率控制
        if(c == 27){ //判断按键值
            break;
        }

    }

    capture.release();
    destroyWindow("Movie Player");
}

bool ImageTransformer::convertVideoToAlphabetic(std::string videoPath)
{
    VideoCapture video(videoPath);
    if(!video.isOpened())
    {
        cout << "loading video failed >>> "<< endl;
    }

    Mat frame;
    while (true)
    {
        if(!video.read(frame)){
            cout << "readVideoFrameError >>> " << endl;
            break;
        }

        ImageTransformer::convertMatToAlphabetic(frame);
        char c = waitKey(60);//帧率控制
        if(c == 27){
            break;
        }
    }

    video.release();
    return true;
}
