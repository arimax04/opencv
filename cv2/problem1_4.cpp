#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int INIT_TIME = 50;
  int width, height;
  double B_PARAM = 1.0 / 50.0;
  double T_PARAM = 1.0 / 200.0;
  double Zeta = 10.0;

  cv::VideoCapture cap;
  cv::Mat frame;
  cv::Mat avg_img, sgm_img;
  cv::Mat lower_img, upper_img, tmp_img;
  cv::Mat dst_img, msk_img;
  
  // 1. initialize VideoCapture 
  if(argc >= 2){
    cap.open(argv[1]);
  }else{
    cap.open(1);
  }
  if(!cap.isOpened()){
    printf("Cannot open the video.\n");
    exit(0);
  }

  // 2. prepare window for showing images
  cv::namedWindow("Input", 1);
  cv::namedWindow("FG", 1);
  cv::namedWindow("mask", 1);

  // 3. calculate initial value of background
  cap >> frame;
  
  cv::Size s = frame.size();
  
  avg_img.create(s, CV_32FC3);
  sgm_img.create(s, CV_32FC3);
  lower_img.create(s, CV_32FC3);
  upper_img.create(s, CV_32FC3);
  tmp_img.create(s, CV_32FC3);
  
  dst_img.create(s, CV_8UC3);
  msk_img.create(s, CV_8UC1);
  
  printf("Background statistics initialization start\n");
  
  avg_img = cv::Scalar(0, 0, 0);
  
  for(int i = 0; i < INIT_TIME; i++){
    cap >> frame;
    cv::Mat tmp;
    /* hatena */
    /* hatena */
  }
 
  avg_img.convertTo(avg_img, -1, 1.0 / INIT_TIME);
  sgm_img = cv::Scalar(0, 0, 0);

  for(int i = 0; i < INIT_TIME; i++){
    cap >> frame;
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */
  }

  sgm_img.convertTo(sgm_img, -1, 1.0 / INIT_TIME);

  printf("Background statistics initialization finish\n");


  bool loop_flag = true;
  while(loop_flag){
    cap >> frame;
    /* hatena */

    // 4. check whether pixels are background or not
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */

    // 5. recalculate 
    /* hatena */
    /* hatena */
    /* hatena */
    /* hatena */

    // 6. renew avg_img and sgm_img
    /* hatena */
    /* hatena */ 

    /* hatena */
    /* hatena */

    dst_img = cv::Scalar(0);
    frame.copyTo(dst_img, msk_img);
    
    cv::imshow("Input", frame);
    cv::imshow("FG", dst_img);
    cv::imshow("mask", msk_img);
    
    char key =cv::waitKey(10);
    if(key == 27){
      loop_flag = false;
    }        
  }
  return 0;
}
