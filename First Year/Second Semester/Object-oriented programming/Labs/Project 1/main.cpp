#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

// class user
// class movie
// class series
// class actors

class Movie{
private:
    int releaseYear;
    char* name;
    float duration; // minutes
    bool isTop10;
    double rating;
    char* description;
    char ageRating; // G = general audience, R = restricted
public:
    // constructors
    Movie();
    Movie(char* name,char* description,int releaseYear,float duration,double rating,bool isTop10,char ageRating);
    Movie(char* name,char* description,int releaseYear,float duration,double rating);
    Movie(char* name,float duration,double rating,char ageRating);
    Movie(const Movie &obj);
    ~Movie();

    // operators
    Movie& operator=(const Movie &obj);
    friend ostream& operator<<(ostream& out,const Movie &obj);
    friend istream& operator>>(istream& in,Movie &obj);

    // methods

    // getters
    int getReleaseYear();
    float getDuration();
    bool getIsTop10();
    double getRating();
    char getAgeRating();
    const char* getName() const;
    const char* getDescription() const;

    // setters
    void setReleaseYear(int releaseYear);
    void setDuration(float duration);
    void setIsTop10(bool isTop10);
    void setRating(double rating);
    void setAgeRating(char ageRating);
    void setName(char *name);
    void setDescription(char *description);
};

Movie::Movie() {
    this->releaseYear = 0;
    this->name = new char[strlen("Unnamed")+1];
    strcpy(this->name,"Unnamed");
    this->duration = 0;
    this->isTop10 = false;
    this->rating = 0;
    this->description = new char[strlen("No description given")+1];
    strcpy(this->description,"No description given");
    this->ageRating = 'R';
}

Movie::Movie(char* name,char* description,int releaseYear,float duration,double rating,bool isTop10,char ageRating) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->description = new char[strlen(description)+1];
    strcpy(this->description,description);
    this->releaseYear = releaseYear;
    this->duration = duration;
    this->rating = rating;
    this->isTop10 = isTop10;
    this->ageRating = ageRating;
}

Movie::Movie(char* name,char* description,int releaseYear,float duration,double rating) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->description = new char[strlen(description)+1];
    strcpy(this->description,description);
    this->releaseYear = releaseYear;
    this->duration = duration;
    this->rating = rating;
    this->isTop10 = false;
    this->ageRating = 'R';
}

Movie::Movie(char* name,float duration,double rating,char ageRating) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->description = new char[strlen("No description given")+1];
    strcpy(this->description,"No description given");
    this->releaseYear = 0;
    this->duration = duration;
    this->rating = rating;
    this->isTop10 = false;
    this->ageRating = ageRating;
}

Movie& Movie::operator=(const Movie &obj) {
    if(this != &obj)
    {
        if(this->name != NULL)
        {
            delete[] this->name;
            this->name = NULL;
        }
        if(this->description != NULL)
        {
            delete[] this->description;
            this->description = NULL;
        }

        this->name = new char[strlen(obj.name)+1];
        strcpy(this->name,obj.name);
        this->description = new char[strlen(obj.description)+1];
        strcpy(this->description,obj.description);
        this->releaseYear = obj.releaseYear;
        this->duration = obj.duration;
        this->isTop10 = obj.isTop10;
        this->rating = obj.rating;
        this->ageRating = obj.ageRating;
    }
    // ask why it works without
    return *this;
}

ostream& operator<<(ostream& out,const Movie &obj) {
    out<<"Name: "<<obj.name<<endl;
    out<<"Description: "<<obj.description<<endl;
    out<<"Release Year: "<<obj.releaseYear<<endl;
    out<<"Duration: "<<obj.duration<<" minutes"<<endl;
    out<<"Top 10: "<<obj.isTop10<<endl;
    out<<"Rating: "<<obj.rating<<endl;
    out<<"Age Rating: "<<obj.ageRating<<endl;

    return out;
}

istream& operator>>(istream& in,Movie &obj) {
    char name[50],description[256];

    cout<<"Enter name: "<<endl;
    in>>name;
    // in>> doesn't get the \n transmitted by keyboard
    // so i get rid of it using in.get()
    in.get();
    if(obj.name != NULL)
    {
        delete[] obj.name;
        obj.name = NULL;
    }
    obj.name = new char[strlen(name)+1];
    strcpy(obj.name,name);

    cout<<"Enter description: "<<endl;
    // in.getline() to read the whole line until \n
    in.getline(description,255);
    if(obj.description != NULL)
    {
        delete[] obj.description;
        obj.description = NULL;
    }
    obj.description = new char[strlen(description)+1];
    strcpy(obj.description,description);

    cout<<"Enter release year: "<<endl;
    in>>obj.releaseYear;

    cout<<"Enter duration(in minutes): "<<endl;
    in>>obj.duration;

    cout<<"Is it top 10? "<<endl;
    in>>obj.isTop10;

    cout<<"Rating: "<<endl;
    in>>obj.rating;

    cout<<"Age rating: "<<endl;
    in>>obj.ageRating;

    return in;
}

Movie::Movie(const Movie &obj) {
    this->releaseYear = obj.releaseYear;
    this->name = new char[strlen(obj.name)+1];
    strcpy(this->name,obj.name);
    this->duration = obj.duration;
    this->isTop10 = obj.isTop10;
    this->rating = obj.rating;
    this->description = new char[strlen(obj.description)+1];
    strcpy(this->description,obj.description);
    this->ageRating = obj.ageRating;
}

Movie::~Movie() {
    if(this->name != NULL)
    {
        delete[] this->name;
        this->name = NULL;
    }
    if(this->description != NULL)
    {
        delete[] this->description;
        this->description = NULL;
    }
}

int Movie::getReleaseYear() {
    return releaseYear;
}

float Movie::getDuration() {
    return duration;
}

bool Movie::getIsTop10() {
    return isTop10;
}

double Movie::getRating() {
    return rating;
}

char Movie::getAgeRating() {
    return ageRating;
}

const char* Movie::getName() const {
    return name;
}

const char* Movie::getDescription() const {
    return description;
}

void Movie::setReleaseYear(int releaseYear) {
    this->releaseYear = releaseYear;
}

void Movie::setDuration(float duration) {
    this->duration = duration;
}

void Movie::setIsTop10(bool isTop10) {
    this->isTop10 = isTop10;
}

void Movie::setRating(double rating) {
    this->rating = rating;
}

void Movie::setAgeRating(char ageRating) {
    this->ageRating = ageRating;
}

void Movie::setName(char *name) {
    if(this->name != NULL)
    {
        delete[] this->name;
        this->name = NULL;
    }
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
}

void Movie::setDescription(char *description) {
    if(this->description != NULL)
    {
        delete[] this->description;
        this->description = NULL;
    }
    this->description = new char[strlen(description)+1];
    strcpy(this->description,description);
}

class Series{
private:
    string name;
    int nrSeasons;
    int* nrEpisodes;
    // for every season store duration of every episode;
    vector<vector<int>> durationEpisodes;
    float rating;
    int releaseYear;
public:
    // constructors
    Series();
    Series(string name,float rating,int releaseYear);
    Series(string name,int nrSeasons,int* nrEpisodes,vector<vector<int>> durationEpisodes);
    Series(string name,int nrSeasons,int* nrEpisodes,vector<vector<int>> durationEpisodes,float rating,int releaseYear);
    Series(const Series &obj);
    ~Series();

    // operators
    friend ostream& operator<<(ostream& out,const Series &obj);
    friend istream& operator>>(istream& in,Series &obj);
    Series& operator=(const Series &obj);
    // methods

    // getters
    const string getName() const;
    int getNrSeasons();
    const int* getNrEpisodes() const;
    float getRating();
    int getReleaseYear();
    const vector<vector<int>> getDurationEpisodes() const;

    // setters
    void setName(string name);
    void setNrSeasons(int nrSeasons);
    void setNrEpisodes(int* nrEpisodes,int nrSeasons);
    void setRating(float rating);
    void setReleaseYear(int releaseYear);
    void setDurationEpisodes(vector<vector<int>> durationEpisodes);
};

Series::Series() {
    this->name = "No name";
    this->nrSeasons = 0;
    this->nrEpisodes = NULL;
    this->rating = 0;
    this->releaseYear = 0;
}

Series::Series(string name,float rating,int releaseYear) {
    this->name = name;
    this->nrSeasons = 0;
    this->nrEpisodes = NULL;
    this->rating = rating;
    this->releaseYear = releaseYear;
}

Series::Series(string name,int nrSeasons,int* nrEpisodes,vector<vector<int>> durationEpisodes) {
    this->name = name;
    this->nrSeasons = nrSeasons;
    this->nrEpisodes = new int[nrSeasons];
    for(int i=0;i<nrSeasons;i++)
        this->nrEpisodes[i] = nrEpisodes[i];

    for(int i=0;i<durationEpisodes.size();i++)
    {
        vector<int> temp;
        for(int j=0;j<durationEpisodes[i].size();j++)
            temp.push_back(durationEpisodes[i][j]);
        this->durationEpisodes.push_back(temp);
    }

    this->releaseYear = 0;
    this->rating = 0;
}

Series::Series(string name,int nrSeasons,int* nrEpisodes,vector<vector<int>> durationEpisodes,float rating,int releaseYear) {
    this->name = name;
    this->nrSeasons = nrSeasons;
    this->nrEpisodes = new int[nrSeasons];
    for(int i=0;i<nrSeasons;i++)
        this->nrEpisodes[i] = nrEpisodes[i];

    for(int i=0;i<durationEpisodes.size();i++)
    {
        vector<int> temp;
        for(int j=0;j<durationEpisodes[i].size();j++)
            temp.push_back(durationEpisodes[i][j]);
        this->durationEpisodes.push_back(temp);
    }

    this->rating = rating;
    this->releaseYear = releaseYear;
}

Series::Series(const Series &obj) {
    this->name = obj.name;
    this->nrSeasons = obj.nrSeasons;
    this->rating = obj.rating;
    this->releaseYear = obj.releaseYear;

    // don't delete nrEpisodes
    this->nrEpisodes = new int[obj.nrSeasons];
    for(int i = 0;i<obj.nrSeasons;i++)
        this->nrEpisodes[i] = obj.nrEpisodes[i];

    if(this->durationEpisodes.empty() == 0) this->durationEpisodes.clear();
    for(int i=0;i<obj.durationEpisodes.size();i++)
    {
        vector<int> temp;
        for(int j=0;j<obj.durationEpisodes[i].size();j++)
            temp.push_back(obj.durationEpisodes[i][j]);
        this->durationEpisodes.push_back(temp);
    }
}

Series::~Series() {
    if(this->nrEpisodes != NULL)
    {
        delete[] this->nrEpisodes;
        this->nrEpisodes = NULL;
    }
    if(this->durationEpisodes.empty() == 0) this->durationEpisodes.clear();
    this->name = "";
    this->nrSeasons = 0;
    this->rating = 0;
    this->releaseYear = 0;
}

ostream& operator<<(ostream& out,const Series &obj) {
    out<<"Name: "<<obj.name<<endl;
    out<<"Release Year: "<<obj.releaseYear<<endl;
    out<<"Rating: "<<obj.rating<<endl;
    out<<"Number of Seasons: "<<obj.nrSeasons<<endl;
    out<<"Number of episodes for each season: "<<endl;
    if(obj.nrSeasons == 0) cout<<"\t0"<<endl;
    for(int i=0;i<obj.nrSeasons;i++)
        cout<<"\tSeason "<<i+1<<": "<<obj.nrEpisodes[i]<<" episodes"<<endl;

    out<<"Duration for each episode: "<<endl;
    if(obj.durationEpisodes.empty()) cout<<"\t0"<<endl;
    for(int i=0;i<obj.durationEpisodes.size();i++)
    {
        cout<<"\tFor season "<<i+1<<": "<<endl;
        for(int j=0;j<obj.durationEpisodes[i].size();j++)
            cout<<"\t\tEpisode "<<j+1<<" takes "<<obj.durationEpisodes[i][j]<<" minutes"<<endl;
    }
    return out;
}

istream& operator>>(istream& in,Series &obj) {
    cout<<"Enter name: "<<endl;
    in>>obj.name;
    cout<<"Enter release year: "<<endl;
    in>>obj.releaseYear;
    cout<<"Enter rating: "<<endl;
    in>>obj.rating;
    cout<<"Enter number of season: "<<endl;
    in>>obj.nrSeasons;
    if(obj.nrEpisodes != NULL)
    {
        delete[] obj.nrEpisodes;
        obj.nrEpisodes = NULL;
    }
    obj.nrEpisodes = new int[obj.nrSeasons];
    for(int i=0;i<obj.nrSeasons;i++)
    {
        cout<<"Enter number of episodes for season "<<i+1<<": "<<endl;
        in>>obj.nrEpisodes[i];
    }
    for(int i=0;i<obj.nrSeasons;i++)
    {
        vector<int> temp;
        cout<<"Enter duration for season "<<i+1<<" (in minutes): "<<endl;
        for(int j=0;j<obj.nrEpisodes[i];j++)
        {
            int aux;
            cout<<"\tEpisode "<<j+1<<": "<<endl;
            in>>aux;
            temp.push_back(aux);
        }
        obj.durationEpisodes.push_back(temp);
    }

    return in;
}

Series& Series::operator=(const Series &obj) {
    if(this != &obj)
    {
        this->name = obj.name;
        this->nrSeasons = obj.nrSeasons;
        this->rating = obj.rating;
        this->releaseYear = obj.releaseYear;

        if(this->nrEpisodes != NULL)
        {
            delete[] this->nrEpisodes;
            this->nrEpisodes = NULL;
        }
        this->nrEpisodes = new int[obj.nrSeasons];
        for(int i = 0;i<obj.nrSeasons;i++)
            this->nrEpisodes[i] = obj.nrEpisodes[i];

        if(this->durationEpisodes.empty() == 0) this->durationEpisodes.clear();
        for(int i=0;i<obj.durationEpisodes.size();i++)
        {
            vector<int> temp;
            for(int j=0;j<obj.durationEpisodes[i].size();j++)
                temp.push_back(obj.durationEpisodes[i][j]);
            this->durationEpisodes.push_back(temp);
        }
    }
    return *this;
}

const string Series::getName() const {
    return this->name;
}

int Series::getNrSeasons() {
    return this->nrSeasons;
}

const int *Series::getNrEpisodes() const {
    return this->nrEpisodes;
}

float Series::getRating() {
    return this->rating;
}

int Series::getReleaseYear() {
    return this->releaseYear;
}

const vector<vector<int>> Series::getDurationEpisodes() const{
    return this->durationEpisodes;
}

void Series::setName(string name) {
    this->name = name;
}

void Series::setNrSeasons(int nrSeasons) {
    this->nrSeasons = nrSeasons;
}

void Series::setNrEpisodes(int *nrEpisodes, int nrSeasons) {
    if(this->nrEpisodes != NULL)
    {
        delete[] this->nrEpisodes;
        this->nrEpisodes = NULL;
    }
    this->nrEpisodes = new int[nrSeasons];
    for(int i=0;i<nrSeasons;i++)
        this->nrEpisodes[i] = nrEpisodes[i];
}

void Series::setRating(float rating) {
    this->rating = rating;
}

void Series::setReleaseYear(int releaseYear) {
    this->releaseYear = releaseYear;
}

void Series::setDurationEpisodes(vector<vector<int>> durationEpisodes) {
    this->durationEpisodes = durationEpisodes;
}

class User {
private:
    // ask how to get all movies from user class
    static int contorID;
    const int idUser;
    string lastName,firstName;
    vector<string> watched;
    int year;
public:
    // constructors
    User();
    User(string lastName,string firstName);
    User(string lastName,string firstName,int year);
    User(string lastName,string firstName,int year,vector<string> watched);
    ~User();

    // operators

    // methods
//        method to format name

    // getters
    int getIdUser();
    static int getContorId();
    const string getLastName() const;
    const string getFirstName() const;
    const vector<string> &getWatched() const;
    int getYear();

    // setters
    void setLastName(string lastName);
    void setFirstName(string firstName);
    void setWatched(const vector<string> watched);
    void setYear(int year);
};

// global declaration for static variable
int User::contorID = 100000000;
// using initializer list
User::User():idUser(contorID++) {
    this->lastName = "None";
    this->firstName = "None";
    this->year = 0;
}

User::User(string lastName,string firstName):idUser(contorID++) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->year = 0;
}

User::User(string lastName,string firstName,int year):idUser(contorID++) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->year = year;
}

User::User(string lastName,string firstName,int year,vector<string> watched):idUser(contorID++) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->year = year;
    for(int i=0;i<watched.size();i++)
        this->watched.push_back(watched[i]);
}

User::~User() {
    contorID--;
    this->lastName = "";
    this->firstName = "";
    this->year = 0;
    if(this->watched.empty() == 0) this->watched.clear();
}

int User::getIdUser() {
    return this->idUser;
}

int User::getContorId() {
    return contorID;
}

const string User::getLastName() const {
    return this->lastName;
}

const string User::getFirstName() const {
    return this->firstName;
}

const vector<string> &User::getWatched() const {
    return this->watched;
}

int User::getYear() {
    return this->year;
}

void User::setLastName(string lastName) {
    this->lastName = lastName;
}

void User::setFirstName(string firstName) {
    this->firstName = firstName;
}

void User::setWatched(vector<string> watched) {
    this->watched = watched;
}

void User::setYear(int year) {
    this->year = year;
}


int main() {
//    MOVIES TESTS:
    /*
    Movie film("Spargerea",126,9.03,'G');
    cout<<film<<endl;

    Movie film2;
    film2 = film;
    cout<<film2<<endl;

    Movie film3;
    cin>>film3;
    cout<<endl<<film3;
     */

//    SERIES TESTS:
    /*
    int v[] = {2,3,1};
    vector<vector<int>> m{
            {23,44},
            {15,74,22},
            {68},
    };

    vector<vector<int>> t{
            {2,5},
            {1,7,2},
            {6},
    };
    Series serial("Buciumeala",3,v,m);
    cout<<serial<<endl;

    Series serial2(serial);
    cout<<serial2<<endl;

    serial2.setDurationEpisodes(t);

    for(int i=0;i<serial2.getDurationEpisodes().size();i++)
    {
        for(int j=0;j<serial2.getDurationEpisodes()[i].size();j++)
            cout<<serial2.getDurationEpisodes()[i][j]<<" ";
        cout<<endl;
    }

    Series serial3;
    serial3.setNrSeasons(3);
    serial3.setNrEpisodes(v,3);
    cout<<serial3<<endl;


//    Series serial3;
    cin>>serial3;
    serial3 = serial;
    cout<<serial3<<endl;
     */

    return 0;
}