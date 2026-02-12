#include <opencv2/opencv.hpp>

// 640 x 480
void add(cv::Mat dst, int value)
{
	//cv::
	//dst += b;
	uint8_t* data = dst.data;
	int width = dst.cols; //이미지의 가로 픽셀 수  
	int height = dst.rows; //이미지의 세로 픽셀 수 
	int st = dst.step1(); //BGR의 경우 width * 3

	//printf("%d %d %d \n", width, height, st); // 640 480 1920

	for (int x = 200; x < 500; x++)
	{
		for (int y = 300; y < 500; y++)
		{
			int b = data[y * st + x * 3 + 0] + value;
			if (b > 255) b = 255;

			int g = data[y * st + x * 3 + 1] + value;
			if (g > 255) g = 255;

			int r = data[y * st + x * 3 + 2] + value;
			if (r > 255) r = 255;

			data[y * st + x * 3 + 0] = b;
			data[y * st + x * 3 + 1] = g;
			data[y * st + x * 3 + 2] = r;
		}
	}

	// 가로로 까만줄을 긋는다.

	int y = 30;
	for (int x = 0; x < width; x++)
	{
		*(data + y * st + x * 3 + 0) = 0;
		*(data + y * st + x * 3 + 1) = 0;
		*(data + y * st + x * 3 + 2) = 0;

	}

	//x1 = 20, y1 = 20
	//x2 = 100, y2 = 300
	// 초록색 사각형
   
	int x1 = 20;
	int y1 = 20;
	int x2 = 100;
	int y2 = 300;

	uint8_t* rt = data + y1 * st + x1 * 3;
	//[B G R] [B G R] [B G R] ....

	int bw = x2 - x1;
	int bh = y2 - y1;

	for (int y = 0; y < bh; y++)
	{
		uint8_t* row = rt + y * st;

		for (int x = 0; x < bw; x++)
		{
			uint8_t* px = row + x * 3;

			// 초록색
			px[0] = 0;
			px[1] = 255;
			px[2] = 0;
		}
	}
}

void add2(cv::Mat dst, int value)
{
	//영상 전체에 b를 더하는 함수
	//data 활용해서 구현

	uint8_t* data = dst.data;
	int width = dst.cols; //이미지의 가로 픽셀 수  
	int height = dst.rows; //이미지의 세로 픽셀 수 

	for (int y = 0; y < height ; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int v = data[y * width + x] + value;
			if (v > 255) v = 255;
			data[y * width + x] = v;
		}
	}

}

int main()
{
	cv::Mat image = cv::imread("k.jpg");
	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
	cv::Mat dst;
	image.copyTo(dst);

	//dst = dst + 50;
	//add(dst, 100);
	add2(dst, 100);
	cv::imshow("test", dst);
	cv::waitKey(0);
}