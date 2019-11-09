#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <unistd.h>
#include <string>

int main(int argc, const char* argv[])
{
  cv::Mat mat = cv::imread("image/image.jpg", cv::IMREAD_COLOR);
  cv::namedWindow("sample", cv::WINDOW_NORMAL);
  cv::imshow("sample", mat);
  cv::waitKey(0);
  cv::destroyAllWindows();

  return 0;
}