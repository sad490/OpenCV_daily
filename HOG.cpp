/*
 * =====================================================================================
 *
 *       Filename:  HOG.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年09月24日 17时09分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat image = cv::imread("/home/sad490/background.jpg");
	image.convertTo(image, CV_32F, 1/255.0);
	
	cv::Mat gx, gy;
	cv::Sobel(image, gx, CV_32F, 1, 0, 1);
	cv::Sobel(image, gy, CV_32F, 0, 1, 1);
	cv::Mat mag, angle;
	cv::cartToPolar(gx, gy, mag, angle, 1);
	
	cv::imshow("Mag", mag);
	cv::imshow("Gx", gx);
	cv::imshow("Gy", gy);

	if (cv::waitKey(0) == 27){
		cv::destroyAllWindows();
	}
	return 0;
}
