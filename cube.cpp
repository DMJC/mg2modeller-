#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*
//Sphere
                float const y = sin( -M_PI_2 + M_PI * radius * R );
                float const x = cos(2*M_PI * sectors * S) * sin( M_PI * rings * R );
                float const z = sin(2*M_PI * sectors * S) * sin( M_PI * rings * R );
*/

main(){

	//	#define PI 3.14159265
	//	#define PI 3.141592653589793
	//	#define M_PI 3.14159265358979323846

	int vert_subdiv = 2;
	vert_subdiv = vert_subdiv + 1;
	float radius = 1;
	float top_radius = 4;
	float bottom_radius = 1;
	float radius_step = 0;
	radius_step = (top_radius - bottom_radius) / (vert_subdiv -1);
	float height = 2;
	float vertical_step = 0;
	vertical_step = height / (vert_subdiv -1);
	int horiz_rotate = 4;
	int tmp_horiz_rotate = 0;
	float degree = 360 / horiz_rotate;
	float deg_count = 0;
	float X = 0.0;
	float Y = 0.0;
	float Z = 0.0;
	radius = bottom_radius;
	while (vert_subdiv != 0){
		cout << vert_subdiv << endl;
		tmp_horiz_rotate = horiz_rotate;
		deg_count = 0;
		while (tmp_horiz_rotate != 0){
			float Xin = 0;
			Xin = (deg_count * (M_PI/180));
			float Yin = 0;
			Yin = (deg_count * (M_PI/180));
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
			if (deg_count > 180){
				Y = -Y;
			}
			if (deg_count > 90 && deg_count < 270){
				X = -X;
			}
			if(radius == 0){
				X = 0; Y = 0;
			}else{
				X = X * radius;
				Y = Y * radius;
			}
			cout << "vertex" << tmp_horiz_rotate << " Radius: " << radius << " degree " << deg_count << " X: " << X << " Y: " 				<< Y << " Z: " << Z << endl;
			deg_count = deg_count + degree;
			tmp_horiz_rotate--;
		}
	radius = radius + radius_step;
	Z = Z + vertical_step;
	vert_subdiv--;
	}
return 0;
}
