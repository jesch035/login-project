#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::getline;
using std::ws;

class User 
{
    private:

        string username;
        string password;


    public:

        void setUsername(string x)
        {
            username = x;
        }
        void setPassword(string y)
        {
            password = y;
        }
        string getUsername()
        {
            return username;
        }
        string getPassword()
        {
            return password;
        }
};

void createAccount(vector<User> &accounts, User &user1, User &user2, User &user3);
bool login(vector<User> &accounts, User &user1, User &user2, User &user3, int &login_attempts);
void manageAccounts();

int main () 
{

    User user1;
    User user2;
    User user3;
    vector<User> accounts;
    int selection;
    int login_attempts = 0;
    bool login_successful = false;

    do{

        cout << "\nMake a selection:\n";
        cout << "1. Login\n";
        cout << "2. Create account\n";
        cout << "3. Manage accounts\n";
        cout << "4. Login check\n";
        cout << "5. Exit\n";
        cout << "-> ";
        cin >> selection;

        switch(selection){
            case 1: login_successful = login(accounts, user1, user2, user3, login_attempts);
                break;
            case 2: createAccount(accounts, user1, user2, user3);
                break;
            case 3: manageAccounts();
                break;
            case 4:

                if(login_successful){
                    cout << "\nYou are logged in!\n";
                }
                else{
                    cout << "\nYou are not logged in\n";
                } 

                break;
            case 5: 
                break;
            default:
                cout << "\nInvalid choice\n";
        }
    }while(selection != 5);

    return 0;
}
void createAccount(vector<User> &accounts, User &user1, User &user2, User &user3)
{
    if(size(accounts) < 3){

        string localUsername;
        string localPassword;

        cout << "\nEnter username: ";
        getline(cin >> ws, localUsername);

        cout << "Enter password: ";
        getline(cin >> ws, localPassword);

        switch(size(accounts))
        {
            case 0: 
                user1.setUsername(localUsername);
                user1.setPassword(localPassword);
                accounts.push_back(user1);
                break;
            case 1:
                user2.setUsername(localUsername);
                user2.setPassword(localPassword);
                accounts.push_back(user2);
                break;
            case 2:
                user3.setUsername(localUsername);
                user3.setPassword(localPassword);
                accounts.push_back(user3);
                break;
        }

        cout << "\nAccount created!\n";

    }
    else{
        cout << "\nYou've created the max number of accounts\n";
    }
}

bool login(vector<User> &accounts, User &user1, User &user2, User &user3, int &login_attempts){

    string login_username;
    string login_password;

    cout << '\n' << '\n' << "\n****************************\n";
    cout << "         Login Page         \n";
    cout << "****************************\n" << '\n';

    if(login_attempts > 2){
        cout << "Max login attempts reached\n";

        return false;   
    }

    cout << "Username: ";
    getline(cin >> ws, login_username);

    cout << "Password: ";
    getline(cin >> ws, login_password);

    if(size(accounts) == 0){

        cout << "\nIncorrect username or password\n";

        login_attempts++;

        if(login_attempts > 2){

            cout << "Max login attempts reached\n";
        }

        return false;
    }
    else{

        for(int i = 0; i < size(accounts); i++){
            if(login_username == accounts[i].getUsername() && login_password == accounts[i].getPassword()){
                cout << "\nLogin successful!\n";

                return true;
                break;
            }
        }

        cout << "\nIncorrect username or password\n";

        login_attempts++;

        return false;
    }
}
void manageAccounts(){

}





