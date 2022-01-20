#include "MainController.h"

#include <iostream>
#include <Windows.h>

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
    char choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case '1': {
        loggedLibrarian = librarianLogin();
        loggedLibrarian.setIsLogged(true); //zalogowany librarian a nie user
        loggedUser.setIsLogged(false);
        librarianMenu();
        break;
    }
    case '2': {
        loggedUser = userLogin();
        loggedUser.setIsLogged(true); //zalogowany user a nie librarian
        loggedLibrarian.setIsLogged(false);
        userMenu();
        break;
    }
    case '3': {
        string name = "Niezalogowany";
        loggedUser.setIsLogged(false); //ani librarian ani user niezalogowani
        loggedLibrarian.setIsLogged(false);
        loggedUser.setName(name);
        userMenu();
        break;
    }
    case '4': {
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
    switch (toupper(choice)) {
    case 'W': {
        cout << "Podaj numer ksiazki z listy: ";
        int bookNumber;
        cin >> bookNumber;
        while (bookNumber > bookDatabase.size() || bookNumber < 0) {
            cout << "Wpisano niewlasciwy numer!\nPodan numer jeszcze raz: ";
            cin >> bookNumber;
        }
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
    default:{
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
        editBook();
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
    cout << "\t3. Przegladaj uzytkownikow\n";
    cout << "\t4. Dodaj uzytkownika\n";
    cout << "\t5. Dodaj ksiazke\n";
    cout << "\t6. Wyloguj\n";
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
        loggedLibrarian.printUsers(userDatabase);
        editUser();
        librarianMenu();
        break;
    }
    case 4: {
        addUser();
        librarianMenu();
        break;
    }
    case 5: {
        int tempInt;
        string title, tempString;
        vector<string> description, author;

        cout << "Podaj tytul:  ";
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
    case 6: {
        loggedLibrarian.setIsLogged(false);
        start();
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

void MainController::editBook() {
    cout << "\nAby edytowac ksiazke, wpisz E\nAby usunac ksiazke, wpisz U\nAby wrocic do menu, wpisz M\nTwoj wybor: ";
    char choice;
    cin >> choice;
    cin.sync();
    switch (toupper(choice)) {
    default: {
        librarianMenu();
        break;
    }
    case 'E': {
        cout << "Podaj numer ksiazki z listy: ";
        int bookNumber;
        cin >> bookNumber;
        while (bookNumber > bookDatabase.size() || bookNumber < 0) {
            cout << "Wpisano niewlasciwy numer!\nPodaj numer jeszcze raz: ";
            cin >> bookNumber;
        }

        bookNumber--; //aby index tablicy zgadzal sie z numerami na liscie

        int editing_book = 0, new_int = 0;
        string new_word = "";
        vector < string > new_vector;
        new_vector.clear();
        cout << "Wybrana ksiazka to:\n";
        bookDatabase[bookNumber].printBook();
        cout << "Wybierz, ktore dane chcesz zmienic. 1 - tytul, 2 - ID, 3 - autorzy, 4 - opis.\n";
        cin >> editing_book;
        switch (editing_book) {
        case 1: {
            cout << "Podaj nowy tytul.\n";
            cin.ignore();
            getline(cin, new_word);
            if (new_word.size() < 3) {
                cout << "Wybrany tytul jest zbyt krotki. Prosze sprobowac ponownie.\n";
                system("pause");
                break;
            }
            bool found = false;
            for (auto i : bookDatabase)
            {

                if (i.getTitle() == new_word)
                {
                    found = true;
                }
            }
            if (found)
            {
                cout << "Wybrana pozycja znajduje sie juz w bazie. Prosze sprobowac ponownie.\n";
                system("pause");
                break;
            }
            loggedLibrarian.editBook(bookDatabase[bookNumber], new_word, bookDatabase[bookNumber].getId(), bookDatabase[bookNumber].getAuthors(), bookDatabase[bookNumber].getDescription());
            break;
        }
        case 2: {
            cout << "Podaj nowe ID.\n";
            cin >> new_int;
            if (new_int < 0) {
                cout << "Wybrane ID jest mniejsze od 0. Prosze sprobowac ponownie.\n";
                system("pause");
                break;
            }
            bool found = false;
            for (auto i : bookDatabase)
            {

                if (i.getId() == new_int)
                {
                    found = true;
                }
            }
            if (found)
            {
                cout << "Ksiazka o wybranym ID znajduje sie juz w bazie. Prosze sprobowac ponownie.\n";
                system("pause");
                break;
            }
            loggedLibrarian.editBook(bookDatabase[bookNumber], bookDatabase[bookNumber].getTitle(), new_int, bookDatabase[bookNumber].getAuthors(), bookDatabase[bookNumber].getDescription());
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
            }
            loggedLibrarian.editBook(bookDatabase[bookNumber], bookDatabase[bookNumber].getTitle(), bookDatabase[bookNumber].getId(), new_vector, bookDatabase[bookNumber].getDescription());
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
            loggedLibrarian.editBook(bookDatabase[bookNumber], bookDatabase[bookNumber].getTitle(), bookDatabase[bookNumber].getId(), bookDatabase[bookNumber].getAuthors(), new_vector);
            break;
        }
        }
        librarianMenu();
        break;
    }
    case 'U': {
        cout << "Podaj numer ksiazki z listy: ";
        int bookNumber;
        cin >> bookNumber;
        while (bookNumber > bookDatabase.size() || bookNumber < 0) {
            cout << "Wpisano niewlasciwy numer!\nPodan numer jeszcze raz: ";
            cin >> bookNumber;
        }

        bookNumber--; //aby index tablicy zgadzal sie z numerami na liscie

        loggedLibrarian.removeBook(bookDatabase, bookNumber);
        cout << "Pomyslnie usunieto ksiazke\n";
        system("pause");
        librarianMenu();
        break;
    }
    case 'M': {
        librarianMenu();
        return;
    }
    }
}

void MainController::editUser() {
    cout << "\nAby edytowac uzytkownika, wpisz E\nAby usunac uzytkownika, wpisz U\nAby dokonac wypozyczenia ksiazki, wpisz B\nAny dokonac zwrotu ksiazki, wpisz R\nAby wrocic do menu, wpisz M\nTwoj wybor: ";
    char choice;
    cin >> choice;
    cin.sync();
    switch (toupper(choice)) {
    case 'E': {
        int switch_case_user_ID = 0, editing_user = 0, editing_ID = 0;
        string new_word = "o", new_password;
        Date data(-1, -1, -1);
        while (switch_case_user_ID < 1 || switch_case_user_ID > userDatabase.size()) {
            cout << "Wybierz uzytkownika,\nktorego dane chcesz zmienic.\n";
            cin >> switch_case_user_ID;
            if ((switch_case_user_ID < 1 || switch_case_user_ID > userDatabase.size()))
                cout << "Brak uzytkownika o tym numerze na liœcie. Prosze sprobowac ponownie\n";
        }
        switch_case_user_ID--;
        cout << "Wybierz, ktore dane chcesz zmienic. 1 - imie, 2 - ID, 3 - haslo, 4 - data urodzenia.\n";
        cin >> editing_user;
        switch (editing_user) {
        case 1: {
            cout << "Podaj nowe imie: ";
            cin >> new_word;
            if (new_word.size() < 3) {
                cout << "Wybrane imie jest zbyt krotkie. Prosze sprobowac ponownie.\n";
                system("pause");
                break;
            }
            bool found = false;
            for (auto i : userDatabase)
            {
                
                if (i.getName() == new_word)
                {
                    found = true;
                }
            }
            if (found)
            {
                cout << "Wybrane imie znajduje sie juz w bazie. Prosze sprobowac ponownie.\n";
                system("pause");
                break;
            }
            loggedLibrarian.editUser(userDatabase[switch_case_user_ID], new_word, -1, "o", data);
            cout << "Pomyslnie edytowano uzytkownika\n";
            system("pause");
            break;
        }
        case 2: {
            cout << "Podaj nowe ID: ";
            cin >> editing_ID;
            if (editing_ID < 0) {
                cout << "Wybrane ID jest mniejsze od 0. Prosze sprobowac ponownie.\n";
                break;
            }
            bool found = false;
            for (auto i : userDatabase)
            {

                if (i.getId() == editing_ID)
                {
                    found = true;
                }
            }
            if (found)
            {
                cout << "Uzytkownik o podanym ID znajduje sie juz w bazie. Prosze sprobowac ponownie.\n";
                system("pause");
                break;
            }
            loggedLibrarian.editUser(userDatabase[switch_case_user_ID], "o", editing_ID, "o", data);
            break;
        }
        case 3: {
            cout << "Podaj nowe haslo: ";
            cin >> new_password;
            if (new_password.size() < 8) {
                cout << "Wybrane haslo jest krotsze niz 8 znakow. Prosze sprobowac ponownie.\n";
                break;
            }
            loggedLibrarian.editUser(userDatabase[switch_case_user_ID], "o", -1, new_password, data);
            break;
        }
        case 4: {
            cout << "Wprowadz nowa date urodzenia wpisujac numer dnia, miesiaca i roku.\n";
            int nday, nmonth, nyear;
            cout << "Dzien: ";
            cin >> nday;
            if (nday < 0 || nday > 31) {
                cout << "Dzien nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
                break;
            }
            cout << "Miesiac: ";
            cin >> nmonth;
            if (nmonth < 0 || nmonth > 12) {
                cout << "Miesiac nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
                break;
            }
            cout << "Rok: ";
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
        break;
    }
    case 'U': {
        cout << "Podaj numer uzytkownika z listy do usuniecia: ";
        int userNumber;
        cin >> userNumber;
        while (userNumber > userDatabase.size() || userNumber < 0) {
            cout << "Wpisano niewlasciwy numer!\nPodan numer jeszcze raz: ";
            cin >> userNumber;
        }

        userNumber--; //aby index tablicy zgadzal sie z numerami na liscie

        loggedLibrarian.removeUser(userDatabase, userNumber);
        cout << "Pomyslnie usunieto uzytkownika\n";
        system("pause");
        librarianMenu();
        break;
    }
    case 'M': {
        librarianMenu();
        break;
    }
    case 'B': {
        bookBorrowment();
        break;
    }
    case 'R': {
        bookReturn();
        break;
    }
    default: {
        librarianMenu();
        break;
    }
    }
}

void MainController::addUser(){
    system("cls");
    cout << "Dodawanie uzytkownika\n";
    int switch_case_user_ID = 0, editing_user = 0, editing_ID = 0;
    string new_word = "o", new_password;
    Date data(-1, -1, -1);
    cout << "Podaj imie: ";
    cin >> new_word;
    if (new_word.size() < 3) {
        cout << "Wybrane imie jest zbyt krotkie. Prosze sprobowac ponownie.\n";
        system("pause");
        librarianMenu();
        return;
    }
    bool found = false;
    for (auto i : userDatabase){
        if (i.getName() == new_word){
            found = true;
        }
    }
    if (found){
        cout << "Wybrane imie znajduje sie juz w bazie. Prosze sprobowac ponownie.\n";
        system("pause");
        librarianMenu();
        return;
    }
    cout << "Podaj haslo: ";
    cin >> new_password;
    if (new_password.size() < 8) {
        cout << "Wybrane haslo jest krotsze niz 8 znakow. Prosze sprobowac ponownie.\n";
        system("pause");
        librarianMenu();
        return;
    }
    cout << "Wprowadz date urodzenia wpisujac numer dnia, miesiaca i roku\n";
    int nday, nmonth, nyear;
    cout << "Dzien: ";
    cin >> nday;
    if (nday < 0 || nday > 31) {
        cout << "Dzien nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
        system("pause");
        librarianMenu();
        return;
    }
    cout << "Miesiac: ";
    cin >> nmonth;
    if (nmonth < 0 || nmonth > 12) {
        cout << "Miesiac nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
        librarianMenu();
        system("pause");
        return;
    }
    cout << "Rok: ";
    cin >> nyear;
    if (nyear < 1900 || nyear > 2022) {
        cout << "Rok nie miesci sie w zakresie. Prosze sprobowac ponownie.\n";
        librarianMenu();
        system("pause");
        return;
    }
    Date new_date(nday, nmonth, nyear);
    User newUser(new_word, new_password, new_date);
    loggedLibrarian.addUser(userDatabase, newUser);
    cout << "Pomyslnie dodano uzytkownika\n";
    newUser.printUser();
    system("pause");
    librarianMenu();
    return;
}

void MainController::bookBorrowment() {
    int switch_case_user_ID = 0;
    while (switch_case_user_ID < 1 || switch_case_user_ID > userDatabase.size()) {
        cout << "Wybierz uzytkownika,\nktoremu wypozyczasz ksiazke.\n";
        cin >> switch_case_user_ID;
        if ((switch_case_user_ID < 1 || switch_case_user_ID > userDatabase.size()))
            cout << "Brak uzytkownika o tym numerze na liœcie. Prosze sprobowac ponownie\n";
    }
    system("cls");
    cout << "Baza Ksiazek:\n";
    int number = 1;
    for (auto i : bookDatabase) {
        cout << number << ". ";
        i.printBook();
        number++;
    }
    cout << "Wybierz ID ksiazki, ktora chcesz wypozyczysz.\n";
    int bookNumber;
    cin >> bookNumber;
    while (bookNumber > bookDatabase.size() || bookNumber < 0) {
        cout << "Wpisano niewlasciwy numer!\nPodaj numer jeszcze raz: ";
        cin >> bookNumber;
    }
    bookNumber--;
    //switch_case_user_ID--;
    cout << "Wybrano ksiazke: " << bookDatabase[bookNumber].getTitle() << ".\n";
    if (bookDatabase[bookNumber].isAnyItemFree())
    {
        cout << "Dostepnych jest: " << bookDatabase[bookNumber].countFreeItems() << " szt. tej ksiazki.\n";
        userDatabase[switch_case_user_ID-1].addBorrowment(bookDatabase[bookNumber]);
        cout << "Ksiazka o id " << bookNumber << " zostala wypozyczona\nuzytkownikowi o id " << switch_case_user_ID << ".\n";
    }
    else
    {
        cout << "Nie ma dostepnych egzemplarzy tej ksiazki.\n";
    }
    system("pause");
}

void MainController::bookReturn() {
    int switch_case_user_ID = 0;
    while (switch_case_user_ID < 1 || switch_case_user_ID > userDatabase.size()) {
        cout << "Wybierz uzytkownika,\nktory zwraca ksiazke.\n";
        cin >> switch_case_user_ID;
        if ((switch_case_user_ID < 1 || switch_case_user_ID > userDatabase.size()))
            cout << "Brak uzytkownika o tym numerze na liœcie. Prosze sprobowac ponownie\n";
    }
    cout << "Wypozyczenia wybranego uzytkownika:\n";
    for (int i = 0; i < userDatabase[switch_case_user_ID-1].getUserBorrowments().size(); i++)
    {
        cout << userDatabase[switch_case_user_ID-1].getUserBorrowments()[i].getId() << endl;
    }
    cout << "Wybierz numer wypozyczenia.\n";
    int id_borrow;
    cin >> id_borrow;
    userDatabase[switch_case_user_ID-1].removeBorrowment(id_borrow);
    cout << "Czy nalezy nalozyc na uzytkownika kare za stan oddanej ksiazki?\nT/N\n";
    char decision;
    cin >> decision;
    if (decision == 'T')
    {
        double fine;
        cout << "Podaj wysokosc kary.\n";
        cin >> fine;
        loggedLibrarian.addUserFine(userDatabase[switch_case_user_ID - 1], fine);
    }
    if (decision == 'N') loggedLibrarian.addUserFine(userDatabase[switch_case_user_ID - 1], 0);
    system("pause");
}