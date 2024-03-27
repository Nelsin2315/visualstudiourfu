#include "BusPark.h"

// Определение класса и конструкторов
BusPark::BusPark()
{
	bus_depot = new LinkedList<BusInfo>();
	bus_route = new LinkedList<BusInfo>();
}

void BusPark::add_bus(BusInfo* bus, bool from_in)
{
	LinkedList<BusInfo>* list = from_in ? this->bus_depot : this->bus_route;
	int id = -1;
	if (bus->id == -1)
	{
		id = list->add(bus);
	}
	else
	{
		id = list->insert(bus->id, bus) ? bus->id : -1;
	}
	if (id == -1)
	{
		throw new std::exception("BusPark add_bus error");
	}
	else
	{
		bus->id = id;
	}
	bus->is_in_depot = from_in;
}

void BusPark::remove_bus(BusInfo* bus)
{
	if (!bus_depot->remove(bus->id) && !bus_route->remove(bus->id))
	{
		throw new std::exception("BusPark remove_bus error");
	}
}

BusInfo* BusPark::select_bus(int id)
{
	BusInfo* res = bus_depot->find(id);
	return res == nullptr ? bus_route->find(id) : res;
}

void BusPark::print(bool* list_marker)
{
	if (list_marker == nullptr)
	{
		print_list(bus_depot);
		print_list(bus_route);
	}
	else if((*list_marker))
	{
		print_list(bus_depot);
	}
	else
	{
		print_list(bus_route);
	}
}

void BusPark::print_list(LinkedList<BusInfo>* list)
{
	BusInfo* bus = list->find_first();
	while (bus != nullptr)
	{
		printf("%s\n", bus->to_string().c_str());
		bus = list->find_next(bus->id);
	}
}