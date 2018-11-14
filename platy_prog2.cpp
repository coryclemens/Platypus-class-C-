#include <iostream>
using namespace std;
#include "platy_prog2.h"
#include <cctype>
#include <random>



//Constructors

Platypus::Platypus()
 :alive(0)
{
    cout << "Platypus Constructed" << endl;
}


Platypus::Platypus(char initGender, float initWeight, short initMonthAge, char initNameInitial)
{
    //Invariant
    if((initGender=='M' || initGender=='F' || initGender=='m' || initGender== 'f')
       && initWeight>=0
       && initMonthAge>=0
       && (isdigit(initNameInitial)^1)){

        weight=initWeight;
        gender=initGender;
        monthAge=initMonthAge;
        nameInit=initNameInitial;
        alive=1;
        mutant=0;
        cout << nameInit << " Platypus Constructed" << endl;
        cout <<"Gender: " << gender << endl;
        cout <<"Weight: " << weight << endl;
        cout <<"Age: " << monthAge << " months" << endl;
        cout <<"Alive: " << alive << endl;
        cout <<"Mutant: " << mutant << endl << endl;
    }
    else{
        cout << "\t\t\tInvalid Values Passed" << endl;
    }
}

void Platypus::print(ostream & out)const{

    out << "Name:  " << nameInit << endl;
    out << "Gender:  " << gender << endl;
    out << "Age:  " << monthAge << " months" <<endl;
    out << "Weight:  " << weight << " lbs" << endl;
    out << "Alive:  " << alive << "  (1=YES 0=NO)" << endl;
    out << "Mutant:  " << mutant << "  (1=YES 0=NO)" << endl;

}

//Ages platypus 1month, 2% chance becomes mutant, (weight*10)% chance to die
void Platypus::age_me(){
    if(alive==0){
        cout << "The Platypus is already dead! Unlucky." << endl;
        return;
    }
    cout << "Aging Platypus" << endl;
    int chance;
    int weight_percent;
    int death_rand;

    monthAge+=1;

//Creates 2% chance of mutant
//rand % 50 returns int from 0-49, add 1 to get 1-50
    chance = (rand() % 50) + 1;
    if(chance==2){
        mutant = 1;
        cout << "Platypus has mutated!" << endl;
    }

    if(weight>=10){
        cout << "The aged platypus has died! Unlucky." << endl;
        alive=0;
        return;
    }
//Chance of death = (weight * 10)%
    weight_percent = weight * 10;
//Creates random number 1-100
    death_rand = (rand() % 100) + 1;
//if random number <= (weight*10) : DEAD
    if(death_rand<=weight_percent){
        alive = 0;
        cout << "The aged platypus has died! Unlucky." << endl;

    }


}


void Platypus::fight(Platypus & p2){
    if(alive==0){
        cout << "Your Platypus isn't Alive to Fight" << cout;
        return;
    }
    if(p2.get_alive()==0){
        cout << "The Platypus you want to Fight is already Dead!" << endl;
    }
    cout << "The 2 Platypuses Engage in Combat!" << endl;
    float p2_weight=p2.get_weight();
    float fight_ratio=(weight/p2_weight)*50;
    int chance = (rand()%100)+1;
    if(chance<fight_ratio){
        p2.make_dead();
        cout << "The 2nd Platypus was killed... Unlucky" << endl;
    }
    else{
        alive=0;
        cout << "The calling platypus has died in battle.. Unlucky" << endl;
    }


}

void Platypus::eat(){
    if(alive==0){
        cout<<"A Dead Platypus Cannot Eat..." << endl;
        return;
    }
    cout << "Eating..." << endl;

    //Random # between 1-50
    float chance = (rand()%50)+1;
    //1/1000=.001=.1% gain, 50/1000=.05=5% gain.
    chance=chance/1000;
    weight=(weight*chance)+weight;
    cout << "New weight is: " << weight << endl;

}

void Platypus::hatch(){
char new_name;
char new_gend;
//50% chance to be m or f
int chance = (rand()%2);
if(chance==0){
    new_gend = 'M';
}
else{
    new_gend = 'F';
}

cout << "New Platypus Gender is: " << new_gend << endl;
cout << "Choose name (1st initial only): " << endl;
cin >> new_name;

//Weight chance, between .1-1lbs, #1-10, 1/100=.1lb, 100/100=1lb
float new_weight = ((rand()%100)+1)/100;
Platypus newP(new_gend, new_weight, 0, new_name);
cout << "New Platypus has been created" << endl;



}

void Platypus::make_dead(){
    alive = 0;
}


//Accessors
float Platypus::get_weight()const{

    return weight;
}

bool Platypus::get_alive()const{

    return alive;
}
short Platypus::get_monthAge()const{
    return monthAge;
}
char Platypus::get_nameInit()const{

    return nameInit;

}
char Platypus::get_gender()const{

    return gender;
}
bool Platypus::get_mutant()const{

    return mutant;
}

//SETTERS
void Platypus::set_weight(float newWeight){

    weight = newWeight;
}

void Platypus::set_alive(bool newAlive){

    alive=newAlive;
}
void Platypus::set_monthAge(short newAge){

    monthAge=newAge;
}
void Platypus::set_nameInit(char newInit){

    nameInit=newInit;

}
void Platypus::set_gender(char newGender){

    gender=newGender;
}
void Platypus::set_mutant(bool newMutant){

    mutant=newMutant;
}

//Overload Operators

ostream & operator<<(ostream & out, const Platypus & p)
{
  p.print(out);
  return out;
}












