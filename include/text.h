#ifndef TEXT_H
#define TEXT_H
#include "object.h"
#include <string>
using namespace std;
class three_dimension_text : object {
private:
	string font;
};

class horizontal_text : three_dimension_text {
};

class vertical_text : three_dimension_text {
};
#endif //TEXT_H
