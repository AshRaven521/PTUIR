//
//  main.cpp
//  laba8_var4_ex2
//
//  Created by Пушнова Алиса Сергеевна on 12/18/18.
//  Copyright © 2018 Пушнова Алиса Сергеевна. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdlib>

using namespace std;

const char   Print_all_trips = '1';
const char   Add_new_trip = '2';
const char   Find_trip = '3';
const char   Quit_program = '4';

class Trip
{
public:
    string DepartureWeekDay;
    string DestinationPlace;
    string DepartureTime;
    string CountOfFreePlaces;
};

void pause_app()
{
    system("pause");
    getchar();
}

void PrintEntry(Trip entry)
{
    printf("\tДень недели:           %s\n", entry.DepartureWeekDay.c_str());
    printf("\tПункт назначения:      %s\n", entry.DestinationPlace.c_str());
    printf("\tВремя отправления:     %s\n", entry.DepartureTime.c_str());
    printf("\tЧисло свободных мест:  %s\n", entry.CountOfFreePlaces.c_str());
}

void PrintList(vector<Trip> info)
{
    system("cls");
    
    if (info.size() < 1)
    {
        cout << "Нет данных для вывода!\nНажмите любую клавишу для выхода в главное меню...\n";
        pause_app();
        return;
    }
    
    for (unsigned int i = 0; i < info.size(); i++)
    {
        printf("Рейс номер #%d\n", i + 1);
        PrintEntry(info[i]);
    }
    cout << string(63, '=').c_str() << "\n";
    pause_app();
}

void PrintMenuDialog()
{
    system("cls");
    int lineLength = 63;
    
    cout << "\t\n" << string(lineLength, '-').c_str();
    cout << "\t\n" << "|                    Что вы хотите сделать?                   |";
    cout << "\t\n" << string(lineLength, '-').c_str();
    cout << "\t\n" << "| " << Print_all_trips           << " | Выдать всю информацию о рейсах                          |";
    cout << "\t\n" << "| " << Add_new_trip              << " | Добавить информацию о рейсе                             |";
    cout << "\t\n" << "| " << Find_trip                 << " | Отфильтровать рейсы                                     |";
    cout << "\t\n" << "| " << Quit_program              << " | Выход из программы                                      |";
    cout << "\t\n" << string(lineLength, '-').c_str() << "\t\n\t\nВаш выбор: ";
    
}

Trip ReadNewTripFromConsole()
{
    system("cls");
    
    Trip* trainInfo = new Trip();
    
    cout << "День недели:              ";
    cin  >> trainInfo->DepartureWeekDay;
    
    cout << "Пункт назначения:         ";
    cin  >> trainInfo->DestinationPlace;
    
    cout << "Время отправления:        ";
    cin  >> trainInfo->DepartureTime;
    
    cout << "Число свободных мест:     ";
    cin  >> trainInfo->CountOfFreePlaces;
    
    return *trainInfo;
}

vector<Trip> GetFilteredTrips(vector<Trip> &trips)
{
    system("cls");
    
    char tmp[101];
    string number;
    string day;
    string time;
    
    printf("Сколько нужно зарезервировать мест: ");
    scanf("%100s", tmp, 101);
    number = tmp;
    
    printf("День недели: ");
    scanf("%100s", tmp, 101);
    day = tmp;
    
    printf("Время отправления поезда не позднее: ");
    scanf("%100s", tmp, 101);
    time = tmp;
    
    system("cls");
    
    vector<Trip> filteredTrips;
    for (auto trip : trips)
    {
        
        if ( ( std::stoi(trip.CountOfFreePlaces)  >= std::stoi(number) ) &&
            ( trip.DepartureWeekDay == day ) &&
            ( std::stof(trip.DepartureTime) <= std::stof(time) ) )
        {
            filteredTrips.push_back(trip);
        }
    }
    
    return filteredTrips;
}


int main()
{
    ifstream input("/Users/alisapushnova/Documents/ОАиП/Лаба 8/laba8_var4_ex2/input.txt");
    ofstream output("/Users/alisapushnova/Documents/ОАиП/Лаба 8/laba8_var4_ex2/output.txt");
    
    auto trips = vector<Trip>();
    
    while (!input.eof())
    {
        string date;
        string trainDestination;
        string departureTime;
        string freeNumber;
        string empty;
        
        getline(input, date);
        getline(input, trainDestination);
        getline(input, departureTime);
        getline(input, freeNumber);
        getline(input, empty);
        
        date.erase( std::remove(date.begin(), date.end(), '\r'), date.end() );
        trainDestination.erase( std::remove(trainDestination.begin(), trainDestination.end(), '\r'), trainDestination.end() );
        departureTime.erase( std::remove(departureTime.begin(), departureTime.end(), '\r'), departureTime.end() );
        freeNumber.erase( std::remove(freeNumber.begin(), freeNumber.end(), '\r'), freeNumber.end() );

        Trip entry = { date, trainDestination, departureTime, freeNumber };
        trips.push_back(entry);
    }
    
    bool quit = false;
    while (!quit)
    {
        PrintMenuDialog();
        switch ( getchar() )
        {
            case Print_all_trips:
                PrintList(trips);
                break;
                
            case Add_new_trip:
                trips.push_back(ReadNewTripFromConsole());
                break;
                
            case Find_trip:
                PrintList(GetFilteredTrips(trips));
                break;
                
            case Quit_program:
                quit = true;
                break;
        }
        system("cls");
    }
    
    for (unsigned int i = 0; i < trips.size(); i++)
    {
        output << trips[i].DepartureWeekDay << endl;
        output << trips[i].DestinationPlace << endl;
        output << trips[i].DepartureTime << endl;
        output << trips[i].CountOfFreePlaces << endl;
        if (i < trips.size() - 1) output << endl;
    }
    
    input.close();
    output.close();
    
    return 0;
}





