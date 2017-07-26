#include "../include/view.h"

void view::onRealize() {
	mGlArea.make_current();
	glewExperimental=true; //GLArea only support Core profile.
	if(glewInit() != GLEW_OK) {
		std::cout << "ERROR: Failed to initialize GLEW. (Maybe the OpenGL context not exist)" << std::endl;
	}
	//This point you have the context and you can use opengl methods. 	
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

void view::onUnrealize() {
	//your cleanUp. Deleting Vao etc.
}

bool view::onRender(const Glib::RefPtr<Gdk::GLContext>& context, int view_type, int draw_type) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cout << "rendering test" << endl;
	switch (draw_type){
	case SOLID_VIEW:
		cout << "Drawing Solid View" << endl;
	break;
	case TRANSPARENT_SOLID_VIEW:
		cout << "Drawing Transparent Solid View" << endl;
	break;
	case TRANSPARENT_WIREFRAME_VIEW:
		cout << "Drawing Transparent Wireframe View" << endl;
	break;
	default:
		cout << "Drawing Wireframe View" << endl;
	break;
	}

	switch(view_type){
	case TOP_VIEW:
		cout << "Drawing Top View" << endl;
		glClearColor(0.5f, 0.5f, 0.5f, 0.5f);		
	break;
	case BOTTOM_VIEW:
		cout << "Drawing Bottom View" << endl;
		glClearColor(0.5f, 0.5f, 0.5f, 0.5f);		
	break;
	case LEFT_VIEW:
		cout << "Drawing Left View" << endl;
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	break;
	case RIGHT_VIEW:
		cout << "Drawing Right View" << endl;
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	break;
	case FRONT_VIEW:
		cout << "Drawing Front View" << endl;
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	break;
	case BACK_VIEW:
		cout << "Drawing Back View" << endl;
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	break;
	case PERSPECTIVE_VIEW:
		cout << "Drawing Perspective View" << endl;
		glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	break;
	case CAMERA_VIEW:
		cout << "Drawing Camera View" << endl;
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	break;
		cout << "Broken View" << endl;
	default:
		cout << "Drawing Perspective View" << endl;
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	break;
	}
	//here comes your rendering code
	return 0;
}

view::view(int view_type, int draw_type, scene){
	add(mGlArea);
	mGlArea.set_auto_render();
	mGlArea.set_hexpand();
	mGlArea.set_vexpand();
	mGlArea.set_halign(Gtk::ALIGN_FILL);
	mGlArea.set_valign(Gtk::ALIGN_FILL);
	mGlArea.set_required_version(3, 3); //your desired gl version
	mGlArea.signal_realize().connect(sigc::mem_fun(this, &view::onRealize));
	mGlArea.signal_unrealize().connect(sigc::mem_fun(this, &view::onUnrealize), false);
	mGlArea.signal_render().connect(sigc::bind<int, int>(sigc::mem_fun(this, &view::onRender), view_type, draw_type));
}
