#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function declaration
void startDay();
int getWeather();
bool checkObstacle();
bool checkMalfunction();
bool deliverToLocation(string location, int &battery, int &success, int &failed, int &delayed);
void showSummary(int success, int failed, int delayed, int battery);

int main(){
    srand(time(0)); //Make random numbers different each time

    int battery =100; //start with full battery
    int success =0;
    int failed =0;
    int delayed =0;

    startDay(); / Show welcome message

 // Deliver to Location A
    cout << "\nDelivering to Location A..\n";
    deliverToLocation("Location A",battery, success, failed, delayed);

 // Deliver to Location B
    cout << "\nDelivering to Location B..\n";
    deliverToLocation("Location B", battery, success, failed, delayed);

 // Deliver to Location C
    cout << "\nDelivering to Location C..\n";
    deliverToLocation("Location C", battery, success, failed, delayed);

 // Show final report
    showSummary(success, failed, delayed, battery);

    return 0;
}

// Show welcome message
void startDay() {
    int n;
    cout << "Welcome\n";
    cout << "Battery is 100%\n";
    cout << "Enter any number  to start delivery day..";
    cin >> n; // Wait for user to Enter 
}

// Random weather, 1 = sunny, 2 = windy, 3 = rainy
int RandomWeather() {
    return 1+ rand() % 3;
}

// Random obstacle, true or false
bool checkObstacle() {
    return rand() % 2 == 1; // number % 2 = 1 or 2 so it will be either true or false
}
bool checkMalfunction() {
    return rand() % 10 == 0;
}

// Try to deliver to one location
bool deliverToLocation(string location, int &battery, int &success, int &failed, int &delayed) {
    int weather = RandomWeather();
    bool obstacle = checkObstacle();
    int batteryDrain = 10 + rand() % 16 ; // Drain 10–25% battery

    // Show conditions
    cout << "Weather: ";
    if (weather == 1) {cout << "Sunny\n";}
    else if (weather == 2){ cout << "Windy\n";}
    else {cout << "Rainy\n";}
    
    cout << "Obstacle: " ;
    if (obstacle){
        cout << "yes\n";
    }
    else {cout<< "NO\n";}

    // Decision making
    if (weather == 3) {
        cout << "It's raining Delivery delayed \n";
        delayed++;
        return false;
    }
    if (weather == 2 && battery < 40){
        cout << "Too windy and battery is low  Recharging (+10%).\n";
        battery += 10;
        if (battery > 100){ battery = 100;} // in the case if battery is gone greater than 100
    }
    if (obstacle) {
        cout << "Obstacle is present rerouting..\n";
        batteryDrain += 5; // Extra battery used
    }
    if (checkMalfunction()) {
        cout << "Oops! System malfunction. Delivery failed.\n";
        failed++;
        battery -= batteryDrain;
        return false;
    }

   
    // Successful delivery
    battery -= batteryDrain;
    
    cout << "Delivered to " << location << " successfully!\n";
    cout << "Battery left: "<<battery<<"%\n";
    success++;
    return true;
}

// Final summary
void showSummary(int success, int failed, int delayed, int battery)
 {
    cout << "\nSummary\n";
    cout << "Total Deliveries: 3\n";
    cout << "Successful: " << success <<"\n";
    cout << "Failed: " << failed <<"\n";
    cout << "Delayed: " << delayed <<"\n";
    cout << "Battery Remaining: " << battery <<"%\n";


}