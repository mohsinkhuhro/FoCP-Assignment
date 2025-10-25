#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string weather_condition();
int random_battery();
bool random_obstacle();
void start_day();
void displaySummary();             
string Dicide_Action(string, int, bool);
string get_random_Weather();
bool get_random_obstacle();
int get_random_battery();

int main() {
    srand(time(0));
    start_day();
    displaySummary();
    return 0;
}

void start_day() {
    int n;
    cout << "\t\tWELCOME\n";
    cout << "\tBattery percentage is = 100%\n";
    cout << "Enter Any Number to Start The Day\n";
    cin >> n;
}

string Dicide_Action(string weather, int battery, bool obstacle) {
    if (weather == "clear" && battery >= 40 && !obstacle) {
        return "Take off";
    } 
    else if (battery < 40) {
        return "Return to base to recharge";
        battery += 10; 
    } 
    else if (weather == "rainy" || weather == "windy") {
        return "Delayed";
    } 
    else if (obstacle) {
        return "Reroute";
        battery -= 5;
    }
    return "Unknown";
}

string weather_condition() {
    int w = rand() % 3;
    if (w == 0) return "clear";
    else if (w == 1) return "windy";
    else return "rainy";
}

int random_battery() {
    int battery = rand() % 100;
    return battery; 
}

bool random_obstacle() {
    int obstacle = rand() % 2;
    return obstacle; 
}


string get_random_Weather() { return weather_condition(); }
bool get_random_obstacle() { return random_obstacle(); }
int get_random_battery() { return random_battery(); }

void displaySummary() {
    for (char location = 'A'; location <= 'C'; location++) {
       
        string weather = get_random_Weather();
        bool obstacle = get_random_obstacle();
        int battery = get_random_battery();
        string action = Dicide_Action(weather, battery, obstacle);
          if (location =='A'){
      battery = 100;
       }
        cout << "For location " << location << endl;
        cout << "Weather is " << weather << endl;
        cout << "Battery = " << battery << "%" << endl;
        cout << "Obstacle: " << (obstacle ? "Yes" : "No") << endl;
        cout << "Drone Action: " << action << endl << endl;
    }
}

