

/* C++ Passing Structure to Function - Call by Value */

#include<iostream.h>
#include<conio.h>

struct distance
{
   int feet;
   int inches;
};

void prnsum(distance l1, distance l2);  // function prototype
void main()
{
   clrscr();

   distance length1, length2;   // two structures of type distance declared

   /* Read values for length1 */
   cout<<"Enter length 1:\n";
   cout<<"Feet: ";
   cin>>length1.feet;
   cout<<"\nInches: ";
   cin>>length1.inches;

   /* Read values for length2 */
   cout<<"\n\nEnter length 2:\n";
   cout<<"Feet: ";
   cin>>length2.feet;
   cout<<"\nInches: ";
   cin>>length2.inches;
   prnsum(length1, length2);      // print sum of length1 and length2

   getch();

}     // end of main()

void prnsum(distance l1, distance l2)
{
   distance l3;      // new structure
   l3.feet=l1.feet+l2.feet+(l1.inches+l2.inches)/12;  // 1 feet=12 inches
   l3.inches=(l1.inches+l2.inches)%12;
   cout<<"\n\nTotal Feet: "<<l3.feet<<"\n";
   cout<<"Total Inches: "<<l3.inches;
}
