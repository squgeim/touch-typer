#ifndef __TYPER_HPP__
#define __TYPER_HPP__

#include <fstream>

class typer {
    // File and if file is set:
    std::ifstream f;
    static bool isset;
    static std::string file;

    // Vars
    int total;
    int now;
    char line[100];
    //std::string line;
    std::string was;
    std::string is;

    // The widgets:
    myWidget<Gtk::Label> label;
    myWidget<Gtk::Entry> entry;
    myWidget<Gtk::Statusbar> speed;
    myWidget<Gtk::Statusbar> score;
    myWidget<Gtk::Statusbar> count;
    Glib::RefPtr<Gtk::EntryBuffer> text;

    // The functions:
    //void keydown(Gtk::Entry*,char*,int&);
    bool readline();
    void updatecount();
    //void pressed(char);
    void on_insert_text(const Glib::ustring&,int*);

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
    static void setfile(std::string);
    //static bool set();
};
std::string typer::l="main_text";
std::string typer::e="entry_text";
std::string typer::spd="speed";
std::string typer::scr="score";
std::string typer::cnt="count";
std::string typer::file="";
bool typer::isset=false;

typer::typer() {
    label=myWidget<Gtk::Label>(l.c_str());
    entry=myWidget<Gtk::Entry>(e.c_str());
    speed=myWidget<Gtk::Statusbar>(spd.c_str());
    score=myWidget<Gtk::Statusbar>(scr.c_str());
    count=myWidget<Gtk::Statusbar>(cnt.c_str());

    now=0;
    //text=Gtk::EntryBuffer::create();
    //text->set_text("Key Pressed");
    //entry->set_buffer(text);
    //text->signal_inserted_text().connect(sigc::mem_fun(*this,&typer::keydown));
    //entry->signal_changed().connect( sigc::bind<typer&>(sigc::ptr_fun(pressed), *this));

    if(!isset) setrand();
    f.open(file.c_str());
    f.seekg(0,std::ios::end);
    total=f.tellg();
    f.seekg(0);
    updatecount();
    readline();

    //entry->signal_changed().connect(sigc::bind<Gtk::Entry*,char*,int>(sigc::mem_fun(*this,&typer::keydown), entry.rtr(), line, now) );
    entry->signal_insert_text().connect(sigc::mem_fun(*this,&typer::on_insert_text));


    //entry->set_text("");
    //was=entry->get_text();
}

void typer::updatecount() {
    std::string nw,tot;
    std::stringstream out;
    out<<now;
    nw=out.str();
    out<<total;
    tot=out.str();
    count->push("Characters: "+nw+" of "+tot);
}

void typer::setfile(std::string s) {
    file=s;
    isset=true;
}

bool typer::readline() {
    if(!f.eof()) {
    //    std::getline(f,line,80);
        //char* tmp;
        f.getline(line,80);
        //line=tmp;
        //std::getline(f,line);
        label->set_text(line);
    }
    else return false;
}

bool typer::setrand() {
    /* TODO
     * Have files 1.txt, 2.txt, 3.txt, etc and get a random int value in
     * the program so the program opens any of this randomly.
     * like this:
     * set(random_int+".txt")
     */
    setfile("1.txt");
}

void typer::on_insert_text(const Glib::ustring &txt,int *i) {
    std::cout<<txt<<std::endl;
    std::cout<<*i<<std::endl;
    std::cout<<line<<std::endl;
    myWidget <Gtk::Entry> entry(e.c_str());
	entry->set_text("someting");
}


#endif
