#ifndef ASCII_IMAGE_HPP
#define ASCII_IMAGE_HPP

#include <iostream>
#include <fstream>
#include "raw_image.hpp"

const char* ASCII_CHARS = " .`,:\"^`_-\'!Ii><~+*jftrxunvczXYUJCLQ0OZmwdbqkhao*#MW&8B%@$";

int getGrayscaleValue(uint8_t r, uint8_t g, uint8_t b) {
  return static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);
}

char pixelToAscii(int grayValue) {
  int index = (grayValue * (strlen(ASCII_CHARS)-1)) / 255;\
  return ASCII_CHARS[index];
}

void createAsciiArt(const RawImage &img, const char* output_filename) {
  std::ofstream outputFile(output_filename, std::ios::trunc) ;
  
  if (!outputFile) {
    throw std::runtime_error("Error opening file!");
  }

  std::streambuf* originalCoutBuffer = std::cout.rdbuf();

  std::cout.rdbuf(outputFile.rdbuf());

  int width = img.getWidth();
  int height = img.getHeight();
  int size = img.getSize();
  uint8_t* data = img.getData();
  
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      size_t pixelIndex = (y * width + x) * 3;  // RGB data assumes 3 channels
      uint8_t r = data[pixelIndex];
      uint8_t g = data[pixelIndex + 1];
      uint8_t b = data[pixelIndex + 2];
      
      int grayValue = getGrayscaleValue(r, g, b);
      char asciiChar = pixelToAscii(grayValue);
      std::cout << asciiChar; 
    }
  std::cout << std::endl; // New line after each row
  }
  
  std::cout.rdbuf(originalCoutBuffer);
}

#endif // ASCII_IMAGE_HPP