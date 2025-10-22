#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

string weather_condition(){
    int w = rand() % 3;
    if(w==0) return "clear";
    else if(w==1) return "windy";
    else return "rainy";
}
int random_battery(){
    int battery = rand() % 100;
    return battery; 
}
bool random_obstacle(){
    int obstacle= rand() % 2;
    if (obstacle=0) return "no obstacle";
    else return "obstacle";
}

int main(){
    srand(time(0));



    return 0;
}