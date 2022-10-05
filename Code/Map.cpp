#include "Map.h"

Map::Map(string setupFile)
{
	std::string filename(setupFile);
	std::vector<std::string> lines;
	std::string line;

	std::ifstream inputFile(setupFile);

	while (getline(inputFile, line))
	{
		lines.push_back(line);
	}
	cout<<"15"<<endl;
	for (int i = 0; i < lines.size(); i++)
		cout << lines.at(i) << endl;

	inputFile.close();

	int fileIndex = 0;
	std::vector<std::string> lineParts = {};
	cout<<"23"<<endl;
	/*
		Initialising the adjacency matrix
	*/
	int totalAreas = stoi(lines.at(0));
	this->adjacencies = new TransportRoute **[totalAreas];
	for (int i = 0; i < totalAreas; i++)
	{
		adjacencies[i] = new TransportRoute *[totalAreas];
	}

	for (int i = 0; i < totalAreas; i++)
	{
		for (int j = 0; j < totalAreas; j++)
		{
			adjacencies[i][j] = NULL;
		}
	}
	cout<<"41"<<endl;
	fileIndex++;
	for (int k = 0; k < totalAreas; k++)
	{
		cout<<"45"<<endl;
		/*
		Breakup the line into two parts, area details and its neighbors e.g. "A0,0:1,2,3" becomes {"A0,0","1,2,3"}
		*/
		std::string temp = "";
		for (int i = 0; i < lines.at(fileIndex).length(); i++)
		{
			if (lines.at(fileIndex).at(i) == ':')
			{
				lineParts.push_back(temp);
				temp = "";
			}
			else
			{
				temp += (lines.at(fileIndex).at(i));
				if (i == lines.at(fileIndex).length() - 1)
				{
					lineParts.push_back(temp);
					temp = "";
				}
			}
		}
		cout<<"66"<<endl;
		/*
		Breakup the area details into two parts, name and index e.g. "A0,0" becomes {"A0","0"}
		*/
		std::vector<std::string> areaParts = {};
		temp = "";
		for (int i = 0; i < lineParts.at(0).length(); i++)
		{
			if (lineParts.at(0).at(i) == ',')
			{
				areaParts.push_back(temp);
				temp = "";
			}
			else
			{
				temp += (lineParts.at(0).at(i));
				if (i == lineParts.at(0).length() - 1)
				{
					areaParts.push_back(temp);
					temp = "";
				}
			}
		}
	cout<<"90"<<endl;
		/*
		Breakup the neighbors into individual numbers e.g. "1,2,3" becomes {"1","2","3"}
		*/
		std::vector<std::string> areaAdjacencies = {};
		temp = "";
		for (int i = 0; i < lineParts.at(1).length(); i++)
		{
			if (lineParts.at(1).at(i) == ',')
			{
				areaAdjacencies.push_back(temp);
				temp = "";
			}
			else
			{
				temp += (lineParts.at(1).at(i));
				if (i == lineParts.at(1).length() - 1)
				{
					areaAdjacencies.push_back(temp);
					temp = "";
				}
			}
		}
		fileIndex++;
		/*
		Add area to all areas
		*/
		allAreas.push_back(new Area(stoi(areaParts.at(1))));

		/*
		Set adjacencies in the adjacency matrix
		*/
		for (int i = 0; i < areaAdjacencies.size(); i++)
		{
			adjacencies[stoi(areaParts.at(1))][stoi(areaAdjacencies.at(i))]=new TransportRoute();
		}
		

	}

	setAllEndPoints();
}

string Map::createTransportRoutes(Area *area1, Area *area2)
{
	// TODO - implement Map::createTransportRoutes
	throw "Not yet implemented";
}

Area *Map::chooseArea()
{
	// TODO - implement Map::chooseArea
	throw "Not yet implemented";
}

string Map::destroyTransportRoute(Area *area1)
{
	// TODO - implement Map::destroyTransportRoute
	throw "Not yet implemented";
}

vector<Area *> Map::listAdjacent(::Area *area)
{
	// TODO - implement Map::listAdjacent
	throw "Not yet implemented";
}

void Map::update()
{
	// TODO - implement Map::update
	throw "Not yet implemented";
}

void Map::setAllEndPoints(){
	for (int i = 0; i < allAreas.size(); i++)
	{
		for (int j = 0; j < allAreas.size(); j++)
		{
			if (adjacencies[i][j]!=NULL)
			{
				adjacencies[i][j]->setEndPoints(allAreas.at(i),allAreas.at(j));
			}
			
		}
		
	}
	
}
