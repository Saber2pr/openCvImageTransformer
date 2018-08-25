/*********************************************************
 * PrprSaber(AK-12)(bilibili妥苪朵And露)_1029985799@qq.com
 * 2018年8月25日15:42:10
 * 所有路径,需使用“\\”分隔。
 */

#include"imagetransformer.h"
#include <opencv2/highgui/highgui.hpp>


//图片文件路径
//#define imageFile "F:\\Test\\opencvTest\\cpp\\test_147.jpg"
//灰度图保存路径
//#define imageFile_gray "F:\\Test\\opencvTest\\cpp\\image_gray.jpg"

//视频文件路径
#define videoFile "F:\\Test\\opencvTest\\cpp\\badapple.mp4"

/**
 * 示例：
 */
int main()
{
//    /**
//     * 读取图片转成字符画
//     */
//    ImageTransformer::convertMatToAlphabetic(imageFile);
//    /**
//     * 读取图片转成灰度图
//     */
//    ImageTransformer::convertMatToGrayLoadToLocal(imageFile, imageFile_gray);

    /**
     * 读取视频转成字符画
     */
    ImageTransformer::convertVideoToAlphabetic(videoFile);

//    /**
//     * 视频播放器
//     */
//    ImageTransformer::videoPlayer(videoFile);

    return 0;//程序终止

}
