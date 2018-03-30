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

	string buffer1, buffer2, name;
	int begin, end = 0;
	long long id1, id2;
	double lat, lon;
	bool bl;


	while (getline(a, buffer1))
	{
		begin = 0;
		end = buffer1.find(";", begin+1);

		id1 = stoi(buffer1.substr(begin, end - begin));

		begin = end+1;
		end = buffer1.find(";", begin);

		lat = stod(buffer1.substr(begin, end - begin));

		begin = end+1;
		end = buffer1.find(";", begin);

		lon = stod(buffer1.substr(begin, end - begin));

		graph.addVertex(GPS(id, lat, lon));
	}

	while (getline(b, buffer1))
	{
		begin = 0;
		end = buffer1.find(";", begin+1);

		id1 = stoi(buffer1.substr(begin, end - begin));

		begin = end+1;
		end = buffer.find(";", begin);

		name = buffer.substr(begin, end - begin);

		begin = end+1;
		end = buffer.find(";", begin);

		if (buffer.substr(begin, end - begin) == "True")
			bl = true;
		else if (buffer.substr(begin, end - begin) == "False")
			bl = false;
		else
		{
			cout << "Bool parser error!\n";
		}

		while (getline(c, buffer2))
		{
			begin = 0;
			end = buffer.find(";", begin+1);

			id2 = stoi(buffer.substr(begin, end - begin));

			if (id2 != id1)
			{
				c.seekg(c.tellg()-buffer2.size());
				break;
			}

			

			

			if (bl)
				graph.addDoubleEdge(graph.findVertex(GPS(id, 0, 0)));
		}
	}

	while (getline(c, buffer))
	{
		buffer = "";
	}

	return true;
}