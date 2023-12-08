#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rapidxml.hpp"

using namespace rapidxml;  // Use rapidxml namespace
using namespace std;       // Use standard namespace

// convertXmlToHtml converts XML to HTML table
void convertXmlToHtml(const char* inputXmlFile, const char* outputHtmlFile) {
    // Read the XML file
    ifstream xmlFile(inputXmlFile);  // Open input XML file
    vector<char> buffer((istreambuf_iterator<char>(xmlFile)), istreambuf_iterator<char>()); // read the entire content of a file into a vector of characters
    buffer.push_back('\0');  // add null terminator to the end of vector

    // Parsing the XML document
    xml_document<> doc;  // Create a RapidXML document
    doc.parse<0>(&buffer[0]);  // Parse the XML content

    // Creating HTML file and write into the table
    ofstream htmlFile(outputHtmlFile);  // Open the output HTML file
    htmlFile << "<!DOCTYPE html>\n";    // HTML doctype declaration
    htmlFile << "<html>\n";             // HTML element
    htmlFile << "<head>\n";             // head element
    htmlFile << "<title>CD Catalog</title>\n";  // Set the HTML title
    htmlFile << "</head>\n";            // Close the head element
    htmlFile << "<body>\n";             // Open the body element
    htmlFile << "<table border=\"1\">\n";        // Open the table element
    htmlFile << "<tr><th>Title</th><th>Artist</th><th>Country</th><th>Company</th><th>Price</th><th>Year</th></tr>\n";  // Write table headers

    // Iterate through CD elements and populate the table
    for (xml_node<>* cdNode = doc.first_node("CATALOG")->first_node("CD"); cdNode; cdNode = cdNode->next_sibling()) {
        htmlFile << "<tr>";  // Open a table row
        htmlFile << "<td>" << cdNode->first_node("TITLE")->value() << "</td>";    // Insert CD title
        htmlFile << "<td>" << cdNode->first_node("ARTIST")->value() << "</td>";   // Insert CD artist
        htmlFile << "<td>" << cdNode->first_node("COUNTRY")->value() << "</td>";  // Insert CD country
        htmlFile << "<td>" << cdNode->first_node("COMPANY")->value() << "</td>";  // Insert CD company
        htmlFile << "<td>" << cdNode->first_node("PRICE")->value() << "</td>";    // Insert CD price
        htmlFile << "<td>" << cdNode->first_node("YEAR")->value() << "</td>";     // Insert CD year
        htmlFile << "</tr>\n";  // Close the table row
    }

    // Close all HTML tags
    htmlFile << "</table>\n";  // Close table element
    htmlFile << "</body>\n";   // Close body element
    htmlFile << "</html>\n";   // Close HTML element
}

int main(int argc, char* argv[]) {
    // Check command-line arguments is provided
    if (argc != 3) {
        cout << "Incorrect usage: " << argv[0] << " <input_xml_file> <output_html_file>" << endl;
        return 1;  // Exit the program with an error code
    }

    // Read from command-line arguments
    const char* inputXmlFile = argv[1];
    const char* outputHtmlFile = argv[2];

    // convert XML to HTML
    convertXmlToHtml(inputXmlFile, outputHtmlFile);

    cout << "Conversion from xml to html is complete. HTML file created: " << outputHtmlFile << endl;

    return 0;  // Exit the program successfully
}
