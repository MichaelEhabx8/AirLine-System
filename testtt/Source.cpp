#include <iostream>
#include <string>
#include <ctime>
#include <regex>
using namespace std;

const int Maxflights = 100;
int numflights = 4;
int ticketnum = 0;
int Pidcheck = 0;

struct date {
    int day, month, year;
};
struct arrival {
    string city;
    string time;
};
struct departure {
    string city;
    string time;
};
struct ticketinfo {
    int flightNum;
    int id;
    int ticketNum;
    int NumOfSeats;
    string reservationDate;
    departure dep;
    arrival arr;
};

struct passengerinfo {
    string username;
    string fullname;
    string password;
    date dateOfBirth;
    int id;
    string phone;
    string address;
    int numOftickets = 0;
    int ticketIndex = 0;

    ticketinfo tick[30];
}passenger[800];

struct flightinfo {
    int flightNum; // ghiarna deh mn string l int
    int NumOfSeats;
    string date;
    departure dep;
    arrival arr;

}flights[100];


// Function  generate al password mn 3 letters flusername we 3 arkam random
string generatePassword(string username) {
    srand(time(0));
    string password = username.substr(0, 3);
    for (int i = 0; i < 3; i++) {
        password += to_string(rand() % 10);
    }
    return password;
}
// Function algenerate id b 10 arakam we awl arkam 3id milado
int generateID(int dateOfBirth) {
    int all;
    all = dateOfBirth * 1000;
    for (int i = 0; i < 3; i++) {
        all += (rand() % 10);
    }
    return all;

}
// Function for user signup
int i = 0;
void signup() {

    cout << "-------------------------------------------------" << endl;
    cout << "                      Sign Up                    " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Please enter your full name: ";
    cin.ignore();
    getline(cin, passenger[i].fullname);

    cout << "Please enter your username (usernames can't contain spaces):";
    string username;
    getline(cin, username);
    cout << "Please enter your date of birth:" << endl;
    cout << "  Year (YYYY): ";
    cin >> passenger[i].dateOfBirth.year;
    cin.ignore();
    cout << "  Month (MM): ";
    cin >> passenger[i].dateOfBirth.month;
    cin.ignore();
    cout << "  Day (DD): ";
    cin >> passenger[i].dateOfBirth.day;
    cin.ignore();
    cout << "Please enter your address: ";
    getline(cin, passenger[i].address);
    cout << "Please enter your phone number: ";
    cin >> passenger[i].phone;
    passenger[i].username = username;
    passenger[i].password = generatePassword(username);
    passenger[i].id = generateID(passenger[i].dateOfBirth.year);
    system("cls");
    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
    cout << "                                  Your account has been created successfully." << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;

    cout << "Username: " << passenger[i].username << endl;
    cout << "Password: " << passenger[i].password << endl;
    cout << "ID: " << passenger[i].id << endl;
    cout << "                        << Memorize your username and password for further logins! >> " << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
    cout << "                                        RETURNING TO THE MAIN MENU...." << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
    i++;
}
// Function al login bl bool 3ashn law al password 8alat wala la
int login(passengerinfo passenger[], int& pidcheck) {
    int check = 1;
    int choice;
    string adminpass;
loginagain:
    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
    cout << "Do you want to login as an Admin or Passenger? " << endl;
    cout << "1. Admin" << endl;
    cout << "2. Passenger" << endl;
    cout << "3. Go to the Mainmenu" << endl;
    cout << "Enter your selection : ";
    cin >> choice;
    if (choice == 1) {
    adminagain:  cout << "Enter the password: ";
        cin >> adminpass;
        system("cls");
        cout << "                                                   LOADING...                                           " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;

        if (adminpass == "admin2023") {
            cout << "-------------------------------------------------" << endl;
            cout << "                  Welcome Admin                     " << endl;
            cout << "-------------------------------------------------" << endl;
            cout << endl;


            check = 4;
        }
        else {
            cout << "-------------------------------------------------" << endl;
            cout << "                  Wrong password                      " << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "1. Try again" << endl;
            cout << "2. Return to login page" << endl;
            cin >> choice;
            if (choice == 1) {
                goto adminagain;
            }
            else if (choice == 2) {
                system("cls");
                goto loginagain;
            }

        }
        return check;
    }


    else if (choice == 2) {
        string usernameInput, passwordInput;

    loginagain2:
        cout << "Please enter your username: ";
        cin >> usernameInput;
        cout << "Please enter your password: ";
        cin >> passwordInput;
        cin.ignore();
        for (int j = 0; j < 100; j++) {
            if (usernameInput == passenger[j].username && passwordInput == passenger[j].password) {
                pidcheck = j;
                check = 2;
                break;
            }
        }

        if (check == 1) {
            int choose;
            cout << "-------------------------------------------------" << endl;
            cout << "  Invalid username or password.Please try again.  " << endl;
            cout << "-------------------------------------------------" << endl;

        tryagain:
            cout << "1. Try again" << endl;
            cout << "2. Return to Mainmenu " << endl;
            cout << "Your choice : ";
            cin >> choose;
            if (choose == 1) {
                goto loginagain2;
            }
            else if (choose == 2) {
                system("cls");
                return check;

            }
            else
                cout << "-------------------------------------------------" << endl;
            cout << "                  Invalid option                      " << endl;
            cout << "-------------------------------------------------" << endl;

            goto tryagain;
        }

    }
    else if (choice == 3) {
        check = 3;
    }
    else {
        cout << "-------------------------------------------------" << endl;
        cout << "                  Invalid option                      " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Please select 1 for Admin , 2 for Passenger or 3 for Go to the Mainmenu" << endl;
        goto loginagain;
    }
    return check;

}
void addflight(flightinfo flights[], int& numflights)
{
    int flight;
    if (numflights >= Maxflights)
    {
        cout << "-------------------------------------------------" << endl;
        cout << "           Max number of flights reached              " << endl;
        cout << "-------------------------------------------------" << endl;
        return;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
again:
    cout << "Enter flight number you want to add: ";
    cin >> flight;
    for (int q = 0; q < 100; q++) {
        if (flights[q].flightNum == flight) {
            cout << "---------------------------------------------------" << endl;
            cout << "This flight number already exist , please try again        " << endl;
            cout << "---------------------------------------------------" << endl;
            goto again;
            break;
        }


    }
    flights[numflights].flightNum = flight;
    cout << "Enter number of seats: ";
    cin >> flights[numflights].NumOfSeats;
    cin.ignore();

    cout << "Enter flight date (DD/MM/YYYY): ";
    getline(cin, flights[numflights].date);

    cout << "Enter departure city: ";
    getline(cin, flights[numflights].dep.city);

    cout << "Enter departure time (HH:MM): ";
    getline(cin, flights[numflights].dep.time);

    cout << "Enter arrival city: ";
    getline(cin, flights[numflights].arr.city);

    cout << "Enter arrival time (HH:MM): ";
    getline(cin, flights[numflights].arr.time);
    numflights++;
    system("cls");
    cout << "-------------------------------------------------" << endl;
    cout << "         Flight added successfully.    " << endl;
    cout << "-------------------------------------------------" << endl;

}
int display(flightinfo flights[], int numflights) {
    int check = 0;
    if (numflights == 0) {
        cout << "-------------------------------------------------                              " << endl;
        cout << "              NO AVALIABLE FLIGHTS                                                " << endl;
        cout << "-------------------------------------------------                              " << endl;

        check = 1;
        return check;
    }
    system("cls");
    cout << "-------------------------------------------------                              " << endl;
    cout << "               Avaliable Flights                                 " << endl;
    cout << "-------------------------------------------------                              " << endl;

    for (int i = 0; i < numflights; ++i) {
        if (flights[i].flightNum == 0) {
            continue;
        }
        cout << "flight number : " << flights[i].flightNum << endl;
        cout << "number of seats : " << flights[i].NumOfSeats << endl;
        cout << "flight date : " << flights[i].date << endl;
        cout << "departure city : " << flights[i].dep.city << endl;
        cout << "departure time : " << flights[i].dep.time << endl;
        cout << "arrival city : " << flights[i].arr.city << endl;
        cout << "arrival time : " << flights[i].arr.time << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
    }
    return 0;

}
void  edit(flightinfo flights[]) {

again:
    cout << "Enter the number of the flight you want to edit : ";
    bool check = false;
    int editNum;
    cin >> editNum;

    int k = 0; // 3shan negeb index el flight
    for (int j = 0; j < 100; j++) {
        if (editNum != flights[j].flightNum) {
            /*  cout << "This flight number does not exist" << endl;
              cout << "   TRY AGAIN  :" << endl;
              cout << "------------------------------------------------------------------------------------------------------------------------ ";*/
            check = false;
        }
        else if (editNum == flights[j].flightNum) {
            system("cls");
            cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;

            cout << "1.number of seats: " << flights[j].NumOfSeats << endl;
            cout << "2.flight date: " << flights[j].date << endl;
            cout << "3.departure city: " << flights[j].dep.city << endl;
            cout << "4.departure time: " << flights[j].dep.time << endl;
            cout << "5.arrival city: " << flights[j].arr.city << endl;
            cout << "6.arrival time: " << flights[j].arr.time << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
            k = j; // hena kda bzabt ba2et line 77
            check = true;
            break;
        }
        // cin >> editNum;
    }
    if (check == false) {
        cout << "------------------------------------------- " << endl;
        cout << "    This flight number does not exist     " << endl;
        cout << "                 TRY AGAIN               " << endl;
        cout << "------------------------------------------- " << endl;
        goto again;
    }
    int editOne;
    char choice;
    do
    {
    there:
        cout << "which number do you want to edit ? " << endl;
        cin >> editOne;
        switch (editOne) {

        case 1:
            cout << "Enter new number of seats :";
            cin >> flights[k].NumOfSeats;
            break;

        case 2:
            cout << "Enter new date :";
            cin >> flights[k].date;
            break;

        case 3:
            cout << "Enter new departure city :";
            cin >> flights[k].dep.city;
            break;

        case 4:
            cout << "Enter new departure time :";
            cin >> flights[k].dep.time;
            break;

        case 5:
            cout << "Enter new arrival city : ";
            cin >> flights[k].arr.city;
            break;

        case 6:
            cout << "Enter new arrival time :";
            cin >> flights[k].arr.time;
            break;


        default:

            cout << "-------------------------------" << endl;
            cout << "         Invalid Choice             " << endl;
            cout << "-------------------------------" << endl;

            goto there;
        }
        cout << "do you want to edit something else? (y/n) ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    system("cls");

}
void deleteFlight(flightinfo flights[], int& numFlights) {
    int Delete;
    bool check = false;
again:
    cout << "Enter the flight number you want to delete: ";
    cin >> Delete;
    int i;
    for (i = 0; i < numFlights; i++) {
        if (flights[i].flightNum == Delete) {

            for (int j = i; j < numFlights - 1; j++) {

                flights[j] = flights[j + 1];
            }
            numFlights--; // decrease the number of flights
            system("cls");
            cout << "-------------------------------------------------" << endl;
            cout << "          Flight " << Delete << " deleted.             " << endl;
            cout << "-------------------------------------------------" << endl;
            check = true;
            return;
        }
    }
    // if the flight number doesn't exist
    if (check == false) {
        cout << "-------------------------------------------------" << endl;
        cout << "         Flight " << Delete << " not found.             " << endl;
        cout << "-------------------------------------------------" << endl;
        int choose;
    tryag:
        cout << "1. Try again" << endl;
        cout << "2. Return to admin's menu" << endl;
        cout << "Your choice : ";
        cin >> choose;
        if (choose == 1) {
            goto again;
        }
        else if (choose == 2) {
            system("cls");
            return;
        }
        else {
            cout << "-------------------------------------------------" << endl;
            cout << "                  Invalid Option              " << endl;
            cout << "-------------------------------------------------" << endl;
            goto tryag;

        }
    }

}
void searchavailablelfights(int NumOfFlights)
{
    string city;
    char choiceofcity = 'y';
    bool found;
    char choice;

    do
    {
        found = false;
        cout << "Enter The Destined City: " << endl;
        //cin.ignore();
        getline(cin, city);

        for (int i = 0; i < NumOfFlights; i++)
        {
            if (city == flights[i].arr.city)
            {
                cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
                cout << "Flight number: " << flights[i].flightNum << endl;
                cout << "Number of seats: " << flights[i].NumOfSeats << endl;
                cout << "Flight date: " << flights[i].date << endl;
                cout << "Departure city: " << flights[i].dep.city << endl;
                cout << "Departure time: " << flights[i].dep.time << endl;
                cout << "Arrival city: " << flights[i].arr.city << endl;
                cout << "Arrival time: " << flights[i].arr.time << endl;
                found = true;


            }

        }
        cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
        if (found == false)
        {
            cout << "-------------------------------------------------" << endl;
            cout << "          There is no flight to " << city << endl;
            cout << "-------------------------------------------------" << endl;

        }

        cout << "Do you want to try another city? (y/n)" << endl;
        cin >> choiceofcity;
        cin.ignore();

    } while (choiceofcity == 'y' || choiceofcity == 'Y');


    system("cls");
}
void addreservation(passengerinfo passenger[], int NumOfflights, int pidcheck, int& ticketnum)
{
    int inputId;
    char option;
    char addchoice;
    int flightnum;


    do
    {
    jump2:
        cout << "Enter flight number you want to book:\n";
        cin >> flightnum;

        bool found = false;



        for (int i = 0; i < NumOfflights; i++)
        {
            if (flightnum == flights[i].flightNum)
            {
                if (flights[i].NumOfSeats > 0)
                {

                    passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].ticketNum = ticketnum + 1;
                    passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].reservationDate = flights[i].date;
                    passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].flightNum = flights[i].flightNum;
                    passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].dep.city = flights[i].dep.city;
                    passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].dep.time = flights[i].dep.time;
                    passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].arr.city = flights[i].arr.city;
                    passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].arr.time = flights[i].arr.time;



                    passenger[pidcheck].numOftickets++;

                    flights[i].NumOfSeats--;
                    cout << "-------------------------------------------------" << endl;
                    cout << "              Reservation successful!                   " << endl;
                    cout << "-------------------------------------------------" << endl;

                    cout << "Ticket number: " << passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].ticketNum << endl;
                    cout << "Passenger name: " << passenger[pidcheck].fullname << endl;
                    cout << "Flight number: " << passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].flightNum << endl;
                    cout << "Flight date: " << passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].reservationDate << endl;
                    cout << "Departure city: " << passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].dep.city << endl;
                    cout << "Departure time: " << passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].dep.time << endl;
                    cout << "Arrival city: " << passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].arr.city << endl;
                    cout << "Arrival time: " << passenger[pidcheck].tick[passenger[pidcheck].ticketIndex].arr.time << endl;
                    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
                    passenger[pidcheck].ticketIndex++;
                    ticketnum++;
                    found = true;

                    break;

                }
                else
                {
                    cout << "No avaliable seats.\n";
                    found = true;
                    break;
                }
            }
        }

        if (found == false)
        {
            cout << "-------------------------------------------------" << endl;
            cout << "          Flight number is not avaliable              " << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "Do you want to try again?(y/n)";
            cin >> option;
            if (option == 'y' || option == 'Y')
                goto jump2; //go to line 143
            // mkansh feh else if fa kan mafesh flights binzl 3le you want another reservation
            else if (option == 'n' || option == 'N') {
                system("cls");
                return;

            }

        }
        cout << "Do you want to add another reservation?(y/n)\n";
        cin >> addchoice;
    } while (addchoice == 'y' || addchoice == 'Y');
    system("cls");

}
void cancelreservation(passengerinfo passenger[], flightinfo flights[], int pidcheck, int& ticketIndex)
{
again:
    int cancel;
    bool check = false;
    cout << "Enter the ticket number you want to cancel : ";
    cin >> cancel;

    for (int i = 0; i < passenger[pidcheck].numOftickets; i++) {

        if (passenger[pidcheck].tick[i].ticketNum == cancel) {
            for (int q = 0; q < 100; q++) {
                if (passenger[pidcheck].tick[i].flightNum == flights[q].flightNum) {
                    flights[q].NumOfSeats++;
                    break;
                }
            }

            for (int j = i; j < passenger[pidcheck].numOftickets - 1; j++) {

                passenger[pidcheck].tick[j] = passenger[pidcheck].tick[j + 1];
            }
            passenger[pidcheck].numOftickets--;// decrease the number of tickets
            passenger[pidcheck].ticketIndex--;
            system("cls");
            cout << "-------------------------------------------------" << endl;
            cout << "         Ticket " << cancel << " cancelled.                 " << endl;
            cout << "-------------------------------------------------" << endl;
            check = true;

            return;


        }

    }
    // if the ticket number doesn't exist
    if (check == false) {
        cout << "-------------------------------------------------" << endl;
        cout << "         Ticket " << cancel << " not found.                 " << endl;
        cout << "-------------------------------------------------" << endl;
        int choose;
    againtry:
        cout << "1. Try again" << endl;
        cout << "2. Return to passenger's menu" << endl;
        cout << "Your choice : ";
        cin >> choose;
        if (choose == 1) {
            goto again;
        }
        else if (choose == 2) {
            system("cls");
            return;

        }
        else {
            cout << "-------------------------------------------------" << endl;
            cout << "                  Invalid Option                 " << endl;
            cout << "-------------------------------------------------" << endl;
            goto againtry;
        }
    }
}
bool reservelog(passengerinfo passenger[], int pidcheck)
{
    bool found = true;
    if (passenger[pidcheck].numOftickets == 0) {
        cout << "-------------------------------------------------                              " << endl;
        cout << "               NO RESERVATION FOUND                                                " << endl;
        cout << "-------------------------------------------------                              " << endl;
        found = false;

        return found;
    }



    for (int i = 0; i < passenger[pidcheck].numOftickets; i++) {
        if (passenger[pidcheck].tick[i].ticketNum != 0) {
            cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
            cout << endl;
            cout << "Ticket number: " << passenger[pidcheck].tick[i].ticketNum << endl;
            cout << "Passenger name: " << passenger[pidcheck].fullname << endl;
            cout << "Flight number: " << passenger[pidcheck].tick[i].flightNum << endl;
            cout << "Flight Date : " << passenger[pidcheck].tick[i].reservationDate << endl;
            cout << "Departure city: " << passenger[pidcheck].tick[i].dep.city << endl;
            cout << "Departure time: " << passenger[pidcheck].tick[i].dep.time << endl;
            cout << "Arrival city: " << passenger[pidcheck].tick[i].arr.city << endl;
            cout << "Arrival time: " << passenger[pidcheck].tick[i].arr.time << endl;

            cout << endl;
        }

    }
    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
    return found;
}
void modifyticket(passengerinfo passenger[], flightinfo flights[], int NumOfflights, int pidcheck) {
    int tick = 0;
    bool flight = 0;
    int ticketNum;

    int choose;
    int j = 0;


agg:
    cout << "Enter the ticket number you want to modify: ";
    cin >> ticketNum;

    for (int k = 0; k < passenger[pidcheck].numOftickets; k++) {
        if (passenger[pidcheck].tick[k].ticketNum == ticketNum) {
            system("cls");
            j = k;
            tick = 1;
            for (int i = 0; i < NumOfflights; i++) {
                if (passenger[pidcheck].tick[j].arr.city == flights[i].arr.city && passenger[pidcheck].tick[j].dep.city == flights[i].dep.city && passenger[pidcheck].tick[j].reservationDate != flights[i].date) {
                    cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
                    cout << "Flight number: " << flights[i].flightNum << endl;
                    cout << "Flight date: " << flights[i].date << endl;
                    cout << "Departure city: " << flights[i].dep.city << endl;
                    cout << "Departure time: " << flights[i].dep.time << endl;
                    cout << "Arrival city: " << flights[i].arr.city << endl;
                    cout << "Arrival time: " << flights[i].arr.time << endl;
                    cout << endl;
                    tick = 2;
                }
            }
            cout << "------------------------------------------------------------------------------------------------------------------------ " << endl;
        }
    }

    if (tick == 0) {
        cout << "-------------------------------------------------" << endl;
        cout << "  There is no ticket with the ticket number: " << ticketNum << endl;
        cout << "          Ticket number does not exist              " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1. Try again" << endl;
        cout << "2. return to the passenger's menu" << endl;
        int cho;
        cin >> cho;
        if (cho == 1) {
            goto agg;
        }
        else {
            system("cls");
            return;
        }
    }

    else if (tick == 1) {
        cout << "-------------------------------------------------" << endl;
        cout << "  There is no other timings for this destination     " << endl;
        cout << "-------------------------------------------------" << endl;

        return;
    }
    else  if (tick == 2) {
        for (int l = 0; l < NumOfflights; l++) {
            if (passenger[pidcheck].tick[j].flightNum == flights[l].flightNum) {
                flights[l].NumOfSeats++;
                break;
            }
        }
    tryag:

        cout << "Choose the flight you want to change to: " << endl;
        cin >> choose;

        for (int m = 0; m < NumOfflights; m++) {
            if (passenger[pidcheck].tick[j].arr.city == flights[m].arr.city && passenger[pidcheck].tick[j].dep.city == flights[m].dep.city && passenger[pidcheck].tick[j].reservationDate != flights[m].date && choose == flights[m].flightNum) {
                flight = 1;
                if (flights[m].NumOfSeats > 0) {
                    flights[m].NumOfSeats--;
                    passenger[pidcheck].tick[j].flightNum = flights[m].flightNum;
                    passenger[pidcheck].tick[j].reservationDate = flights[m].date;
                    system("cls");
                    cout << "-------------------------------------------------" << endl;
                    cout << "           Ticket modified successfully!           " << endl;
                    cout << "-------------------------------------------------" << endl;

                }
                else {
                    cout << "-------------------------------------------------" << endl;
                    cout << "        The selected flight is fully booked.               " << endl;
                    cout << "-------------------------------------------------" << endl;

                }
                break;
            }

        }
    }

    if (flight == 1) {

        return;

    }
    else if (flight == 0) {
        cout << "-------------------------------------------------" << endl;
        cout << "            flight number does not exist          " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1. Try again" << endl;
        cout << "2. return to the passenger's menu" << endl;
        int cho;
        cin >> cho;
        if (cho == 1) {
            goto tryag;
        }
        else {
            system("cls");
            return;
        }
    }
}

void mainmenu() {
    passengerinfo;

    int option;
    int check = 1;

    cout << "                              -------------------------------------------------                              " << endl;
    cout << "                                   Welcome to our Arline Reservasion System                                  " << endl;
    cout << "                              -------------------------------------------------                              " << endl;
main:
    cout << "-------------------------------------------------" << endl;
    cout << "              Please select an option             " << endl;
    cout << "-------------------------------------------------" << endl;
again:
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your selection : ";
    cin >> option;
    switch (option) {


    case 1:
        signup();
        goto main;
        break;


    case 2:
        check = login(passenger, Pidcheck);

        if (check == 1) {
            cout << "-------------------------------------------------" << endl;
            cout << "  Invalid username or password.Please try again.    " << endl;
            cout << "-------------------------------------------------" << endl;


            goto main;
        }
        else if (check == 2) {
            int passchoice;
            bool reslog = false;
            system("cls");
            cout << endl << "Login successful!" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "              Welcome " << passenger[Pidcheck].fullname << endl;
            cout << "----------------------------------------------" << endl;
        passn:
            cout << endl;
            cout << "select one of the options:               " << endl;
            cout << "--------------------------" << endl;
            cout << "1. Add reservation\n";
            cout << "2. Cancel reservation\n";
            cout << "3. Modify reservation\n";
            cout << "4. Search available flights\n";
            cout << "5. Show reservation log\n";
            cout << "6. Go back to the Mainmenu\n";
            cout << "Your choice : ";
            cin >> passchoice;
            cin.ignore();
            int inputId;
            switch (passchoice)
            {
            case 1:

                display(flights, numflights);
                addreservation(passenger, numflights, Pidcheck, ticketnum);
                goto passn;
                break;

            case 2:

                reslog = reservelog(passenger, Pidcheck);

                if (reslog == false) {
                    goto passn;
                }
                cancelreservation(passenger, flights, Pidcheck, ticketnum);
                goto passn;
                break;
            case 3:
                reslog = reservelog(passenger, Pidcheck);
                if (reslog == false) {
                    goto passn;
                }
                modifyticket(passenger, flights, numflights, Pidcheck);
                goto passn;
                break;
            case 4:
                searchavailablelfights(numflights);
                goto passn;
                break;
            case 5:

                reslog = reservelog(passenger, Pidcheck);
                goto passn;
                break;
            case 6:
                goto main;
                break;
            default:
                cout << "-------------------------------------------------" << endl;
                cout << "     Option is not available, please try again          " << endl;
                cout << "-------------------------------------------------" << endl;

                goto passn;
                break;
            }
        }
        else if (check == 3) {

            goto main;
        }
        else if (check == 4) {

            int can;
            int choice;
            char cho;
        adminfun:

            cout << "Please select one of the options : " << endl;
            cout << "--------------------------------" << endl;
            cout << "1. Add flight" << endl;
            cout << "2. Edit flight" << endl;
            cout << "3. Display the avaliable flights" << endl;
            cout << "4. Delete flight" << endl;
            cout << "5. Go back to the Mainmenu" << endl;
            cout << "Enter your selection : ";
            cin >> choice;

            switch (choice)
            {


            case 1:
                do {
                    addflight(flights, numflights);
                    cout << "Do you want to add a new flight? (y/n)\n";
                    cin >> cho;
                    cin.ignore();
                } while (cho == 'y' || cho == 'Y');
                goto adminfun;
                break;



            case 2:

                can = display(flights, numflights);
                if (can == 1) {
                    goto adminfun;
                }
                edit(flights);
                goto adminfun;
                break;


            case 3:
                can = display(flights, numflights);
                if (can == 1) {
                    goto adminfun;
                }
                goto adminfun;
                break;


            case 4:
                can = display(flights, numflights);
                if (can == 1) {
                    goto adminfun;
                }
                deleteFlight(flights, numflights);

                goto adminfun;



            case 5:
                system("cls");
                goto main;
                break;

            default:
                system("cls");
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "                               Invalid option                                " << endl;
                cout << " Please select 1 for Add, 2 for Edit, 3 to Display or 4 to go the Mainmenu" << endl;
                cout << "------------------------------------------------------------------------------" << endl;

                goto adminfun;
                break;


                srand(time(NULL));
            }

        }


    case 3:
        cout << "                              -------------------------------------------------                              " << endl;
        cout << "                                    thank you for using our airline system                               " << endl;
        cout << "                              -------------------------------------------------                              " << endl;
        break;



    default:
        cout << "-------------------------------------------------" << endl;
        cout << "                  Invalid option                      " << endl;
        cout << "     Please select 1 for Signup or 2 for Login.     " << endl;
        cout << "-------------------------------------------------" << endl;

        goto again;
        break;

    }
}


int main() {
    // Hard Coded Flights
    flights[0].flightNum = 1;
    flights[0].NumOfSeats = 100;
    flights[0].date = "10/10/2023";
    flights[0].dep.city = "Cairo";
    flights[0].dep.time = "00:00";
    flights[0].arr.city = "Dubai";
    flights[0].arr.time = "4:00";


    flights[1].flightNum = 2;
    flights[1].NumOfSeats = 100;
    flights[1].date = "11/12/2023";
    flights[1].dep.city = "Cairo";
    flights[1].dep.time = "13:00";
    flights[1].arr.city = "Tokyo";
    flights[1].arr.time = "22:00";

    flights[2].flightNum = 3;
    flights[2].NumOfSeats = 100;
    flights[2].date = "14/12/2023";
    flights[2].dep.city = "Cairo";
    flights[2].dep.time = "13:00";
    flights[2].arr.city = "Tokyo";
    flights[2].arr.time = "22:00";


    flights[3].flightNum = 4;
    flights[3].NumOfSeats = 100;
    flights[3].date = "21/12/2023";
    flights[3].dep.city = "Cairo";
    flights[3].dep.time = "13:00";
    flights[3].arr.city = "Tokyo";
    flights[3].arr.time = "22:00";

    mainmenu();

    return 0;
}