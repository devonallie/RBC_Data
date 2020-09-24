#include <iostream>

#include "poppler-document.h"
#include "poppler-page.h" 
#include "poppler-toc.h"

using namespace poppler;

std::string to_utf8(ustring x){
  if(x.length()){
    byte_array buf = x.to_utf8();
    return std::string(buf.data(), buf.size());
  } else {
    return std::string("null");
  }
}

int main()
{
	document* doc = document::load_from_file("statements/test.pdf");
	page *p(doc->create_page(0));
	std::cout << "\n TEST: \n" << std::endl;
	for (text_box& i: p->text_list())
	std::cout << to_utf8(i.text()) << std::endl;
  	return 0;
}
