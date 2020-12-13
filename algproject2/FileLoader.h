#pragma once
class FileLoader
{
public:
	void loadGraph();
	int getNodes();
	int* getSrc();
	int* getDest();
	int getRows();
private:
	void openFile();
	void closeFile();
	void SetNodes();
	void setEdges();
	void defineEdges();
};


