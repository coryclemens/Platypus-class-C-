#include <iostream>
#include "platy_prog2.h"
#include <random>


using namespace std;

int main()
{
Platypus Cory;
cout << Cory << endl;
Cory.eat();
cout << Cory << endl;
Cory.age_me();
cout << Cory << endl;

Platypus Clemens('m', 4.5, 2, 'C');
Clemens.age_me();
cout << Clemens << endl;
Clemens.eat();
cout << Clemens << endl;
Clemens.hatch();

Platypus Jay('f', 9, 2, 'J');
Jay.eat();

Jay.fight(Clemens);

Platypus Corn('F', 9.9, 8, 'C');
cout << Corn << endl;
Corn.eat();
Corn.eat();
Corn.age_me();

Platypus Sean;
Sean.set_alive(1);
Sean.set_gender('M');
Sean.set_monthAge(5);
Sean.set_mutant(1);
Sean.set_nameInit('S');
Sean.set_weight(8);
cout << Sean << endl;
Sean.eat();
Sean.age_me();

cout << Sean << endl;


    return 0;

}
