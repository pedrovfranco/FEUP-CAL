//
// Created by Beatriz Mendes on 29/03/2018.
//

#include "DeliveryNetwork.h"

#include <fstream>

using namespace std;

bool DeliveryNetwork::loadGraph(string aname, string bname, string cname)
{
	ifstream a(aname), b(bname), c(cname);

	if (!a.is_open() || !b.is_open() || !c.is_open())
	{
		cout << "Error opening file!\n";
		return false;
	}

	string buffer, name;
	int begin, end = 0;
	long long id1, id2, id3, id4;
	double lat, lon;
	bool bl;
	streampos lastPos;


	while (getline(a, buffer))
	{
		begin = 0;
		end = buffer.find(";", begin+1);
		id1 = stoll(buffer.substr(begin, end - begin));

		begin = end+1;
		end = buffer.find(";", begin);
		lat = stod(buffer.substr(begin, end - begin));

		begin = end+1;
		end = buffer.find(";", begin);
		lon = stod(buffer.substr(begin, end - begin));

		if (!graph.addVertex(id1, GPS(lat, lon)))
			cout << "Failed insert!\n";
		
	}

	while (getline(b, buffer))
	{
		begin = 0;
		end = buffer.find(";", begin+1);
		id1 = stoll(buffer.substr(begin, end - begin));

		begin = end+1;
		end = buffer.find(";", begin);
		name = buffer.substr(begin, end - begin);

		begin = end+1;
		end = buffer.find(";", begin);

		buffer = buffer.substr(begin, end - begin);
		
		if (buffer.back() == '\r')
			buffer.erase(buffer.end()-1);

		if (buffer == "True")
			bl = true;
		else if (buffer == "False")
			bl = false;
		else
		{
			cout << "Bool parser error!\n";
		}

		while (getline(c, buffer))
		{
			begin = 0;
			end = buffer.find(";", begin+1);

			id2 = stoll(buffer.substr(begin, end - begin));

			if (id2 != id1)
			{
				c.seekg(lastPos);
				break;
			}

			begin = end+1;
			end = buffer.find(";", begin+1);
			id3 = stoll(buffer.substr(begin, end - begin));

			begin = end+1;
			end = buffer.find(";", begin+1);
			id4 = stoll(buffer.substr(begin, end - begin));
			

			if (bl)
				if (!graph.addDoubleEdge(id3, id4))
					cout << "Failed edge!\n";
			else
				if (!graph.addEdge(id3, id4))
					cout << "Failed edge!\n";

			lastPos = c.tellg();
		}
	}


	return true;
}


Graph DeliveryNetwork::getGraph() const {
	return graph;
}