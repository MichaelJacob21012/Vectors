#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <cmath>

// TODO: your code  goes here

class Item {
private:
	float latitude;
	float longitude;
	string ID;
	int availableTime;

public:
	Item (float lat, float lon, string id, int time)
	: latitude(lat), longitude(lon), ID(id), availableTime(time){
	}
	float getLatitude () {
		return latitude;
	}
	float getLongitude () {
		return longitude;
	}
	string getID () {
		return ID;
	}
	int getAvailableTime () {
		return availableTime;
	}
	float distanceTo (Item destination) {
		float latRadsStart = latitude * (M_PI/180);
		float latRadsDestination = destination.getLatitude() * (M_PI/180);
		float lonRadsStart = longitude * (M_PI/180);
		float lonRadsDestination = destination.getLongitude() * (M_PI/180);
		float dlon = lonRadsDestination - lonRadsStart;
		float dlat = latRadsDestination - latRadsStart;
		float a = pow((sin(dlat/2)),2) + cos(latRadsStart)*cos(latRadsStart)*pow((sin(dlon/2)), 2);
		float c = 2*atan2(sqrt(a),sqrt(1-a));
		return c*6373000;
	}
};
ostream & operator<<(ostream & o, Item item){
		o << "{"
		  << item.getLatitude()
		  << ", "
		  << item.getLongitude()
		  << ", \""
		  << item.getID()
		  << "\", "
		  << item.getAvailableTime()
		  << "}";
		return o;
	}




// don't write any code below this line

#endif

