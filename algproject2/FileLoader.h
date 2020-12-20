#pragma once
///Class <code>Fileloader</code> is used for loading from txt file and setting variables.
class FileLoader
{
public:
///open file then set rows of nodes and set edges
	void loadGraph();
///@return nodes
	int getNodes();
///@return src
	int* getSrc();
///@return dest
	int* getDest();
///@return Rows in file - first row for number of nodes
	int getRows();
	
private:
///open file
	void openFile();
///close file
	void closeFile();
///set nodes from file
	void setNodes();
///set edges from file
	void setEdges();
///defining edges
	void defineEdges();
	void setRows();
};


