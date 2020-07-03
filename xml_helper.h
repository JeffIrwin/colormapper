
#pragma once

#include <colormapper_constants.h>
#include <pugixml.hpp>

namespace irwincolor
{

class XPathException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "No match for XPath expression.";
  }
} xPathException;

int loadXml(std::string& fxml, pugi::xml_document& doc)
{
	pugi::xml_parse_result result = doc.load_file(fxml.c_str());
	if (!result)
	{
		std::cout << "\nError:  cannot open or parse XML file \""
				<< fxml << "\"." << std::endl;
		return ERR_XML_OPEN;
	}
	return 0;
}

} // namespace irwincolor

