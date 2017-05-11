#include <iostream>
#include <mxnet-cpp/MxNetCpp.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace mxnet::cpp;

uint get(cv::Mat *in, int x, int y, int c){

	return (*in).at <cv::Vec3b> (cv::Point(x, y))[c];

}

int main(){

  	Context device(DeviceType::kGPU, 0);

  	cv::Mat im = cv::imread("test.jpg", 1);

	cv::Mat im2(im.size().height, im.size().width, CV_32FC3);

	im.convertTo(im2, CV_32FC3, 1 / 255.0);

	cout << "im2 : " << get(&im2, 10, 10, 1) << endl;


	cv::imshow("image", im2);

	cv::waitKey(0);

	Shape sim = Shape(im.size().height, im.size().width, im.channels());

	NDArray ndim = NDArray(sim, device);

	float *fData = (float*)im2.data;

	ndim.SyncCopyFromCPU(fData, im.size().height * im.size().width * im.channels());

	/*

	initialize ndarray, and assign initial value

	*/



	/*

	initialize symbol

	*/

	auto x = Symbol::Variable("x");

	auto z = x + 0;
	/*

	build computation graph

	*/



	/*

	assgin ndarray to corresponding variable

	*/


	map <string, NDArray> feed;

	feed["x"] = ndim;
	//auto exe = z.bind(device, feed);

	NDArray::WaitAll();

	/*

	Bind Executor

	*/

	Executor *exe = z.SimpleBind(device, feed);

	(*exe).Forward(false);






	vector <NDArray> &output = (*exe).outputs;

	float *fptr = new float[im.size().height * im.size().width * im.channels()];



	output[0].SyncCopyToCPU(fptr, im.size().height * im.size().width * im.channels());

	NDArray::WaitAll();
	//Mat I(480, 640, CV_32FC3, Idata);

	//cout << *(fptr + 2) << endl;

	cv::Mat oim(im.size().height, im.size().width, CV_32FC3, fptr);

	cout << get(&oim, 10, 10, 1) << endl;

	cv::imshow("image", oim);

	cv::waitKey(0);

}
