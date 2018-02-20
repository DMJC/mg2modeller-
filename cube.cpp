#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
main(){

//	#define PI 3.14159265
//	#define PI 3.141592653589793
//#define M_PI 3.14159265358979323846


	int vert_subdiv = 3;
	int radius = 1;
	float height = 2;
	float vertical_step = 0;
	vertical_step = height / (vert_subdiv -1);
	int horiz_subdiv = 4;
	float degree = 360 / horiz_subdiv;
	float deg_count = 0;
	float X = 0.0;
	float Y = 0.0;
	float Z = 0.0;

	while (vert_subdiv != 0){
		cout << vert_subdiv << endl;
		horiz_subdiv = 4;
		deg_count = 0;
		while (horiz_subdiv != 0){
			float Xin = 0;
			Xin = deg_count * (M_PI/180);
			float Yin = 0;
			Yin = deg_count * (M_PI/180);
			X = cosf(Xin);
			Y = sinf(Yin);
			X = fabs(X);
			Y = fabs(Y);
			float diff = fmod(X, 1.0f);
			if(abs(diff < 0.001f))
			X -= diff;
			float diff2 = fmod(Y, 1.0f);
			if(abs(diff2 < 0.001f))
			Y -= diff2;
			cout << "var" << horiz_subdiv << " degree " << deg_count /*<< setprecision(0)*/ << " X: " << X << " Y: " 				<< Y << " Z: " << Z << endl;
			deg_count = deg_count + degree;
			horiz_subdiv--;
		}
	Z = Z + vertical_step;
	vert_subdiv--;
	}
return 0;
}
