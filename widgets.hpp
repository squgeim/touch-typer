
template<class T>
class myWidget {
    T *ptr;
    public:
    myWidget(const char*);
    myWidget(){};
    T* operator->();
    T* rtr();
};

template<class T>
myWidget<T>::myWidget(const char* name) {
    ptr=0;
    try {
        builder->get_widget(name,ptr);
        if(!ptr) throw -1;
    }
    catch(int) {
        std::cerr<<"Could not open widget "<<name<<std::endl;
        throw;
    }
}

template<class T>
T* myWidget<T>::operator-> () {
    return ptr;
}

template<class T>
T* myWidget<T>::rtr() {
    return ptr;
}

////////////////////////////////////////////////////////////////////////

class Page: public myWidget<Gtk::Fixed> {
    int me;
    public:
    static std::string pgs[];
    Page(const std::string);
    Page(){};
    void show();
};
std::string Page::pgs[] = {"choosefile","type","highscore","about"};
Page::Page(const std::string name):myWidget(name.c_str()){
    for(int i=0;i<4;i++) if(name==pgs[i]) {me=i;break;}
}
Page pages[5];
int now=4;
void Page::show() {
    pages[now]->hide();
    (*this)->show();
    now=me;
}

////////////////////////////////////////////////////////////////////////

class MenuButton: public myWidget<Gtk::Button> {
    int me;
    public:
    static std::string menubtns[];
    MenuButton(const std::string);
    MenuButton(){};
    void clicked(int);
};
std::string MenuButton::menubtns[] = {"file","ran","scor","abt"};

MenuButton::MenuButton(const std::string name):myWidget<Gtk::Button>(name.c_str()) {
    for(int i=0;i<4;i++) if(name==menubtns[i]) {me=i;break;}
    //rtr()->signal_clicked().connect(sigc::bind<int>( sigc::mem_fun(*this,&MenuButton::clicked),me ));
    rtr()->signal_clicked().connect(sigc::mem_fun(pages[me],&Page::show));
}

void MenuButton::clicked(int which) {
    std::cerr<<menubtns[which]<<" clicked"<<std::endl;
}
