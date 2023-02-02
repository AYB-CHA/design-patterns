#include <iostream>

using namespace std;

class Compressor {
public:
  virtual void compress(string image_path) = 0;
};

class PngCompressor : public Compressor {
public:
  void compress(string image_path);
};

void PngCompressor::compress(string image_path) {
  cout << "compressing png image " << image_path << endl;
}
class Filter {
public:
  virtual void filter(string image_path) = 0;
};

class BlackAndWhite : public Filter {
public:
  void filter(string image_path);
};

void BlackAndWhite::filter(string image_path) {
  cout << "applaing black and  white filter on image " << image_path << endl;
}

class ImageStorage {
public:
  ImageStorage(Compressor *compressor, Filter *filter, string image_path);
  void store();

private:
  Filter *filter;
  Compressor *compressor;
  string image_path;
  void compress();
  void applayFilter();
};

ImageStorage::ImageStorage(Compressor *compressor, Filter *filter,
                           string image_path)
    : compressor(compressor), filter(filter), image_path(image_path) {}
void ImageStorage::applayFilter() { this->filter->filter(this->image_path); }
void ImageStorage::compress() { this->compressor->compress(this->image_path); }
void ImageStorage::store() {
  this->applayFilter();
  this->compress();
}
int main(int argc, char const *argv[]) {
  ImageStorage storage(new PngCompressor, new BlackAndWhite, "image.png");
  storage.store();
  return 0;
}
