#include <fstream>

class typer {
    // File and if file is set:
    bool isset;
    std::ifstream f;
    
    // The widgets:
    myWidget<Gtk::Label> label;
    myWidget<Gtk::Entry> entry;
    myWidget<Gtk::Statusbar> speed;
    myWidget<Gtk::Statusbar> score;
    myWidget<Gtk::Statusbar> count;
    
    // The functions:
    void keydown();
    
    public:
    // The static ids of widgets in xml:
    static std::string l;
    static std::string e;
    static std::string spd;
    static std::string scr;
    static std::string cnt;
    
    // The public functions:
    typer();
    bool setrand();
    bool set(std::string);
};
std::string typer::l="main_text";
std::string typer::e="entry_text";
std::string typer::spd="speed";
std::string typer::scr="score";
std::string typer::cnt="count";

typer::typer() {
    label=myWidget<Gtk::Label>(l.c_str());
    entry=myWidget<Gtk::Entry>(e.c_str());
    speed=myWidget<Gtk::Statusbar>(spd.c_str());
    score=myWidget<Gtk::Statusbar>(scr.c_str());
    count=myWidget<Gtk::Statusbar>(cnt.c_str());
    /* TODO
     * set signal for each keypress.
     */
}

bool typer::set(std::string fname) {
    /* TODO
     * Set up error handling.
     */
    f.open(fname.c_str());
    isset=true;
    /* TODO
     * get the no. of chars in this file and set count to 0 of chars_in_this file
     */
    return true;
}
    
bool typer::setrand() {
    /* TODO
     * Have files 1.txt, 2.txt, 3.txt, etc and get a random int value in
     * the program so the program opens any of this randomly.
     * like this:
     * set(random_int+".txt")
     */
}

void typer::keydown() {
    /* This function will be called each time the user presses a key. So
     * all the checking and stuff will be managed here.
     */
}
