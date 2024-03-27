#include "BusMenu.h"
using namespace std;


BusPark* g_bus_park;
BusInfo* selected_bus = nullptr;

// Управление текстовыми сообщениями 
#pragma region 
	#pragma region Ìåíþ_âûõîäà
		#define EXIT_COMMAND "exit"
		#define PRINT_EXIT_MENU printf("\n\tPlease write \"%s\" to return to previous menu\n", EXIT_COMMAND)
	#pragma endregion
	#pragma region Ãëàâíîå_ìåíþ
		#define MENU_STRING "Please enter one of this commands:\n\t\"%s\" - add a new bus to depot\n\t\"%s\" - select a bus from depot or route\n\t\"%s\" - do something with selected bus\n\t\"%s\" - print list of buses\n\t\"%s\" - close program\n"
		#define NEW_COMMAND "new"
		#define SELECT_COMMAND "select"
		#define ACTION_COMMAND "action"
		#define PRINT_COMMAND "print"
		#define PRINT_MAIN_MENU printf(MENU_STRING, NEW_COMMAND, SELECT_COMMAND, ACTION_COMMAND, PRINT_COMMAND, EXIT_COMMAND)
		#define PRINT_SELECTED_BUS printf("\nSelected bus is:%s", selected_bus->to_string().c_str())
	#pragma endregion
	#pragma region Ìåíþ_ââîäà èíôîðìàöèè îá àâòîáóñå
		#define ADD_NEW_BUS_MENU "You can add new bus here\nOr you can return to previous menu by %s"
		#define NEW_DRIVER_NAME "\n\tPlease write a driver's name:\t"
		#define NEW_BUS_ROUTE "\tPlease write a bus route:\t"
	#pragma endregion
	#pragma region Ìåíþ_âûáîðà àâòîáóñà
		#define SELECT_BUS_MENU "You can selected one of previously created bus here\nOr you can return to previous menu by %s"
		#define PRINT_SELECT_MENU printf(SELECT_BUS_MENU, EXIT_COMMAND)
		#define ID_BUS_TO_SELECT "\n\tPlease write bus id to select:\t"
	#pragma endregion
	#pragma region Ìåíþ_ïå÷àòè ñïèñêà àâòîáóñîâ
		#define DEPOT_COMMAND "depot"
		#define ROUTE_COMMAND "route"
		#define ALL_COMMAND "all"
		#define PRINT_MENU_STRING "Please enter one of this commands:\n\t\"%s\" - print all busses in depot\n\t\"%s\" - print all busses on routes\n\t\"%s\" - print all busses\n\t\"%s\" - back to main menu\n"
		#define PRINT_PRINT_MENU printf(PRINT_MENU_STRING, DEPOT_COMMAND, ROUTE_COMMAND, ALL_COMMAND, EXIT_COMMAND)
	#pragma endregion
	#pragma region Ìåíþ_äåéñòâèé ñ âûáðàííûì àâòîáóñîì
		#define ACTION_COMMAND "action"
		#define REMOVE_COMMAND "remove"
		#define NO_SELECTED_BUS "There's no selected bus, please write something to exit\n"
		#define ACTION_MENU_STRING "Please enter one of this commands:\n\t\"%s\" - remove selected bus from all lists\n\t\"%s\" - %s\n\t\"%s\" - back to main menu\n"
		#define IN_DEPOT_COMMAND "Move bus from route to depot"
		#define ON_ROUTE_COMMAND "Move bus from depot to route"
	#pragma endregion
#pragma endregion


// Определение указателя на функцию и прототипы функций для вывода меню
typedef void (*f_ptr)();
void print_main_menu();
void print_exit_menu();
void print_print_menu();
void print_action_menu();
void print_new_bus_name();
void print_new_bus_route();
void print_select_id_menu();

//Определение функции для запроса ввода с консоли
string ask_to_write(f_ptr printFunction, bool* exit_marker);
void listen_main_menu();
void add_new_bus();
void select_bus();
void print_bus();
void action_with_bus();


BusMenu::BusMenu()
{
	this->bus_park = new BusPark();
	g_bus_park = this->bus_park;
}

void BusMenu::start_listen()
{
	listen_main_menu();
	cout << "Exiting..";
}

void listen_main_menu()
{
bool exit_marker = false;
while (!exit_marker)
{
	string input_text = ask_to_write(print_main_menu, &exit_marker);
	if (exit_marker)
	{
		break;
	}
	else
	{
		if (input_text == NEW_COMMAND)
		{
			add_new_bus();
		}
		if (input_text == SELECT_COMMAND)
		{
			select_bus();
		}
		if (input_text == PRINT_COMMAND)
		{
			print_bus();
		}
		if (input_text == ACTION_COMMAND)
		{
			action_with_bus();
		}
	}
}
}

void add_new_bus()
{
	bool exit_marker = false;
	printf(ADD_NEW_BUS_MENU, EXIT_COMMAND);
	string drivers_name = ask_to_write(print_new_bus_name, &exit_marker);
	if (exit_marker)
	{
		return;
	}
	string bus_route = ask_to_write(print_new_bus_route, &exit_marker);
	if (exit_marker)
	{
		return;
	}
	g_bus_park->add_bus(new BusInfo(drivers_name, bus_route));
	printf("Bus successfully added");
	ask_to_write(print_exit_menu, &exit_marker);
}

void select_bus()
{
	bool exit_marker = false;
	PRINT_SELECT_MENU;
	string str_id = ask_to_write(print_select_id_menu, &exit_marker);
	if (exit_marker)
	{
		return;
	}
	else
	{
		int id = -1;
		try
		{
			id = stoi(str_id);
			selected_bus = g_bus_park->select_bus(id);
			printf(selected_bus == nullptr ? "Bus with this id does not exist" : "Bus is selected");
			ask_to_write(print_exit_menu, &exit_marker);
		}
		catch (const std::exception&)
		{
			system("cls");
			printf("Please enter a number");
			select_bus();
		}
	}
}

void print_bus()
{
	bool exit_marker = false;
	bool print_in_depot = true;
	string input_str = ask_to_write(print_print_menu, &exit_marker);
	if (exit_marker)
	{
		return;
	}
	if (input_str == DEPOT_COMMAND)
	{
		g_bus_park->print(&print_in_depot);
	}
	else if (input_str == ROUTE_COMMAND)
	{
		print_in_depot = false;
		g_bus_park->print(&print_in_depot);
	}
	else if (input_str == ALL_COMMAND)
	{
		g_bus_park->print(nullptr);
	}
	ask_to_write(print_exit_menu, &exit_marker);
}

void action_with_bus()
{
	bool exit_marker = selected_bus == nullptr;
	string input_str = ask_to_write(print_action_menu, &exit_marker);
	if (exit_marker)
	{
		return;
	}
	try
	{
		if (input_str == REMOVE_COMMAND)
		{
			g_bus_park->remove_bus(selected_bus);
			delete selected_bus;
			selected_bus = nullptr;
		}
		else if ((input_str == ROUTE_COMMAND) && (selected_bus->is_in_depot))
		{
			g_bus_park->remove_bus(selected_bus);
			g_bus_park->add_bus(selected_bus, false);
		}
		else if((input_str == DEPOT_COMMAND) && (!selected_bus->is_in_depot))
		{
			g_bus_park->remove_bus(selected_bus);
			g_bus_park->add_bus(selected_bus, true);
		}
	}
	catch (const std::exception& e)
	{
		printf("\n%s\n", e.what());
	}
	ask_to_write(print_exit_menu, &exit_marker);
}

string ask_to_write(f_ptr printFunction, bool* exit_marker)
{
	string value = "";
	printFunction();
	cin >> value;
	*exit_marker |= (value == "exit");
	if (!(*exit_marker) && (value == ""))
	{
		return ask_to_write(printFunction, exit_marker);
	}
	return value;
}

#pragma region Print Functions 
void print_main_menu()
{
	system("cls");
	PRINT_MAIN_MENU;
	if (selected_bus != nullptr)
	{
		PRINT_SELECTED_BUS;
	}
}
void print_exit_menu()
{
	PRINT_EXIT_MENU;
}
void print_print_menu()
{
	system("cls");
	PRINT_PRINT_MENU;
}
void print_action_menu() 
{
	if (selected_bus == nullptr)
	{
		printf(NO_SELECTED_BUS);
	}
	else if (selected_bus->is_in_depot)
	{
		printf(ACTION_MENU_STRING, REMOVE_COMMAND, ROUTE_COMMAND, ON_ROUTE_COMMAND, EXIT_COMMAND);
	}
	else
	{
		printf(ACTION_MENU_STRING, REMOVE_COMMAND, DEPOT_COMMAND, IN_DEPOT_COMMAND, EXIT_COMMAND);
	}
}
void print_new_bus_name()
{
	printf(NEW_DRIVER_NAME);
}
void print_new_bus_route()
{
	printf(NEW_BUS_ROUTE);
}
void print_select_id_menu()
{
	printf(ID_BUS_TO_SELECT);
}
#pragma endregion