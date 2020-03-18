CSCI 3280 Introduction to Multimedia Systems
Spring 2020, Assignment 1 - Halftone

Make sure the current directory has a folder called "patch" where including 3 files called "0.bmp", "1.bmp" and "2.bmp".
The program would call these by "patch/0.bmp", "patch/1.bmp" and "patch/2.bmp".


1. halftone.cpp

1.1. We will use Visual Studio 2015 C++ compiler and have your program compiled via visual studio command prompt (Tools->Command Prompt) and the following command line.
C:\> cl halftone.cpp bmp.cpp

1.2. The compiled program must run in Windows 10 command prompt as a console program and accepts source bitmap (.bmp format) with the following syntax and save generated images to the current directory.
C:\> halftone <input.bmp> <size1> <size2>
<input.bmp> : The path name to the source bitmap
<size1> : The size of content image. It must be an integer.
<size2> : The size of patch image. It must be an integer that equal to 2^n, where n is an integer and n > 0.
e.g. halftone monokuma.bmp 64 16

1.3. It will generate an image called "output.bmp".

2. halftone_bonus.cpp
The different between halftone_bonus.cpp and halftone.cpp : Cropping unwanted blackground and focussing on the message
The program quantize based on statistic information and resize the image by cropping width.

2.1. We will use Visual Studio 2015 C++ compiler and have your program compiled via visual studio command prompt (Tools->Command Prompt) and the following command line.
C:\> cl halftone_bonus.cpp bmp.cpp

2.2. The compiled program must run in Windows 10 command prompt as a console program and accepts source bitmap (.bmp format) with the following syntax and save generated images to the current directory.
C:\> halftone_bonus <input.bmp> <size1> <size2>
<input.bmp> : The path name to the source bitmap
<size1> : The size of content image. It must be an integer.
<size2> : The size of patch image. It must be an integer that equal to 2^n, where n is an integer and n > 0.
e.g. halftone_bonus monokuma.bmp 64 16

2.3 It will generate an image called "output_bonus.bmp".