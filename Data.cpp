#include "Data.h"

using namespace std;

Data::Data()
{}

Data::Data(unsigned int dia, unsigned int mes, unsigned int ano) : dia(dia), mes(mes), ano(ano)
{}


unsigned int Data::getDia() const {
	return this->dia;
}
unsigned int Data::getMes() const {
	return this->mes;
}

unsigned int Data::getAno() const {
	return this->ano;
}

std::string Data::getInfo() const {
	string info;

	info = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);

	return info; 
}

void Data::setDia(unsigned int dia) {
	this->dia = dia;
}

void Data::setMes(unsigned int mes) {
	this->mes = mes;
}

void Data::setAno(unsigned int ano) {
	this->ano = ano;
}


bool Data::operator==(const Data& data1) const {
	return (this->dia  == data1.getDia() && this->mes == data1.getMes() && this->ano == data1.getAno());
}

bool Data::operator<(const Data& data1) const {
	if (this->ano != data1.getAno())
		return (this->ano < data1.getAno());

	else if (this->mes != data1.getMes())
		return (this->mes < data1.getMes());

	else if (this->dia != data1.getDia())
		return (this->dia < data1.getDia());
}


std::ostream& operator<<(std::ostream& os, const Data& data1) {
	return (os << data1.getInfo());
}