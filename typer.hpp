#include <fstream>

class typer {
    // File and if file is set:
    std::ifstream f;
    static bool isset;
    static std::string file;

    // Vars
    int total;
    int now;
    std::string line;
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
    void keydown(Gtk::Entry*);
    bool readline();
    void updatecount();

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

    //text=Gtk::EntryBuffer::create();
    //text->set_text("Key Pressed");
    //entry->set_buffer(text);
    //text->signal_inserted_text().connect(sigc::mem_fun(*this,&typer::keydown));
    entry->signal_changed().connect( sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this,&typer::keydown), entry.rtr()) );

    if(!isset) setrand();
    f.open(file.c_str());
    f.seekg(0,std::ios::end);
    now=0;
    total=f.tellg();
    f.seekg(0);
    updatecount();
    readline();

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
        line="";
        std::getline(f,line);
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

void typer::keydown(Gtk::Entry *entry) {
    /* This function will be called each time the user presses a key. So
     * all the checking and stuff will be managed here.
     */
    //std::cout<<"typed"<<entry->get_text()<<std::endl;
	std::string text=entry->get_text();
	char n=text[text.length()-1];
	std::cout<<n<<std::endl;
}
