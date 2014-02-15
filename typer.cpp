#include<gtkmm.h>
#include<iostream>

int main(int argc, char* argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.squgeim.typer");
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
	Gtk::Window *mainwin=0;
	
	try {
		builder->add_from_file("glade.xml");
	}
	catch(const Glib::FileError& ex) {
		std::cerr<<"FileError: "<<ex.what()<<std::endl;
	}
	catch(const Glib::MarkupError& ex) {
		std::cerr<<"MarkupError: "<<ex.what()<<std::endl;
	}
	catch(const Gtk::BuilderError& ex) {
		std::cerr<<"BuilderError: "<<ex.what()<<std::endl;
	}
	
	builder->get_widget("main",mainwin);
	if(mainwin) {
		return app->run(*mainwin);
	}
	else return -1;
}
