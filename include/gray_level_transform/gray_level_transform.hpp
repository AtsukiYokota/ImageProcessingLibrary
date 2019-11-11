#ifndef GRAY_LEVEL_TRANSFORM_HPP
#define GRAY_LEVEL_TRANSFORM_HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <unistd.h>
#include <string>

class GrayLevelTransform
{
public:
  GrayLevelTransform();
  void setImage(cv::Mat& image);
  void returnImage(cv::Mat& output);
  void applyContrastModify(const float scaling_coefficient);
  void applyGammaModify(const float gamma_coefficient);
  void applyHistogramEqualization(void);

private:
  cv::Mat image_;
};

GrayLevelTransform::GrayLevelTransform()
{

}

void GrayLevelTransform::setImage(cv::Mat& image)
{
  image_ = image;
}

void GrayLevelTransform::returnImage(cv::Mat& output)
{
  output = image_;
}

void GrayLevelTransform::applyContrastModify(const float scaling_coefficient)
{
  std::cout << __FUNCTION__ << " ..." << std::endl;

  // // lookup table
  int i = 0;
  uchar lut[256];
  for (auto& elem : lut)
  {
    elem = 255.0 / (1 + exp(-scaling_coefficient * (i - 128.0) / 255.0));
    i++;
  };
  // Luminance value replacement processing
  cv::LUT(image_, cv::Mat(cv::Size(256, 1), CV_8U, lut), image_);
}

void GrayLevelTransform::applyGammaModify(const float gamma_coefficient)
{
  std::cout << __FUNCTION__ << " ..." << std::endl;

  // lookup table
  int i = 0;
  uchar lut[256];
  for (auto& elem : lut)
  {
    elem = pow(1.0 * i / 255.0, 1.0 / gamma_coefficient) * 255.0;
    i++;
  };
  // Luminance value replacement processing
  cv::LUT(image_, cv::Mat(cv::Size(256, 1), CV_8U, lut), image_);
}

void GrayLevelTransform::applyHistogramEqualization(void)
{
  std::cout << __FUNCTION__ << " ..." << std::endl;

  cv::Mat src;

  // BGR to GRAY
  cv::cvtColor(image_, src, CV_BGR2GRAY);

  cv::equalizeHist(src, src);

  // GRAY to BGR
  cv::cvtColor(src, image_, CV_GRAY2BGR);
}

#endif  // GRAY_LEVEL_TRANSFORM_HPP