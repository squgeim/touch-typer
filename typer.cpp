#include<gtkmm.h>
using namespace std;

int main(int argc, char* argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.squgeim.typer");

	Gtk::Window window;
	window.set_default_size(600,300);
	window.set_title("Touch Typer");

	Gtk::Box box;
	Gtk::Button btn("Click here");
	box.pack_start(btn);
	window.add(box);
	btn.show();
	box.show();

	return app->run(window);
}
