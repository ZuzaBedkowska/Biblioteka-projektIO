#include "MainController.h"

#include <iostream>

using namespace std;

MainController::MainController(vector < User > userDatabase, vector < Librarian > librarianDatabase, vector < Book > bookDatabase) {
    this->userDatabase = userDatabase;
    this->librarianDatabase = librarianDatabase;
    this->bookDatabase = bookDatabase;
    //this->reservationDatabase = reservationDatabase;
}

void MainController::start() {
    system("cls");
    cout << "Wybierz jedna z dostepnych opcji wpisujac jej numer:\n";
    cout << "\t1. Zaloguj jako pracownik\n";
    cout << "\t2. Zaloguj jako uzytkownik\n";
    cout << "\t3. Korzystaj bez zalogowania\n";
    cout << "\t4. Zarejestruj\nTwoj wybor: ";
    int choice = 0;
    cin >> choice;
    switch (choice) {
    case 1: {
        loggedLibrarian = librarianLogin();
        loggedLibrarian.setIsLogged(true); //zalogowany librarian a nie user
        loggedUser.setIsLogged(false);
        librarianMenu();
        break;
    }
    case 2: {
        loggedUser = userLogin();
        loggedUser.setIsLogged(true); //zalogowany user a nie librarian
        loggedLibrarian.setIsLogged(false);
        userMenu();
        break;
    }
    case 3: {
        string name = "Niezalogowany";
        loggedUser.setIsLogged(false); //ani librarian ani user niezalogowani
        loggedLibrarian.setIsLogged(false);
        loggedUser.setName(name);
        userMenu();
        break;
    }
    case 4: {
        userRegistration();
        start();
        break;
    }
    default: {
        cout << "Wybierz wlasciwa opcje!\n";
        start();
        system("pause");
        break;
    }
    }
}

void MainController::bookReservation() {
    cout << "\nAby wypozyczyc ksiazke, wpisz W\nAby wrocic do menu, wpisz M\nTwoj wybor: ";
    char choice;
    cin >> choice;
    switch (choice) {
    case 'W': {
        cout << "Podaj numer ksiazki z listy: ";
        int bookNumber;
        cin >> bookNumber;
        while (bookNumber > bookDatabase.size() || bookNumber < 0) {
            cout << "Wpisano niewlasciwy numer!\nPodan numer jeszcze raz: ";
            cin >> bookNumber;
        }

        bookDatabase[bookNumber].createItem(); //robocze robienie wolnego itemu
        if ((bookDatabase[bookNumber].isAnyItemFree()) && (loggedUser.userTest())) {
            loggedUser.addReservation(bookDatabase[bookNumber]);
        }
        else if (!loggedUser.userTest()) {
            cout << "Wypozyczenie niemozliwe\nSprawdz czy nie przekroczono limitu wypozyczen (5 pozycji), lub zaplac nalozone kary i oddaj przetrzymane ksiazki.\n";
        }
        else {
            cout << "Brak wolnego egzemplarza podanej ksiazki";
            bookReservation();
        }
        system("pause");
        userMenu();
        break;
    }
    case 'M': {
        userMenu();
        return;
    }
    }
}

void MainController::getLogin(string& login) {
    cout << "Login: ";
    cin >> login;
}

void MainController::getPassword(string& login, string& password) {
    cout << "Login: " << login << "\nLogin poprawny!\nHaslo: ";
    cin >> password;
}

void MainController::printBookDatabase() {
    system("cls");
    cout << "Baza Ksiazek:\n";
    int number = 1;
    for (auto i : bookDatabase) {
        cout << number << ". ";
        i.printBook();
        number++;
    }
    if (loggedUser.getIsLogged()) //jezeli user zalogowany (librarian nie jest zalogowany)
    {
        bookReservation();
    }
    else if (loggedLibrarian.getIsLogged()) //jesli to librarian jest zalogowany a user nie
    {
        system("pause");
        librarianMenu();
    }
    else if ((!loggedLibrarian.getIsLogged()) && (!loggedUser.getIsLogged())) //jesli nikt nie jest zalogowany
    {
        cout << "\nAby wypozyczyc ksiazke, musisz sie zalogowac!\n";
        system("pause");
        userMenu();
    }
}

void MainController::bookSearch() {
    system("cls");
    cout << "Wyszukiwanie ksiazki\nPodaj wyszukiwana fraze: ";
    string phrase;
    cin >> phrase;
    cout << "\nTytuly zawierajace podana fraze:\n";
    vector < Book > foundTitles;
    vector < Book > foundAuthors;
    vector < Book > allFound;
    for (auto& i : bookDatabase) {
        if (i.getTitle().find(phrase) < i.getTitle().size()) {
            foundTitles.push_back(i);
            allFound.push_back(i);
        }
        for (auto& j : i.getAuthors()) {
            if (j.find(phrase) < j.size()) {
                foundAuthors.push_back(i);
                allFound.push_back(i);
                break;
            }
        }

    }
    int number = 1;
    if (foundTitles.size() == 0) {
        cout << "Brak\n";
    }
    else {
        for (auto i : foundTitles) {
            cout << number << ". ";
            i.printBook();
            number++;
        }
    }
    cout << "\nNazwiska autorow zawierajace podana fraze:\n";
    if (foundAuthors.size() == 0) {
        cout << "Brak\n";
    }
    else {
        for (auto i : foundAuthors) {
            cout << number << ". ";
            i.printBook();
            number++;
        }
    }
    if (loggedUser.getIsLogged()) {
        bookReservation();
    }
    else {
        cout << "\nAby wypozyczyc ksiazke, musisz sie zalogowac!\n";
        system("pause");
        userMenu();
    }
}

void MainController::userMenu() {
    system("cls");
    cout << "Witaj " << loggedUser.getName() << "!\nWybierz jedna z dostepnych opcji wpisujac jej numer:\n";
    cout << "\t1. Przegladaj ksiazki\n";
    cout << "\t2. Wyszukaj ksiazke\n";
    cout << "\t3. Sprawdz stan konta\n";
    cout << "\t4. Wroc do logowania\n";
    cout << "Twoj wybor: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        printBookDatabase();
        break;
    }
    case 2: {
        bookSearch();
        break;
    }
    case 3: {
        loggedUser.printUser();
        loggedUser.printBooks();
        system("pause");
        userMenu();
        break;
    }
    case 4: {
        start();
        break;
    }
    default: {
        cout << "Wybierz wlasciwa opcje!\n";
        system("pause");
        userMenu();
        return;
    }
    }
}

User MainController::userLogin() {
    system("cls");
    string login;
    string pass;
    cout << "Logowanie\n\n";
    getLogin(login); //podawanie loginu
    bool loginFound = false; //jezeli login znaleziono
    while (!loginFound) //dopoki loginu nie znaleziono
    {
        for (auto i : userDatabase) //wyszukanie loginu w bazie
        {
            if (i.getName() == login) //jezeli login znaleziony
            {
                loginFound = true;
                cout << "Login poprawny! \nHaslo: ";
                cin >> pass;
                while (pass != i.getPassword()) {
                    cout << "Haslo niepoprawne!\nSprobuj ponownie\n";
                    system("pause");
                    system("cls");
                    cout << "Logowanie\n\n";
                    getPassword(login, pass);
                }
                if (i.getPassword() == pass) {
                    cout << "Logowanie poprawne!\n";
                    system("pause");
                    system("cls");
                    return i;
                }
            }
            else {
                cout << "Login niepoprawny! Sprobuj ponownie\n";
                system("pause");
                system("cls");
                cout << "Logowanie\n\n";
                getLogin(login);
            }
        }
    }
}

void MainController::userRegistration() {
    system("cls");
    string login;
    cout << "Rejestracja\n\n";
    getLogin(login);
    bool loginAvailable = true;
    do {
        for (auto i : userDatabase) {
            if (i.getName() == login) //jezeli login zajety
            {
                loginAvailable = false; //login niedostepny
                cout << "Login zajety! wybierz inny!\n";
                system("pause");
                system("cls");
                cout << "Rejestracja\n\n"; //wyswietl wszystko od nowa;
                getLogin(login);
                break;
            }
            loginAvailable = true; //jesli nie wybrejkowalismy sie z petli for wczesniej, to znaczy ze login ok
        }
    } while (!loginAvailable);
    string password;
    cout << "Login poprawny! \nPodaj haslo: ";
    cin >> password;
    bool goodPassword = false;
    while (!goodPassword) {
        if (password.size() > 8) {
            goodPassword = true;
            break;
        }
        else {
            cout << "Haslo za slabe! podaj inne\n";
            system("pause");
            system("cls");
            cout << "Rejestracja\n\n";
            getPassword(login, password);
        }
    }
    Date birthDate;
    cout << "Podaj date urodzenia wpisujac numer dnia, miesiaca i roku\nDzien: ";
    cin >> birthDate.day;
    cout << "Miesiac: ";
    cin >> birthDate.month;
    cout << "Rok: ";
    cin >> birthDate.year;
    while (!birthDate.isTrue()) {
        cout << "Data niepoprawna, Podaj date jeszcze raz!\n";
        system("pause");
        system("cls");
        cout << "Rejestracja\n\nPodaj login :" << login << "\nLogin poprawny.\nPodaj haslo: "; //wyswietl wszystko od nowa;"
        for (auto i : password) {
            cout << "*";
        }
        cout << "\nPodaj date urodzenia wpisujac numer dnia, miesiaca i roku\nDzien: ";
        cin >> birthDate.day;
        cout << "Miesiac: ";
        cin >> birthDate.month;
        cout << "Rok: ";
        cin >> birthDate.year;
    }
    User newUser(login, password, birthDate);
    cout << "Uzytkownik zostal utworzony ";
    userDatabase.push_back(newUser);
    cout << " i dodany do bazy.\nDane uzytkownika:\n";
    newUser.printUser();
    system("pause");
}

Librarian MainController::librarianLogin() {
    system("cls");
    string login;
    string pass;
    cout << "Logowanie\n\n";
    getLogin(login); //podawanie loginu
    bool loginFound = false; //jezeli login znaleziono
    while (!loginFound) //dopoki loginu nie znaleziono
    {
        for (auto i : librarianDatabase) //wyszukanie loginu w bazie
        {
            if (i.getName() == login) //jezeli login znaleziony
            {
                loginFound = true;
                cout << "Login poprawny! \nHaslo: ";
                cin >> pass;
                while (pass != i.getPassword()) {
                    cout << "Haslo niepoprawne!\nSprobuj ponownie\n";
                    system("pause");
                    system("cls");
                    cout << "Logowanie\n\n";
                    getPassword(login, pass);
                }
                if (i.getPassword() == pass) {
                    cout << "Logowanie poprawne!\n";
                    system("pause");
                    system("cls");
                    return i;
                }
            }
            else {
                cout << "Login niepoprawny! Sprobuj ponownie\n";
                system("pause");
                system("cls");
                cout << "Logowanie\n\n";
                getLogin(login);
            }
        }
    }
}

void MainController::librarianMenu() {
    system("cls");
    cout << "Witaj " << loggedLibrarian.getName() << "!\nWybierz jedna z dostepnych opcji wpisujac jej numer:\n";
    cout << "\t1. Przegladaj ksiazki\n";
    cout << "\t2. Wyszukaj ksiazke\n";
    cout << "\t3. Wyloguj\n";
    cout << "\t4. Edytuj uzytkownika\n";
    cout << "\t5. Edytuj ksiazke\n";
    cout << "\t6. Dodaj ksiazke\n";
    cout << "Twoj wybor: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        printBookDatabase();
        break;
    }
    case 2: {
        bookSearch();
        break;
    }
    case 3: {
        loggedLibrarian.setIsLogged(false);
        start();
        break;
    }
    case 4: {
        int switch_case_user_ID = 0, editing_user = 0, editing_ID = 0;
        string new_word = "o", new_password;
        Date data(-1, -1, -1);
        cout << "Wybrano opcje edycji uzytkownika. Podaj ID uzytkownika,\nktorego dane chcesz zmienic.\n";
        cin >> switch_case_user_ID;
        cout << "Wybierz, ktore dane chcesz zmienic. 1 - imie, 2 - ID, 3 - haslo, 4 - data urodzenia.\n";
        cin >> editing_user;
        switch (editing_user) {
        case 1: {
            cout << "Podaj nowe imie.\n";
            cin >> new_word;
            if (new_word.size() < 3) {
                cout << "Wybrane imie jest zbyt krotkie. Prosze sprobowac ponownie.\n";
                break;
            }
            loggedLibrarian.editUser(userDatabase[switch_case_user_ID], new_word, -1, "o", data);
            break;
        }
        case 2: {
            cout << "Podaj nowe ID.\n";
            cin >> editing_ID;
            if (editing_ID < 0) {
                cout << "Wybrane ID jest mniejsze od 0. Prosze sprobowac ponownie.\n";
                break;
            }
            loggedLibrarian.editUser(userDatabase[switch_case_user_ID], "o", editing_ID, "o", data);
            break;
        }
        case 3: {
            cout << "Podaj nowe haslo.\n";
            cin >> new_password;
            if (new_password.size() < 8) {
                cout << "Wybrane haslo jest krotsze niz 8 znakow. Prosze sprobowac ponownie.\n";
                break;
            }
            loggedLibrarian.editUser(userDatabase[switch_case_user_ID], "o", -1, new_password, data);
            break;
        }
        case 4: {
            cout << "Wprowadz nowa date urodzenia w kolejnosci dzien (enter), miesiac (enter), rok (enter).\n";
            int nday, nmonth, nyear;
            cin >> nday;
            if (nday < 0 || nday > 31) {
                cout << "Dzien nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
                break;
            }
            cin >> nmonth;
            if (nmonth < 0 || nmonth > 12) {
                cout << "Miesiac nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
                break;
            }
            cin >> nyear;
            if (nyear < 1900 || nyear > 2022) {
                cout << "Rok nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
                break;
            }
            Date new_date(nday, nmonth, nyear);
            loggedLibrarian.editUser(userDatabase[switch_case_user_ID], "o", -1, "o", new_date);
            break;
        }
        }
        librarianMenu();
        break;
    }

    case 5: {
        int switch_case_book_ID = 0, editing_book = 0, new_int = 0;
        string new_word = "";
        vector < string > new_vector;
        new_vector.clear();
        cout << "Wybrano opcje edycji ksiazki. Podaj ID ksiazki,\nktorej dane chcesz zmienic.\n";
        cin >> switch_case_book_ID;
        cout << "Wybierz, ktore dane chcesz zmienic. 1 - tytul, 2 - ID, 3 - autorzy, 4 - opis.\n";
        cin >> editing_book;
        switch (editing_book) {
        case 1: {
            cout << "Podaj nowy tytul.\n";
            cin.ignore();
            getline(cin, new_word);
            if (new_word.size() < 3) {
                cout << "Wybrany tytul jest zbyt krotki. Prosze sprobowac ponownie.\n";
                break;
            }
            loggedLibrarian.editBook(bookDatabase[switch_case_book_ID], new_word, switch_case_book_ID, bookDatabase[switch_case_book_ID].getAuthors(), bookDatabase[switch_case_book_ID].getDescription());
            break;
        }
        case 2: {
            cout << "Podaj nowe ID.\n";
            cin >> new_int;
            if (new_int < 0) {
                cout << "Wybrane ID jest mniejsze od 0. Prosze sprobowac ponownie.\n";
                break;
            }
            loggedLibrarian.editBook(bookDatabase[switch_case_book_ID], bookDatabase[switch_case_book_ID].getTitle(), new_int, bookDatabase[switch_case_book_ID].getAuthors(), bookDatabase[switch_case_book_ID].getDescription());
            break;
        }
        case 3: {
            cout << "Podaj liczbe nowych autorow.\n";
            cin >> new_int;
            cin.ignore();
            for (int i = 0; i < new_int; i++) {
                cout << "Podaj autora nr " << i + 1 << "\n";
                getline(cin, new_word);
                new_vector.push_back(new_word);
                cout << new_vector[0];
            }
            loggedLibrarian.editBook(bookDatabase[switch_case_book_ID], bookDatabase[switch_case_book_ID].getTitle(), switch_case_book_ID, new_vector, bookDatabase[switch_case_book_ID].getDescription());
            break;
        }
        case 4: {
            cout << "Podaj liczbe nowych opisow.\n";
            cin >> new_int;
            cin.ignore();
            for (int i = 0; i < new_int; i++) {
                cout << "Podaj opis nr " << i + 1 << "\n";
                getline(cin, new_word);
                new_vector.push_back(new_word);
            }
            loggedLibrarian.editBook(bookDatabase[switch_case_book_ID], bookDatabase[switch_case_book_ID].getTitle(), switch_case_book_ID, bookDatabase[switch_case_book_ID].getAuthors(), new_vector);
            break;
        }
        }
        librarianMenu();
        break;
    }
    case 6: {
        int tempInt;
        string title, tempString;
        vector<string> description, author;

        cout << "Podaj tytul \n";
        cin.ignore();
        getline(cin, title);

        cout << "Podaj ilosc autorow \n";
        cin >> tempInt;
        cin.ignore();
        for (int i = 0; i < tempInt; i++) {
            cout << "Podaj autora nr " << i + 1 << "\n";
            getline(cin, tempString);
            author.push_back(tempString);
        }

        cout << "Podaj ilosc opisow \n";
        cin >> tempInt;
        cin.ignore();
        for (int i = 0; i < tempInt; i++) {
            cout << "Podaj opis nr " << i + 1 << "\n";
            getline(cin, tempString);
            description.push_back(tempString);
        }

        loggedLibrarian.addBook(bookDatabase, Book(title, description, author));

        librarianMenu();
        break;
    }

  default: {
      cout << "Wybierz wlasciwa opcje!\n";
      system("pause");
      librarianMenu();
      return;
  }
}
}