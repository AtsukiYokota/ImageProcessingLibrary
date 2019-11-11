#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <unistd.h>
#include <string>

#include "gray_level_transform/gray_level_transform.hpp"

int main(int argc, const char* argv[])
{
  GrayLevelTransform level_trans;

  cv::Mat mat = cv::imread("image/image.jpg", cv::IMREAD_COLOR);

  level_trans.setImage(mat);
  level_trans.applyGammaModify(5.0);
  level_trans.applyContrastModify(5.0);
  level_trans.applyHistogramEqualization();
  level_trans.returnImage(mat);

  cv::namedWindow("sample", cv::WINDOW_NORMAL);
  cv::imshow("sample", mat);
  cv::waitKey(0);
  cv::destroyAllWindows();

  return 0;
}
