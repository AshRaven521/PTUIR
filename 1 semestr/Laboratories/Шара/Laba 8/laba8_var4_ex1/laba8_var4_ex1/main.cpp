//
//  main.cpp
//  ex1
//
//  Created by Пушнова Алиса Сергеевна on 12/15/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char PRINT_ALL_INFORMATION_ABOUT_TRIPS = '1';
const char SHOW_TRIPS_BEFORE_SOME_TIME = '2';
const char ADD_NEW_TRIP = '3';
const char EXIT_FROM_APPLICATION = '4';

class Trip
{
public:
    string number;
    string bus_type;
    string destination;
    int departure_time;
    int arrival_time;
};

void pause_app()
{
    system("pause");
    getchar();
}

Trip get_trip_from_console(Trip* trip = new Trip())
{
    system("cls");
    
    cout << "Введите информацию о новом рейсе:\n\n";
    
    cout << "Номер рейса:       ";
    cin  >> trip->number;
    
    cout << "Тип автобуса:      ";
    cin  >> trip->bus_type;
    
    cout << "Пункт назначения:  ";
    cin  >> trip->destination;
    
    cout << "Время отправления: ";
    cin  >> trip->departure_time;
    
    cout << "Время прибытия:    ";
    cin  >> trip->arrival_time;
    
    return *trip;
}

void print_trip(Trip &entry)
{
    cout << "\t" << "Номер рейса:       " << entry.number << "\n";
    cout << "\t" << "Тип автобуса:      " << entry.bus_type << "\n";
    cout << "\t" << "Пункт назначения:  " << entry.destination << "\n";
    cout << "\t" << "Время отправления: " << entry.departure_time << "\n";
    cout << "\t" << "Время прибытия:    " << entry.arrival_time << "\n\n";
}

void print_trips(vector<Trip> trips)
{
    system("cls");
    
    if (trips.size() < 1)
    {
        cout << "Нет данных для вывода!\nНажмите любую клавишу для выхода в главное меню...\n";
        pause_app();
        return;
    }
    
    cout << "Список рейсов (всего " << trips.size() << "): \n\n";
    
    for (int i = 0; i < trips.size(); i++)
    {
        print_trip(trips[i]);
    }
    cout << string(63, '=').c_str() << "\n";
    
    pause_app();
}

void Menu_Dialog()
{
    system("cls");
    int lineLength = 63;
    
    cout << "\t\n" << string(lineLength, '-').c_str();
    cout << "\t\n" << "|                    Что вы хотите сделать?                   |";
    cout << "\t\n" << string(lineLength, '-').c_str();
    cout << "\t\n" << "| " << PRINT_ALL_INFORMATION_ABOUT_TRIPS << " | Выдать всю информацию о рейсах                          |";
    cout << "\t\n" << "| " << SHOW_TRIPS_BEFORE_SOME_TIME       << " | Выдать рейсы, которые придут до указанного времени      |";
    cout << "\t\n" << "| " << ADD_NEW_TRIP                      << " | Добавить информацию о рейсах                            |";
    cout << "\t\n" << "| " << EXIT_FROM_APPLICATION             << " | Выход из программы                                      |";
    cout << "\t\n" << string(lineLength, '-').c_str() << "\t\n\t\nВаш выбор: ";
}


vector<Trip> sort_trips_by_arrival_time(vector<Trip> trips)
{
    for (int i = 0; i < trips.size(); i++)
    {
        for (int j = 0; j < trips.size() - i - 1; j++)
        {
            if (trips[j].arrival_time < trips[j + 1].arrival_time)
            {
                swap(trips[j], trips[j + 1]);
            }
        }
    }
    return trips;
}

vector<Trip> find_trips_arrived_before_time(int deadline, vector<Trip> trips)
{
    trips = sort_trips_by_arrival_time(trips);
    
    for (int i = 0; i < trips.size(); i++)
    {
        if (deadline >= trips[i].arrival_time)
        {
            trips.erase(trips.begin() + (--i + 1));
        }
    }
    return trips;
}

int main()
{
    auto trips = vector<Trip>();
    
    while (true)
    {
        Menu_Dialog();
        
        switch (getchar())
        {
            case PRINT_ALL_INFORMATION_ABOUT_TRIPS:
                print_trips(trips);
                break;
                
            case SHOW_TRIPS_BEFORE_SOME_TIME:
            {
                cout << "Введите максимально допустимое время прибытия: ";
                int deadline = 0;
                scanf("%d", &deadline);
                
                print_trips(find_trips_arrived_before_time(deadline, trips));
                break;
            }
                
            case ADD_NEW_TRIP:
                trips.push_back(get_trip_from_console());
                break;
                
            case EXIT_FROM_APPLICATION:
                return 0;
        }
        system("cls");
    }
    return 0;
}
