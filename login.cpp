#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ws;

class User 
{
    private:
        string username, password;

    public:
        //Make sure your variable names are clear.  x and y in this case are unclear.  uName and pass clearly state what is going on.
        void setUsername(string uName)
        {
            username = uName;
        }
        //Same as above
        void setPassword(string pass)
        {
            password = pass;
        }
        string getUsername()
        {
            return username;
        }
        string getPassword()
        {
            return password;
        }
        //Check user's credentials match
        bool validCredentials(string uName, string pass) {
            return username == uName && password == pass;
        }
        //This is a constructor.  It will create a user without a username and password.  Really not needed for this (security reasons in pratice), but for example.
        User () 
        {}
        //This is a constructor.  Given a username and password, it will make a new User.  A class can have any number of constructors.
        User(string uName, string pass) 
        {
            username = uName;
            password = pass;
        }
};

void createAccount(vector<User> &accounts);
bool login(vector<User> &accounts, int &login_attempts);
void manageAccounts();

int main () 
{
    //Define all like variables together.  Less code + readability
    vector<User> accounts;
    int selection, login_attempts = 0;
    bool login_successful = false;

    //Avoid do{}while() statements.  Instead use while (){} statements.  More typical in programming.
    while(selection != 5){
        
        //When making a long string, do something like this.  Don't keep concating to it unless necessary.
        cout << "\nMake a selection:\n"
        "1. Login\n"
        "2. Create account\n"
        "3. Manage accounts\n"
        "4. Login check\n"
        "5. Exit\n"
        "-> ";
        cin >> selection;

        switch(selection){
            case 1: login_successful = login(accounts, login_attempts);
                break;
            case 2: createAccount(accounts);
                break;
            case 3: manageAccounts();
                break;
            //Turned this into a ternary operator.  ? is runs if the statement is true, : runs if the statement is false.  In this example, if login_successful is ture, it runs "You are logged in!".  On false, it runs, "You are not logged in".  Read about these as they are useful.
            case 4: login_successful ? cout << "\nYou are logged in!\n" : cout << "\nYou are not logged in\n";
                break;
            case 5: 
                break;
            default:
                cout << "\nInvalid choice\n";
        }
    };
    return 0;
}
void createAccount(vector<User> &accounts)
{
    //Why limit to three users?  The vector can hold a large amount of users.  Don't need to even define them here.
    //Stick to one case style (login_successful, snake case, or localUser, camel case).  Edit your variable names to whichever style you chose and stick with it.
    //Functions should stay camel case (createAccount)
    string localUsername, localPassword;

    cout << "\nEnter username: ";
    cin >> localUsername;

    cout << "Enter password: ";
    cin >> localPassword;

    User createdUser (localUsername, localPassword);
    accounts.push_back(createdUser);

    cout << "\nAccount created!\n";
}
/**
 *  Prompts for login credentials and attempts to login the user.
 * 
 *  Note: do something like this for the other functions (createAccount, manageAccount, validCredentials)
 * 
 *  @tparam &accounts the accounts available
 *  @tparam &login_attempts the login attempts made
 *  @return boolean - is valid user
 */
bool login(vector<User> &accounts, int &login_attempts){

    string login_username, login_password;
    
    //If no accounts are there, no need to say incorrect password (because there is no user) and add to the fail count.  
    if(size(accounts) == 0)
    {
        cout << "\nNo accounts created.  Please make an account\n";
        return false;
    }
    
    //Check for max logins before going to the login page.
    if(login_attempts > 2){
        cout << "Max login attempts reached\n";
        return false;   
    }
    
    //If both checks pass, then go to the login page and run the logic to see if the user is valid.
    cout << "\n\n\n****************************\n"
    "         Login Page         \n"
    "****************************\n\n";
    
    cout << "Username: ";
    cin >> login_username;

    cout << "Password: ";
    cin >> login_password;

    //This is a for loop that maps every accounts[i] to a user variable (which is based on the User class).  It does the same logic but with less code and becomes much clearer.
    for(User user : accounts) {
        if (user.validCredentials(login_username, login_password)){
            cout << "\nLogin successful!\n";
            return true;
            break;
        }
    }

    cout << "\nIncorrect username or password\n";
    login_attempts++;
    return false;
}
//TODO: Add logic to show/remove accounts.
void manageAccounts(){
    //Best pratice: anytime you have an empty function, add a // like below to signify there is nothing happening.  Also a TODO is nice at the top.
    //
}
