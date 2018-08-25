/*********************************************************
 * PrprSaber(AK-12)(bilibili妥苪朵And露)_1029985799@qq.com
 * 2018年8月25日15:42:10
 * 图片视频转换字符画(ImageTransformer)
 * 需要opencv环境
 *
 * 输出效果可能需要结合文本域大小调试
 * （详见：ImageTransformer::convertMatToAlphabetic:line15）
 *
 */

#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H

#include <iostream>
#include <fstream>//文件流
#include <opencv2/opencv.hpp>//opencv库
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class ImageTransformer
{
public:
    ImageTransformer();

public:
    /***
     * 把Mat图片变量转换成字符输出到控制台。
     * 输入图片变量。
     */
    static bool convertMatToAlphabetic(Mat image);

    /***
     * 把图片转换成字符输出到控制台。
     * 输入图片路径,使用“\\”。
     */
    static bool convertMatToAlphabetic(std::string imagePath);

    /***
     * 把图片转换成灰度图输出到本地保存。
     * 输入原图路径和保存路径,,使用“\\”。
     */
    static bool convertMatToGrayLoadToLocal(std::string imagePath, std::string loadPath);

   /**
    * 播放视频
    * 输入视频路径,使用“\\”。
    */
   static void videoPlayer(std::string videoPath);

   /**
    * 视频转字符
    * 输入视频路径,使用“\\”。
    */
   static bool convertVideoToAlphabetic(std::string videoPath);

};

#endif // IMAGETRANSFORMER_H
