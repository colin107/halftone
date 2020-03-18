/*

CSCI 3280, Introduction to Multimedia Systems
Spring 2020

Assignment 01 Skeleton

halftone.cpp

*/

#include "bmp.h"		//	Simple .bmp library

#include <iostream> 



using namespace std;
#define MAX_SHADES 3

#define SAFE_FREE(p)  { if(p){ free(p);  (p)=NULL;} }


int main(int argc, char** argv)
{
	//
	//	Your code goes here ....
	//
	//	1. Open BMP file 
	//  you can use the following parameters for testing,
	//  remember to modify it based on the user input.
	//int imagesize = 64;
	//int patchsize = 16;
	//Bitmap image_data("monokuma.bmp"); 
	char* input_bmp;
	int imagesize, patchsize;
	//istringstream iss(argv[2]);
	//istringstream iss2(argv[3]);
	//iss >> imagesize;
	//iss2 >> patchsize;
	input_bmp = argv[1];
	imagesize = atoi(argv[2]);
	patchsize = atoi(argv[3]);
	Bitmap image_data(input_bmp);
	Bitmap input_0("patch/0.bmp");
	Bitmap input_1("patch/1.bmp");
	Bitmap input_2("patch/2.bmp");
	
	image_data.resize(imagesize);//64
	input_0.resize(patchsize);//16
	input_1.resize(patchsize);
	input_2.resize(patchsize);
	//	2. Load image patches
	//
	//
	//	3. Obtain Luminance
	//
	int gray_value;
	int quantized_value;
	Bitmap output(image_data.getWidth() * input_0.getWidth(), image_data.getHeight() * input_0.getHeight());
	//Bitmap output(image_data.getWidth() * patchsize, image_data.getHeight() * patchsize);
	for (int i = 0; i < image_data.getWidth(); i++) {
		for (int j = 0; j < image_data.getHeight(); j++) {

			image_data.getColor(i, j, image_data.getData()->R, image_data.getData()->G, image_data.getData()->B);
			gray_value = 0.299 * image_data.getData()->R + 0.587 * image_data.getData()->G + 0.114 * image_data.getData()->B;
			quantized_value = floor(gray_value / ((double)256 / (double)3));

			if (quantized_value == 0) {
				for (int k = 0; k < patchsize ; k++) {
					for (int l = 0; l < patchsize ; l++) {

						input_0.getColor(k, l, input_0.getData()->R, input_0.getData()->G, input_0.getData()->B);
						output.setColor(i * patchsize + k, j * patchsize + l, input_0.getData()->R, input_0.getData()->G, input_0.getData()->B);
					}
				}
			}
			else if (quantized_value == 1) {
				for (int k = 0; k < patchsize; k++) {
					for (int l = 0; l < patchsize; l++) {

						input_1.getColor(k, l, input_1.getData()->R, input_1.getData()->G, input_1.getData()->B);
						output.setColor(i * patchsize + k, j * patchsize + l, input_1.getData()->R, input_1.getData()->G, input_1.getData()->B);

					}
				}
			}
			else if (quantized_value == 2) {
				for (int k = 0; k < patchsize; k++) {
					for (int l = 0; l < patchsize; l++) {
						input_2.getColor(k, l, input_2.getData()->R, input_2.getData()->G, input_2.getData()->B);
						output.setColor(i * patchsize + k, j * patchsize + l, input_2.getData()->R, input_2.getData()->G, input_2.getData()->B);
					}
				}
			}
		}
	}


	output.save("output.bmp");
	//output_test.save("output_test.bmp");
	//
	//	4. Quantization
	//
	//int quantized_value;

	//quantized_value = floor(gray_value / ((double)256 / (double)3));
	//cout << "quantized_value" << endl;
	//cout << quantized_value << endl;
	
	//
	//  5. Generate bmp image and parse patches according to quantized image
	//
	
	//  free memory

	return 0;
} 