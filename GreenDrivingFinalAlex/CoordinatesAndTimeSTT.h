#pragma once

enum STT { circle = 0, rectangle = 1, triangle = 2 };

typedef struct Coordinates {

	double Latitude = 0;
	double Longitude = 0;
}Coordinates;

typedef struct Optimal {

	Coordinates start;
	Coordinates end;
	short int nr_of_points = 0;
	double avg_speed = 0.0;
}Optimal;
