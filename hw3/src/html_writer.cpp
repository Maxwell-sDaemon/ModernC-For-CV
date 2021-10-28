#include "helper.hpp"
#include "web_utils.hpp"
#include <iomanip>
#include <iostream>

void html_writer::OpenDocument() {
  std::cout << "<!DOCTYPE html>" << std::endl;
  std::cout << "<html>" << std::endl;
}

void html_writer::CloseDocument() { std::cout << "</html>" << std::endl; }

void html_writer::AddCSSStyle(const std::string &stylesheet) {
  std::cout << "<head>" << std::endl;
  std::cout << R"(<link rel="stylesheFet " type=" text/css " href=")"
            << stylesheet << R"("/>)" << std::endl;
  std::cout << "</head>" << std::endl;
}

void html_writer::AddTitle(const std::string &title) {
  std::cout << "<title>" << title << "</title>" << std::endl;
}

void html_writer::OpenBody() { std::cout << "<body>" << std::endl; }

void html_writer::CloseBody() { std::cout << "</body>" << std::endl; }

void html_writer::OpenRow() {
  std::cout << R"(<div class="row">)" << std::endl;
}

void html_writer::CloseRow() { std::cout << R"(</div)" << std::endl; }

void html_writer::AddImage(const std::string &img_path, float score,
                           bool highlight) {
  std::string path2filename = img_path;
  const std::string style =
      (highlight == true) ? " style=border : 5px solid green " : "";
  std::cout << R"(<div class="column" )" << style << R"(" >)" << std::endl;
  std::cout << "<h2> " << file_path_helper::filename(path2filename) << "</h2>"
            << std::endl;

  std::cout << R"(<img src=")" << img_path << R"(")" << std::endl;
  std::cout << "<p>score = " << std::setprecision(2) << std::fixed << score
            << "</p>";
  std::cout << R"(</div>)" << std::endl;
}
