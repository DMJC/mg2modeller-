#ifndef RENDER_H
#define RENDER_H
#include "GL/gl.h"
enum render_frames { RENDER_ONE, RENDER_ALL };
enum render_mode { WIREFRAME, SOLID, SOLID_WIRE, SOLID_TRANS, SOLID_TRANS_WIRE };

class render {
private:
	int mode;
	int frames;
public:
	render();
	void set_render_mode(int);
	int get_render_mode(void);
	void set_render_frames(int);
	int get_render_frames(void);
	void run_render(void);
};


#endif //render_h
