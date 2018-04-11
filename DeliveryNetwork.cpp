//
// Created by Beatriz Mendes on 29/03/2018.
//

#include "DeliveryNetwork.h"
#include <fstream>
#include <sstream>
#include <cfloat>
#include <limits>
#include <algorithm>

#include "utilities.h"
#include "ui_utilities.h"

using namespace std;

void DeliveryNetwork::placeOrder(int clientID, Data date){
	double max = 0;
	Supermarket * s;
	bool b= false;

	Client * c = clientExists(clientID);

	for(const auto &sup : supermarkets){
		if(sup.second->getGPS().distance(c->getGPS())>max){
			max = sup.second->getGPS().distance(c->getGPS())>max;
			s = sup.second;
		}
	}

	for(const auto &d: deliveries){
		if(d->getData()==date){
			d->addOrder(c,c->getBasket());
			b = true;
		}
	}

	if(!b){
		deliveries.push_back( new Delivery(s,  date));
		deliveries.at(deliveries.size()-1)->addOrder(c,c->getBasket());
	}

}

Client * DeliveryNetwork::clientExists(int id){
	Client * cl = NULL;
	for(auto & c : clients){
		if(c.second->getId() == id) return c.second;
	}
	return cl;
}

Item * DeliveryNetwork::itemExists(int id){
	Item * it = NULL;
	for(auto & i : items){
		if(i->getId() == id) return i;
	}
	return it;
}

void DeliveryNetwork::addDelivery(Delivery * d){
	deliveries.push_back(d);
};


bool DeliveryNetwork::loadGraph(string aname, string bname, string cname)
{

	ifstream a(aname), b(bname), c(cname);

	if (!a.is_open() || !b.is_open() || !c.is_open())
	{
		cout << "Error opening file!\n";
		return false;
	}


	string buffer;
	int begin, end = 0, i = 0;
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
		{
			cout << "Failed insert!\n";
			return false;
		}

	}

	while (getline(b, buffer))
	{
		begin = 0;
		end = buffer.find(";", begin+1);
		id1 = stoll(buffer.substr(begin, end - begin));

		begin = end+1;
		end = buffer.find(";", begin);
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
			return false;
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
			{
				if (!graph.addDoubleEdge(id3, id4, i))
				{
					cout << "Failed edge!\n";
					return false;
				}
			}
			else
			{
				if (!graph.addEdge(id3, id4, i))
				{
					cout << "Failed edge!\n";
					return false;
				}
			}

			lastPos = c.tellg();

			i++;
		}
	}

	a.close();
	b.close();
	c.close();

	return true;
}

bool DeliveryNetwork::loadViewer(string aname, string bname, string cname)
{

	gv = new GraphViewer(600, 600, false);

	gv->defineEdgeCurved(false);
	gv->defineVertexSize(1);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	ifstream inFile;

	inFile.open(aname);

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		return false;
	}

	string   line;

	long long id = 0;
	double X = 0;
	double Y = 0;

	double Xadd;
	double Yadd;
	long long i = 0;

	string dummy;
	dummy.push_back(1); // The given program does not accept space nor empty string for albel so I had to be creative...

	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string         data;

		linestream >> id;

		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> X;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> Y;

		if (i == 0) 		//Sets the first point as the origin of the map
		{					//
			Xadd = -X;		//
			Yadd = -Y;		//
		}					//
		//
		X += Xadd;			//
		Y += Yadd;			//

		X = X*1350000;		//Since the give program only accepts integer coordinates some shady techniques are applied.
		Y = Y*1000000;		//X is multiplied more than Y because the proportions were a bit off.

		swap(X, Y);			//Rotates 90ª counter-clockwise
		Y *= -1;

		// cout << X << ", " << Y << "\n";

		gv->addNode(id, X, Y);

		gv->setVertexLabel(id, dummy);

		i++;
	}

	inFile.close();


	//Ler o ficheiro arestas.txt
	inFile.open(cname);

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	ifstream b(bname);

	streampos lastPos;
	int begin, end;
	bool bl;
	long long idAresta = 0, idNoOrigem = 0, idNoDestino = 0, id1, id2;
	string buffer;
	i = 0;



	while (getline(b, buffer))
	{
		begin = 0;
		end = buffer.find(";", begin+1);
		id1 = stoll(buffer.substr(begin, end - begin));

		begin = end+1;
		end = buffer.find(";", begin);
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
			return false;
		}

		while(getline(inFile, line))
		{
			begin = 0;
			end = line.find(";", begin+1);

			id2 = stoll(line.substr(begin, end - begin));

			if (id2 != id1)
			{
				inFile.seekg(lastPos);
				break;
			}

			stringstream linestream(line);
			string data;

			linestream >> idAresta;

			getline(linestream, data, ';');  // read up-to the first ; (discard ;).
			linestream >> idNoOrigem;
			getline(linestream, data, ';');  // read up-to the first ; (discard ;).
			linestream >> idNoDestino;

			if (bl)
			{
				gv->addEdge(i, idNoOrigem, idNoDestino, EdgeType::UNDIRECTED);
			}
			else
			{
				gv->addEdge(i, idNoOrigem, idNoDestino, EdgeType::DIRECTED);
			}

			lastPos = inFile.tellg();

			i++;
		}
	}

	inFile.close();

	gv->rearrange();
}

bool DeliveryNetwork::loadClients(std::string filename)
{
	ifstream input(filename);

	if (!input.is_open())
	{
		cout << "Error opening file!\n";
		return false;
	}

	int id;
	double lat, lon;
	vector<Item * > items;
	int itemid,amount;
	string buffer;

	try
	{
		while (getline(input, buffer)) // id;lat;lon;item1;amount1;item2;amount2;...
		{
			stringstream ss(buffer);

			ss >> id;
			getline(ss, buffer, ';');
			ss >> lat;
			getline(ss, buffer, ';');
			ss >> lon;

			Client * c = new Client(id, lat, lon, items);

			while (1)
			{
				if (!getline(ss, buffer, ';'))
				break;
				ss >> itemid;

				if (!getline(ss, buffer, ';'))
				break;
				ss >> amount;

				c->addItem(new Item(itemid, amount));
			}

			clients.insert(make_pair(id, c));
			clients[id]->setRef(graph);
		}
	}
	catch (exception &e)
	{
		return false;
	}


	input.close();

	return true;
}

bool DeliveryNetwork::loadSupermarkets(std::string filename)
{
	ifstream input(filename);

	if (!input.is_open())
	{
		cout << "Error opening file!\n";
		return false;
	}

	int id;
	double lat, lon;
	string buffer;

	try
	{
		while (getline(input, buffer)) // id;lat;lon;item1;amount1;item2;amount2;...
		{
			stringstream ss(buffer);

			ss >> id;
			getline(ss, buffer, ';');
			ss >> lat;
			getline(ss, buffer, ';');
			ss >> lon;

			supermarkets.insert(make_pair(id, new Supermarket(id, lat, lon)));
			supermarkets[id]->setRef(graph);
		}
	}
	catch (exception &e)
	{
		return false;
	}


	input.close();

	return true;
}




void DeliveryNetwork::showPath(const long long &startid, const long long &endid)
{
	gv->setVertexSize(startid, 200);
	gv->setVertexColor(startid, GREEN);
	gv->setVertexLabel(startid, "Start");

	gv->setVertexSize(endid, 200);
	gv->setVertexColor(endid, BLUE);
	gv->setVertexLabel(endid, "Finish");

	graph.dijkstraShortestPath(startid);

	vector<Vertex*> temp = graph.getPath(startid, endid);

	for (int i = 0; i < temp.size() - 1; ++i)
	{
		for (int j = 0; j < temp[i]->getAdj().size(); ++j)
		{
			if (graph.findVertex(temp[i]->getAdj()[j].getId()) == temp[i+1])
			{
				gv->setEdgeThickness(temp[i]->getAdj()[j].getEdgeId(), 40);
				gv->setEdgeColor(temp[i]->getAdj()[j].getEdgeId(), RED);

			}
		}
	}

	gv->rearrange();
}

void DeliveryNetwork::showPath(vector<long long> v)
{


	if (v.size() < 2)
	return;

	long long startid = v[0], endid = v[0];

	double smaller = DBL_MAX;

	long long firstid = v[0];
	int i = 0;

	while (v.size() != 0)
	{
		startid = endid;

		if (i == 0)
		{
			gv->setVertexSize(startid, 300);
			gv->setVertexColor(startid, GREEN);
			gv->setVertexIcon(startid,"res/cartIcon.png");
			gv->setVertexLabel(startid, "Start");
		}
		else
		{
			gv->setVertexSize(startid, 200);
				gv->setVertexColor(startid, RED);
			gv->setVertexIcon(startid,"res/homeIcon.png");
		}



		if (v.size() == 1)
		{
			endid = firstid;

			graph.dijkstraShortestPath(startid);

		}
		else
		{
			graph.dijkstraShortestPath(startid);

			smaller = DBL_MAX;

			for (int j = 0; j < v.size(); ++j) // Find shortest point to startid
			{
				if (v[j] != startid)
				{
					if (graph.findVertex(v[j])->getDist() < smaller)
					{
						smaller = graph.findVertex(v[j])->getDist();
						endid = v[j];
					}
				}
			}
		}

		vector<Vertex*> temp = graph.getPath(startid, endid);

		for (int j = 0; j < temp.size() - 1; ++j)
		{
			for (int k = 0; k < temp[j]->getAdj().size(); ++k)
			{
				if (graph.findVertex(temp[j]->getAdj()[k].getId()) == temp[j+1])
				{
					gv->setEdgeThickness(temp[j]->getAdj()[k].getEdgeId(), 40);
					gv->setEdgeColor(temp[j]->getAdj()[k].getEdgeId(), RED);

				}
			}
		}

		v.erase(remove(v.begin(), v.end(), startid), v.end());

		i++;

	}

	gv->rearrange();
}

void DeliveryNetwork::printClients() const
{
	for (auto i : clients)
	{
		cout << *(i.second) << "\n";
	}
}

void DeliveryNetwork::printSupermarkets() const
{
	for (auto i : supermarkets)
	{
		cout << *(i.second) << "\n";
	}
}

Graph DeliveryNetwork::getGraph() const
{
	return graph;
}

GraphViewer* DeliveryNetwork::getGV() const
{
	return gv;
}

std::map<int, Client*> DeliveryNetwork::getClients() const
{
	return clients;
}

std::map<int, Supermarket*> DeliveryNetwork::getSupermarkets() const
{
	return supermarkets;
}

void DeliveryNetwork::deleteGV()
{
	delete gv;
}

bool DeliveryNetwork::loadItems(string filename){
	{
		ifstream input(filename);

		if (!input.is_open())
		{
			cout << "Error opening file!\n";
			return false;
		}

		string id;

		try
		{
			while (getline(input, id)) // id;lat;lon;item1;amount1;item2;amount2;...
			{
				items.push_back(new Item(stoi(id),1));
			}
		}
		catch (exception &e)
		{
			return false;
		}


		input.close();

		return true;
	}
}


void DeliveryNetwork::printItems(){
	for(int i = 0; i < items.size();i++){
		cout << "item " << i+1 << ": ";
		cout << items.at(i)->getId();
		cout << "\n";
	}
}

void DeliveryNetwork::loadDeliveries(){
	for(const auto &c : clients){
		placeOrder(c.second->getId(), Data(2,2,2018));
	}
}

void DeliveryNetwork::showDeliveries(){
	for(int i = 0; i< deliveries.size();i++){
		cout << "\n Delivery " << i+1 << " | " << deliveries.at(i)->getData() << endl;

		for(const auto c : deliveries.at(i)->getOrders()){
			cout << "Client ID: " << c->getId() << " | Items ID's: ";
			for(int j = 0; j < c->getBasket().size(); j++){
				cout << c->getBasket().at(j)->getId();
				if(j!= c->getBasket().size()-1) cout << "-";
			}
			cout<< "\n";
		}
	}
}

void DeliveryNetwork::popDelivery(){
	int i = -1;
	Data data;

	for(auto it : deliveries){
		if(it->getData()<data)
		i++;
	}
	if(deliveries.size()!=0)
	deliveries.erase(deliveries.begin()+i);
}

vector<long long> DeliveryNetwork::makeDelivery(){
	string tempstr;

	std::vector<long long> ids;
	if(deliveries.size() == 0)
	{	 cout << "No schedule deliveries.";
return ids;}

	Delivery * d = deliveries.at(deliveries.size()-1);


	ids.push_back(d->getSupermarket()->getRef().first);

	for(const auto c: d->getOrders()){
		if(c!=NULL)
		ids.push_back(c->getRef().first);

	}
	cout << "Delivery done!\n";
	popDelivery();
	return ids;
}
