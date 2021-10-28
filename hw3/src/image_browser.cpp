#include "web_utils.hpp"
// using ScoredImage = std::tuple<std::string, float>;
// using ImageRow = std::array<ScoredImage, 3>;

void image_browser::CreateImageBrowser(const std::string &title,
                                       const std::string &stylesheet,
                                       const std::vector<ImageRow> &rows) {
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  for (auto imageRow : rows) {
    image_browser::AddFullRow(imageRow);
  }
}

void image_browser::AddFullRow(const ImageRow &row, bool first_row) {
  for (const ScoredImage &scored_image : row) {
    auto [path_name, precision] = scored_image;
    html_writer::AddImage(path_name, precision, first_row);
  }
}