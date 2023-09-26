#include <iostream>
#include <vector>
#include <string>
#include <datapath.h>
using namespace std;
//I made the class named Car which is private and has members make, model and year.
class Car{
private:

    string make;
    string  model;
    int year;

public://i used the public access specifier to make the carID and rented status of the car throughout the runtime of the program to public
    int carID;
    bool rented;
public:
    Car(int carID,string make,string model,int year,bool rented)//car constructor that takes in arguments
    :carID(carID),make(make),model(model),year(year)
    {
    }

    int getcarID(){//method used to get the carID
        return carID;
    }
    bool isRented(){//method used to get the rent status
        return rented;
        }

    string getmake(){//method used to get the car make
        return make;
    }
    string  getmodel(){//method used to get the car model
        return model;
    }
    int getyear(){//method used to get the car model year
        return year;
    }



};
/*I created the CarRentalSystem class which is a derived class of the Car class which is the base class. The CarRentalSystem has members
which are a vector that stores the cars in the program and some methods that we use to add, delete, view, rent, and return the cars
the CarRentalSystem class uses the Encapsulation technique, which allows it to access the private members of the car class*/

class CarRentalSystem : public Car{
private:
    vector<Car>cars;

    public:
    /*the CarRentalSystem constructor, accessing the Car members using the Encapsulation technique
    And having access to the members throughout the run time of the program*/
    CarRentalSystem(int carID, string make, string model, int year, bool rented) : Car(carID, make, model, year, rented) {}

    /*The void displayrented function will display the rented cars,
    s it uses a for loop to iterate through the vector cars and checks if there is any car that has been rented*/
        void displayrented(){//checks if there is any car in the vector
        if(cars.empty()){
            cout<<"There are currently no rented cars in the system!";
        }
        for(Car &car : cars){
            if(car.isRented())
                {
                cout<<"CarID "<< car.getcarID() <<endl;
                cout<<"Make  "<< car.getmake() <<endl;
                cout<<"Model "<< car.getmodel() <<endl;
                cout<<"Year  "<< car.getyear() <<endl;
                cout<<endl;
                }
            }
        }
        delcar(int carID){//function is used to delete or removes a car from the vector
            auto it = cars.begin();//declaration of an iterator called -it- in an std vector
            while(it != cars.end()){//checks the condition if the -it- iterator is not equal to the vectors if true it does through
                if(it->getcarID()==carID){//if the -it- iterator checks if the carID of the current car in the vector is equal to the carID of the one being searched for.
                    it = cars.erase(it);
                        cout<<"Car "<< carID <<" has been deleted! "<<endl;
                            break;
                            }
                            else{
                                ++it;
                                }
                        }
                            if(it==cars.end()){
                            cout<<" Car "<< carID <<" Not found. "<<endl;
                            }
                    }
        void addCar(){//the addcar function is used to add cars to the vector
            int carID;
            string make, model;
            int year;
            bool rented = false;
            cout<<"TO ADD A CAR PLEASE FOLLOW THE FOLLWING STEPS:\n"
                  "----------------------------------------------"<<endl;
            cout<<"Enter CarID: \n"
                  "Enter Car Make: \n"
                  "Enter Car Model: \n"
                  "Enter Model year: \n"
                  "-------------------"<<endl;
                  while(true){//condition used to check if the car is exists or not
                  cin>>carID;
                  cin.ignore();
                  if(carID == 0){
                        break;
                  }
                  bool exist = false;
                  for(Car &car : cars)
                    {
                        if(car.getcarID() ==carID)
                            {
                                exist = true;
                                cout<<"Car "<< carID <<"already exists!\n Please enter a carID that hasn't been take." <<endl;
                                break;
                            }
                    }
                    if(exist)
                        {
                            continue;
                        }
                  if(carID < 0){
                        cout<<"invalid CarID!\n"
                               "Please enter a valid CarID"<<endl;
                                continue;
                                }

                  cin>>make;
                  cin.ignore();

                  cin>>model;
                  cin.ignore();

                  cin>>year;
                  cin.ignore();

                  if(year < 0){
                    cout<<"Invalid car make year!"
                          "Please enter a valid year!"<<endl;
                  }

            cars.push_back(Car(carID,make,model,year,rented));

                cout<<"Do you want add another car? (yes/no) Press: y for yes and n for n :";
                char pick;
                cin>> pick;

                if(pick == 'n'){
                    break;
                }
            }
        }

        void displaycars(){//function used to display cars, the cars displayed are the non rented
        char dip;
        if(cars.empty()){
            cout<<"There are currently no cars in the system!";
        }
        for(Car& car : cars){
            if(!car.isRented()){
        cout<<"CarID : "<<car.carID<<endl;
        cout<<"Car make: "<<car.getmake()<<endl;
        cout<<"Car model is: "<<car.getmodel()<<endl;
        cout<<"The model year is: "<<car.getyear()<<endl;
                        }
            if(dip!= '\n'){
                break;}
                cout<<"Press 0 to exit: ";
                cin>>dip;
            }
            return;
        }

    void rentCar(int carID) {//function to rent a car
        bool carFound = false;
        for (Car &car : cars) {
            if (car.getcarID() == carID && !car.isRented()) {
                car.rented = true;
                    cout << "You have successfully rented: " << car.getmake() << " " << car.getmodel() << endl;
                    carFound = true;
                    break;
        }
    }
    if(!carFound){
    cout << "Car:  "<< carID <<"  not found or already rented." << endl;
        }
    }
     void returnCar(int carID) {//function to return the car
        bool carFound = false;
        for (Car &car : cars) {
            if (car.getcarID() == carID && car.isRented()) {
                car.rented = false;
                    cout << "You have successfully returned: " <<car.getmake() <<" "<< car.getmodel() << endl;
                    carFound = true;
                    break;
        }
    }
    if(!carFound){
    cout << "Car:  "<< carID <<"  not found or not rented." << endl;
        }
    }
};

int main()
{
    CarRentalSystem rentcars(0,"","",0,false);//we create an object of the CarRentalSystem class

    int MAD = 0;
    int carID;
    //our Graphical user interface.
    cout<<"\t\t\n"
          "***********************************************************\n"<<endl;
    cout<<"*** WELCOME TO MAD_CAR_RENTAL SERVICES\t\t\t***"<<endl;
    cout<<"\n"
    "***********************************************************\n"
    "***\tPlease follow the easy steps\t\t\t***\n"
    "***\tTo rent a vehicle of choice\t\t\t***\n"
    "***********************************************************\n"
    "***\tPress 1 to view available cars:\t\t\t***\n"
    "***\tPress 2 to Add a car:\t\t\t\t***\n"
    "***\tPress 3 to rent a car:\t\t\t\t***\n"
    "***\tPress 4 to return car:\t\t\t\t***\n"
    "***\tPress 5 to delete a car:\t\t\t***\n"
    "***\tPress 6 to view rented cars\t\t\t***\n"
    "***\tPress 0 to exit\t\t\t\t\t***\n"
    "***\t\t\t\t\t\t\t***\n"
    "***********************************************************"<<endl;
    //we iterate the switch statment
    while(true){
    cin>>MAD;
    switch(MAD){
    case 1:
        rentcars.displaycars();//call function to display available cars
        break;
    case 2:
        rentcars.addCar();//call function to add cars
        break;
    case 3:
        cout << "Enter the car ID you want to rent: ";
        cin >> carID;
        rentcars.rentCar(carID);//call function to rent cars
        break;
    case 4:
        cout<<"Enter the carID of the car you wish to return:";
        cin>>carID;
        rentcars.returnCar(carID);//call function to return cars pointing from the rentcar function
        break;
    case 5:
        cout<<"Enter the carID of the car you want to delete:";
        cin>>carID;
        rentcars.delcar(carID);//call function to delete car
        break;
    case 6:
        rentcars.displayrented();//call function to display rented cars
        break;
    default:
        MAD=0;
        exit(0);
        break;
    }
    }

    return 0;
}
