#include <gtkmm.h>
#include <iostream>
#include <string>

Glib::RefPtr<Gtk::Application> app;
Glib::RefPtr<Gtk::Builder> builder;

#include "widgets.hpp"

int main(int argc, char* argv[]) {
	app = Gtk::Application::create(argc, argv, "com.squgeim.typer");

	try {
		builder = Gtk::Builder::create_from_file("glade.xml");
	}
	catch(const Glib::FileError& ex) {
		std::cerr<<"FileError: "<<ex.what()<<std::endl;
		return -1;
	}
	catch(const Glib::MarkupError& ex) {
		std::cerr<<"MarkupError: "<<ex.what()<<std::endl;
		return -1;
	}
	catch(const Gtk::BuilderError& ex) {
		std::cerr<<"BuilderError: "<<ex.what()<<std::endl;
		return -1;
	}

	try {
		myWidget <Gtk::Window> mainwin("main");
		MenuButton menu[4];
		for(int i=0;i<4;i++) menu[i]=MenuButton(MenuButton::menubtns[i]);
		for(int i=0;i<4;i++) pages[i]=Page(Page::pgs[i]);
		pages[4]=Page("welcome");
		
		app->run(*mainwin.rtr());
		//app->run(*(mainwin->));
	}
	catch(int) {
		std::cerr<<"The main window was not found in the xml."<<std::endl;
		return -1;
	}
}
