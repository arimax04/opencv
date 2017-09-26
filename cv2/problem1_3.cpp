#include <opencv2/opencv.hpp>
#include <stdio.h>

#define IN_VIDEO_FILE "sample_video_input.avi"
#define OUT_VIDEO_FILE "sample_video_output.avi"

int main(int argc, char *argv[]){

  // 1. prepare VideoCapture Object
  /* hatena */
  std::string input_index;
  if(argc > 1){ // capture from video file
    input_index = argv[1];
    /* hatena */
  }else{ // capture from camera
    /* hatena */
  }

  // 2. prepare VideoWriter Object
  cv::Mat frame, copy_frame;
  int rec_mode = 0;

  cv::namedWindow("video", 1);
  /* hatena */
  /* hatena */
  /* using "MJPG" as the video codec */

  if(!cap.isOpened() || !output_video.isOpened()){
    printf("no input video\n");
    return 0;
  }
  else 
  {
    bool loop_flag = true;
    while(loop_flag){

      // 3. capture frame from VideoCapture
      /* hatena */
      if(frame.empty()){
        break;
      }

      // 4. save frame
      if(rec_mode){
        /* hatena */
        /* hatena */
        /* hatena */
        /* hatena */
	/* hatena */
        cv::imshow("video", copy_frame);  
      }
      else{
        cv::imshow("video", frame);  
      }

      // 5. process according to input key
      int k = cv::waitKey(33);
      switch(k){
      case 'q':
      case 'Q':
        loop_flag = false;
        break;
      case 'r':
        if(rec_mode == 0){
          rec_mode = 1;
        }else{
          rec_mode = 0;
        }
        break;
      }
    }
  }
  return 0;
}
