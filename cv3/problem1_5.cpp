#include <opencv2/opencv.hpp>
#include <stdio.h>

int size_of_mosaic = 0;

int main(int argc, char *argv[])
{
  // 1. load classifier
  std::string cascadeName = "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml"; //Haar-like
  /* hatena */
  if(!cascade.load(cascadeName)){
    printf("ERROR: cascadeFile not found\n");
    return -1;
  }
  
  // 2. initialize VideoCapture
  cv::Mat frame;
  cv::VideoCapture cap;
  cap.open(0);
  cap >> frame;
  
  // 3. prepare window and trackbar
  cv::namedWindow("result", 1);
  /* hatena */

  double scale = 4.0;
  cv::Mat gray, smallImg(cv::saturate_cast<int>(frame.rows/scale),
               cv::saturate_cast<int>(frame.cols/scale), CV_8UC1);

  for(;;){
    
    // 4. capture frame
    cap >> frame;
    // convert to gray scale
    cv::cvtColor(frame, gray, CV_BGR2GRAY);
    
    // 5. scale-down the image
    /* hatena */
    /* hatena */
    
    // 6. detect face using Haar-classifier
    std::vector<cv::Rect> faces;
    // multi-scale face searching
    // image, size, scale, num, flag, smallest rect
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */

    // 7. mosaic(pixelate) face-region
    for(int i = 0; i < faces.size(); i++){
      cv::Point center;
      int radius;
      center.x = cv::saturate_cast<int>((faces[i].x + faces[i].width * 0.5) * scale);
      center.y = cv::saturate_cast<int>((faces[i].y + faces[i].height * 0.5) * scale);
      radius = cv::saturate_cast<int>((faces[i].width + faces[i].height) * 0.25 * scale);
      // mosaic
      if(size_of_mosaic < 1) size_of_mosaic = 1;
      /* hatena */
      /* hatena */
      /* hatena */
      /* hatena */
      /* hatena */
    }
    
    // 8. show mosaiced image to window
    cv::imshow("result", frame);

    int key = cv::waitKey(10);
    if(key == 'q' || key == 'Q')
        break;

  }
 return 0;
}
