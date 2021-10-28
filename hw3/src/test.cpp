#include "helper.hpp"
#include "path.hpp"
#include "web_utils.hpp"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>
#include <random>
// using ScoredImage = std::tuple<std::string, float>;
// using ImageRow = std::array<ScoredImage, 3>;
using namespace image_browser;
using namespace html_writer;
namespace fs = boost::filesystem;

void printImageRows(std::vector<ImageRow> img_rows) {
  for (ImageRow row : img_rows) {
    for (ScoredImage img : row) {
      auto &[filepath, precision] = img;
      std::cout << "(" << filepath << "," << precision << ")" << std::endl;
    }
  }
}

const std::vector<ImageRow>
createImageRowsFromData(const std::string &filepath) {
  // std::cout << filepath << std::endl;
  std::vector<ImageRow> img_rows;

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<float> distribution(0, 1);

  /* generate ten random numbers in [1,6] */
  // for (size_t i = 0; i < 10; ++i) {
  //   std::cout << distribution(generator) << ' ';
  // }

  fs::path p{filepath};
  std::cout << p << std::endl;
  fs::directory_iterator it{p};

  // std::cout << "size is " << p.size() << std::endl;
  if (fs::exists(filepath)) {
    for (auto it = fs::directory_iterator(p); it != fs::directory_iterator{};) {
      auto temp_it = it;

      ImageRow row;
      size_t i = 0;
      while (i < TABLE_ROW) {
        float precision = distribution(generator);
        ScoredImage img =
            std::make_tuple(fs::absolute(*temp_it++).string(), precision);
        row.fill(img);
        i++;
      }

      img_rows.push_back(row);

      // std::cout << *it++ << "," << distribution(generator) << std::endl;
    }
    printImageRows(img_rows);
    return img_rows;
  } else {
    throw std::invalid_argument("there is no path exists.");
  }
}

int main() {

  // test 1
  test_utils::initTest(1);
  html_writer::OpenDocument();
  html_writer::AddTitle("Image Browser");
  html_writer::AddCSSStyle("deneme.css");
  html_writer::OpenRow();
  html_writer::AddImage("deneme.jpg", 1.0055f);
  html_writer::CloseRow();
  html_writer::CloseDocument();

  // test 2 AddImage with true
  test_utils::initTest(2);
  html_writer::OpenDocument();
  html_writer::AddTitle("Image Browser");
  html_writer::AddCSSStyle("deneme.css");
  html_writer::OpenRow();
  html_writer::AddImage("deneme.jpg", 1.0055f, true);
  html_writer::CloseRow();
  html_writer::CloseDocument();

  test_utils::initTest(3);
  const std::vector<ImageRow> &rows = createImageRowsFromData(IMAGE_PATH);

  test_utils::initTest(4);
  image_browser::CreateImageBrowser("Image Browser", "style.css", rows);
}