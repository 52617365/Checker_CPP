
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H


/**
  * class authentication
  * 
  */

class authentication
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  authentication();

  /**
   * Empty Destructor
   */
  virtual ~authentication();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * Add code that checks if the user has entered a valid authentication combo
   * (user:pass).
   * @return istream&
   * @param  is
   * @param  auth
   */
  istream& operator_(istream& is, authentication& auth)
  {
    is>> dt.mo>> dt.da>> dt.yr;
        return is;
  }


  /**
   * @return bool
   */
  bool get_auth_bool()
  {
    return auth;
  }


  /**
   * @return std::pair<std::string_view, std::string_view>
   */
  std::pair<std::string_view, std::string_view> get_auth_combo()
  {
    return auth_combo;
  }

protected:
  // Static Protected attributes
  //  

  // Protected attributes
  //  


  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //

private:
  // Static Private attributes
  //  

  // Private attributes
  //  

  // Contains true if user has proxy authentication and vica verca.
  bool auth;
  // If user has auth, contains users auth in a user:pass format.
  std::optional<std::pair<std::string_view, std::string_view>> auth_combo;

  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  /**
   * Set the value of auth
   * Contains true if user has proxy authentication and vica verca.
   * @param value the new value of auth
   */
  void setAuth(bool value)
  {
    auth = value;
  }

  /**
   * Get the value of auth
   * Contains true if user has proxy authentication and vica verca.
   * @return the value of auth
   */
  bool getAuth()
  {
    return auth;
  }

  /**
   * Set the value of auth_combo
   * If user has auth, contains users auth in a user:pass format.
   * @param value the new value of auth_combo
   */
  void setAuth_combo(std::optional<std::pair<std::string_view, std::string_view>> value)
  {
    auth_combo = value;
  }

  /**
   * Get the value of auth_combo
   * If user has auth, contains users auth in a user:pass format.
   * @return the value of auth_combo
   */
  std::optional<std::pair<std::string_view, std::string_view>> getAuth_combo()
  {
    return auth_combo;
  }


  /**
   * Asks the user if his proxies contain authentication.
   * @return bool
   */
  bool ask_if_authentication()
  {
        std::cin.exceptions(std::ios_base::badbit);
        for (;;) {
            char response = 0;
            do {
                std::cin.clear();
                std::cout << "proxy authentication (y)es|(n)o:\n";
                std::cin >> response;
                response = std::tolower(response);
            } while (response != 'y' && response != 'n');
    
            if (response == 'y') {
                auth = true;
            }
            if (response == 'n') {
                auth = false;
            }
        }
    
  }


  /**
   * // A function that asks user for his proxy authentication details after user has
   * said he has authentication.
   */
  void ask_for_authentication()
  {
  }

  void initAttributes();

};

#endif // AUTHENTICATION_H
