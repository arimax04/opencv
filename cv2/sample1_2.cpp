#include <opencv2/opencv.hpp>
#include <stdio.h>

cv::Mat inpaint_mask;
cv::Mat original_image, whiteLined_image, inpainted;

void myMouseEventHandler(int event, int x , int y , int flags, void *){
  if(whiteLined_image.empty()){
    return;
  }
  static bool checker=true;
  static bool isBrushDown = false;
  static cv::Point prevPt;
  cv::Point pt(x,y);

  bool isLButtonPressedBeforeEvent = (bool)(flags & CV_EVENT_FLAG_LBUTTON);
  if(isLButtonPressedBeforeEvent && isBrushDown){
    //cv::rectangle(inpaint_mask,prevPt,pt,cv::Scalar(255),5,8,0);
    //cv::rectangle(whiteLined_image,prevPt,pt,cv::Scalar::all(255),5,8,0);
    //cv::imshow("image", whiteLined_image);
  }

  // The XOR below means, isLButtonPressedAfterEvent
  // is usualy equal to isLButtonPressedBeforeEvent,
  // but not equal if the event is mouse down or up.
  bool isLButtonPressedAfterEvent = isLButtonPressedBeforeEvent
    ^ ((event == CV_EVENT_LBUTTONDOWN) || (event == CV_EVENT_LBUTTONUP));
  bool isLButtonReleased= event==CV_EVENT_LBUTTONUP;
  if(isLButtonReleased){
    cv::rectangle(inpaint_mask,prevPt,pt,cv::Scalar(255),-1,8,0);
    //cv::rectangle(whiteLined_image,prevPt,pt,cv::Scalar(255),-1,8,0);
    cv::Rect roi(prevPt.x,prevPt.y,pt.x-prevPt.x,pt.y-prevPt.y);
    whiteLined_image(roi)=~whiteLined_image(roi);
    cv::imshow("image", whiteLined_image);
    checker=true;
  }
  if(isLButtonPressedAfterEvent){
    if(checker){
      prevPt=pt;
      checker=false;
    }
    isBrushDown = true;
    std::cout<<"OK!\n";
  }else{
    isBrushDown = false;
    //cv::imshow("image", whiteLined_image);
  }
}

int main(int argc, char *argv[]){

  // 1. read image file
  char *filename = (argc >= 2) ? argv[1] : (char *)"fruits.jpg";
  original_image = cv::imread(filename);
  if(original_image.empty()){
    printf("ERROR: image not found!\n");
    return 0;
  }

  //print hot keys
  printf( "Hot keys: \n"
      "\tESC - quit the program\n"
      "\ti or ENTER - run inpainting algorithm\n"
      "\t\t(before running it, paint something on the image)\n");

  // 2. prepare window
  cv::namedWindow("image");

  // 3. prepare Mat objects for processing-mask and processed-image
  whiteLined_image=original_image.clone();
  inpaint_mask=original_image.clone();
  inpaint_mask.create(original_image.size(),CV_8UC1);

  inpaint_mask=cv::Scalar(0);
  inpainted=cv::Scalar(0);

  /* hatena */
  /* hatena */

  /* hatena */
  /* hatena */

  // 4. show image to window for generating mask
  cv::imshow("image", whiteLined_image);

  // 5. set callback function for mouse operations
  cv::setMouseCallback("image",myMouseEventHandler,0);

  bool loop_flag = true;
  while(loop_flag){

    // 6. wait for key input
    int c = cv::waitKey(0);

    // 7. process according to input
    switch(c){
      case 27://ESC
      case 'q':
        loop_flag = false;
        break;

      case 'r':
        inpaint_mask = cv::Scalar(0);
        original_image.copyTo(whiteLined_image);
        cv::imshow("image", whiteLined_image);
        break;

      case 'i':
      case 10://ENTER
        cv::namedWindow("inpainted image", 1);
        cv::inpaint(whiteLined_image,inpaint_mask,inpainted,3.0,cv::INPAINT_TELEA);
        cv::imshow("inpainted image", inpainted);
        break;
    }
  }
  return 0;
}
