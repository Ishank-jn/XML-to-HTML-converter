#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rapidxml.hpp"

using namespace rapidxml;  // Use rapidxml namespace
using namespace std;       // Use standard namespace

// convertXmlToHtml converts XML to HTML table
void convertXmlToHtml(const char* inputXmlFile, const char* outputhtmlDoc) 
{
    // Read the XML file
    ifstream xmlFile(inputXmlFile);  // Open input XML file
    vector<char> buffer((istreambuf_iterator<char>(xmlFile)), istreambuf_iterator<char>()); // read the entire content of a file into a vector of characters
    buffer.push_back('\0');  // add null terminator to the end of vector

    // Parsing the XML document
    xml_document<> doc;  // Create a RapidXML document
    doc.parse<0>(&buffer[0]);  // Parse XML content

    // Creating HTML file and write into the table
    ofstream htmlDoc(outputhtmlDoc);  // Open output HTML file
    htmlDoc << "<!DOCTYPE html>\n";    // HTML doctype declaration
    htmlDoc << "<html>\n";             // HTML element
    htmlDoc << "<head>\n";             // head element
    htmlDoc << "<title>CD Catalog</title>\n";  // Set HTML title
    htmlDoc << "</head>\n";            // Close the head element
    htmlDoc << "<body>\n";             // Open the body element
    htmlDoc << "<table border=\"1\">\n";        // Open table element
    htmlDoc << "<tr><th>Title</th><th>Artist</th><th>Country</th><th>Company</th><th>Price</th><th>Year</th></tr>\n";  // Write table headers

    // Iterate through CD elements and populate the table
    for (xml_node<>* cdNode = doc.first_node("CATALOG")->first_node("CD"); cdNode; cdNode = cdNode->next_sibling()) 
    {
        htmlDoc << "<tr>";  // Open a table row
        htmlDoc << "<td>" << cdNode->first_node("TITLE")->value() << "</td>";    // Insert CD title
        htmlDoc << "<td>" << cdNode->first_node("ARTIST")->value() << "</td>";   // Insert CD artist
        htmlDoc << "<td>" << cdNode->first_node("COUNTRY")->value() << "</td>";  // Insert CD country
        htmlDoc << "<td>" << cdNode->first_node("COMPANY")->value() << "</td>";  // Insert CD company
        htmlDoc << "<td>" << cdNode->first_node("PRICE")->value() << "</td>";    // Insert CD price
        htmlDoc << "<td>" << cdNode->first_node("YEAR")->value() << "</td>";     // Insert CD year
        htmlDoc << "</tr>\n";  // Close the table row
    }

    // Close all HTML tags
    htmlDoc << "</table>\n";
    htmlDoc << "</body>\n";
    htmlDoc << "</html>\n";
}

int main(int argc, char* argv[]) 
{
    // Check command-line arguments is provided
    if (argc != 3) 
    {
        cout << "Incorrect usage: " << argv[0] << " <input_xml_file> <output_html_file>" << endl;
        return 1;  // Exit the program with an error code
    }

    // Read from command-line arguments
    const char* inputXmlFile = argv[1];
    const char* outputhtmlDoc = argv[2];

    // convert XML to HTML
    convertXmlToHtml(inputXmlFile, outputhtmlDoc);

    cout << "Conversion from xml to html is complete. HTML file created: " << outputhtmlDoc << endl;

    return 0;  // Exit the program successfully
}
