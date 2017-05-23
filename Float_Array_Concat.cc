#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(){

	cv::Mat im1 = cv::imread("test.jpg", 1);

	cv::Mat im2 = cv::imread("test.jpg", 1);



	int h = im1.size().height;

	int w = im1.size().width;


	cv::Mat im11(h, w, CV_32FC3);

	cv::Mat im22(h, w, CV_32FC3);

	im1.convertTo(im11, CV_32FC3, 1 / 255.0);

	im2.convertTo(im22, CV_32FC3, 1 / 255.0);




	float *ftotal = new float [h * w * im1.channels() * 2];

	float *fim1 = (float *)im11.data;

	float *fim2 = (float *)im22.data;

	int s = h * w * im1.channels();

	cout << "1" << endl;

	// copy from

	copy(fim1, fim1 + s, ftotal + 0 * s);

	copy(fim2, fim2 + s, ftotal + 1 * s);

	cout << "2" << endl;


	float *fsplit1 = new float [h * w * im1.channels() * 1];

	float *fsplit2 = new float [h * w * im1.channels() * 1];

	//

	cout << s << endl;

	copy(ftotal + 0 * s, ftotal + 1 * s, fsplit1);

	copy(ftotal + 1 * s, ftotal + 2 * s, fsplit2);

	cv::Mat oim(h, w, CV_32FC3, fsplit1);


	cv::imshow("output", oim);

	cv::waitKey(0);

}
