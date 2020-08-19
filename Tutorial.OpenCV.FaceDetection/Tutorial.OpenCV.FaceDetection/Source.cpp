#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);
	cap.open(0);
	Mat img;
	CascadeClassifier face_cascade;
	face_cascade.load("C:\\Work\\opencv-4.4.0\\opencv-4.4.0\\data\\haarcascades\\haarcascade_frontalface_alt2.xml");
	for (;;)
	{
		cap >> img;
		cap.retrieve(img, CAP_OPENNI_BGR_IMAGE);
		//resize(img, img, Size(1000, 640));
		vector<Rect> faces;
		face_cascade.detectMultiScale(img, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(140, 140));
		for (int i = 0; i < faces.size(); i++)
		{
			Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
			ellipse(img, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
		}
		imshow("face detect", img);
		const char key = (char)waitKey(5);
		if (key == 27 || key == 'q') // ESC
		{
			cout << "Exit requested" << endl;
			break;
		}
	}
}