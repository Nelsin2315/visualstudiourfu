#pragma once
#include "BusPark.h"
#include <iostream>

class BusMenu
{
public:
	BusMenu();
	void start_listen();
private:
	//автобусный парк
	BusPark* bus_park;
};