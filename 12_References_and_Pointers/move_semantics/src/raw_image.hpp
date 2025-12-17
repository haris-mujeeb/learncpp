#ifndef RAW_IMAGE_HPP
#define RAW_IMAGE_HPP

#include <cstdint>
#include <cstddef>
#include <cstring>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class RawImage
{
private:
  int m_width, m_height, m_channels ;
  size_t m_size;
  uint8_t* m_data = nullptr;
  static inline int s_live_objects = 0;
public:
  RawImage(int width, int height, int channels);
  RawImage(const char* filename);
  ~RawImage();
  
  RawImage(const RawImage &other);
  RawImage& operator= (const RawImage &other);

  RawImage(RawImage &&other) noexcept;
  RawImage& operator= (RawImage &&other) noexcept;

  size_t getSize() const { return m_size; }
  int getWidth() const { return m_width; }
  int getHeight() const { return m_height;}
  int getChannels() const { return m_channels;}
  uint8_t* getData() const { return m_data; }
  static int get_live_count() { return s_live_objects; }
};

RawImage::RawImage(int width, int height, int channels = 3) 
: m_width(width), m_height(height), m_channels(channels) {
  m_size = static_cast<size_t>(m_width * m_height * m_channels);
  m_data = new uint8_t[m_size];
  s_live_objects++;
}

RawImage::RawImage(const char* filename) {
    uint8_t* temp_data = stbi_load(filename, &m_width, &m_height, &m_channels, 0);
    if (!temp_data) {
        throw std::runtime_error("Failed to load image");
    }

    m_size = static_cast<size_t>(m_width * m_height * m_channels);
    m_data = new uint8_t[m_size];
    std::memcpy(m_data, temp_data, m_size);
    stbi_image_free(temp_data); // Free the original image

    s_live_objects++;
} 
  
  RawImage::RawImage(const RawImage &other) 
: m_width(other.m_width), m_height(other.m_height), m_channels(other.m_channels), m_size(other.m_size) {
  m_data = new uint8_t[m_size];
  std::memcpy(m_data, other.m_data, m_size);
  s_live_objects++;
}

RawImage& RawImage::operator= (const RawImage &other)
{
  if (this != &other) { // self-assignment check
    delete[] m_data;    // free current memory

    // Copy from other
    m_width = other.m_width; 
    m_height = other.m_height;
    m_channels = other.m_channels;
    m_size = other.m_size;

    m_data = new uint8_t[m_size];   // Allocate new memory
    std::memcpy(m_data, other.m_data, m_size);  // Copy data from other
  }
  return *this; // Return current object by reference
}

RawImage::RawImage(RawImage &&other) noexcept
: m_width(other.m_width), m_height(other.m_height), m_channels(other.m_channels), m_size(other.m_size), m_data(other.m_data) {
  // Steal the resources
  other.m_data = nullptr;
  other.m_size = 0;
  other.m_width = 0;
  other.m_height = 0;
  other.m_channels = 0;
  s_live_objects++;
}

RawImage& RawImage::operator= (RawImage &&other) noexcept {
  if (this != &other) {
    // Free existing resource
    delete[] m_data;

    // Steal resources
    m_data = other.m_data;
    m_width = other.m_width;
    m_height = other.m_height;
    m_channels = other.m_channels;
    m_size = other.m_size;

    // Reset source
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_width = 0;
    other.m_height = 0;
    other.m_channels = 0;
  }
  return *this;
}

RawImage::~RawImage()
{
  if(m_data) {
    delete[] m_data;
    s_live_objects--;
  }
}


#endif // RAW_IMAGE_HPP