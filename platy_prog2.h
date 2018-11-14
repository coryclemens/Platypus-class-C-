#ifndef PLATY_PROG2_H_INCLUDED
#define PLATY_PROG2_H_INCLUDED
using namespace std;

class Platypus{
public:
    //Constructors
    Platypus();  //REQUIRED IN PROG.2 ASSIGNMENT DESCRIPTION = ***

    Platypus(char initGender, float initWeight, short initMonthAge, char initNameInitial); //***

    //Display
    void print(ostream & out)const; //***

    //Utility
    void age_me();  //***

    void fight(Platypus & p2);   //***

    void eat();   //***

    void hatch();  //***

    //Accessors
    short get_monthAge()const;
    char get_nameInit()const;
    char get_gender()const;
    float get_weight()const;
    bool get_alive()const;
    bool get_mutant()const;

    //setters
    void make_dead();
    void set_monthAge(short newAge);
    void set_nameInit(char newInit);
    void set_gender(char newGender);
    void set_weight(float newWeight);
    void set_alive(bool newAlive);
    void set_mutant(bool newMutant);






private:
    float weight=0;
    short monthAge=0;
    char nameInit= '\0';
    char gender= '\0';
    bool alive=0;
    bool mutant=0;

};


ostream & operator<<(ostream & out, const Platypus & p);


#endif // PLATY_PROG2_H_INCLUDED
