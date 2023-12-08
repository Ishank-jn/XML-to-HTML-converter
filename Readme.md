
XML to HTML Converter
Overview

xml_to_html C++ program takes cd_catalog.xml containing a catalog of CDs and converts it into an HTML file with a table format. The output HTML file displays information about each CD, including title, artist, country, company, price, and year.

Prerequisites
1. C++ Compiler

2. RapidXML Library: I am using RapidXML library for XML parsing. I have included RapidXML.hpp with the folder. You can find more info on RapidXML GitHub.

How to Compile
Open a terminal window.

Navigate to the directory containing xml_to_html.cpp.

Compile the C++ program using the following command:

bash
1. Genetate executable file
g++ -o xml_to_html xml_to_html.cpp

2. run make

How to Run
After compiling the program, run it with the following command:

bash
Copy code
./xml_to_html cd_catalog.xml output.html

Notes
1. The program assumes a Linux environment (I used Ubuntu 20.04).

2. Sample output file 'output.html' is also provided in the folder.

3. I also included the executable file. If you want to test compilation or make, please delete
executable file and compile the code as suggested above.

References on Google:
1. https://gist.github.com/JSchaenzle/2726944
2. https://copyprogramming.com/howto/how-to-parse-an-xml-file-with-rapidxml

Author
This C++ program was authored by Ishank Jain.