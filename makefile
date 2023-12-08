all: xml_to_html

xml_to_html: xml_to_html.cpp
	g++ -o xml_to_html xml_to_html.cpp

clean:
	rm -f xml_to_html
