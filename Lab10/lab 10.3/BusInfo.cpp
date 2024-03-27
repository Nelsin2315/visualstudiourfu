#pragma once
#include <string>
using namespace std;
class BusInfo
{
public:
	int id;
	bool is_in_depot;

	// Конструктор класса, принимающий имя водителя и маршрут автобуса
	BusInfo(string driver_name, string route) {
		id = -1;
		is_in_depot = true;
		this->driver_name = driver_name;
		this->route = route;
	}
	// Метод для получения имени водителя
	string get_driver() {
		return driver_name;
	}
	// Метод для получения маршрута автобуса
	string get_route() {
		return route;
	}
	// Метод для преобразования объекта BusInfo в строку
	string to_string() {
		// Формирование строки с информацией об автобусе
		return "Id: " + std::to_string(id) + "\tName: " + driver_name + "\tRoute : " + route + "\tIn depot: " + (is_in_depot ? "true" : "false") + "\n";
	}
private:
	string driver_name;
	string route;
};