
#ifndef PAYLOAD_CONTAINER_H
#define PAYLOAD_CONTAINER_H


/**
  * class payload_container
  * This is just a container for the payload.
  */

class payload_container
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  payload_container();

  /**
   * Empty Destructor
   */
  virtual ~payload_container();

  // Static Public attributes
  //  

  // Public attributes
  //  

  std::string_view combo_payload;
  std::string_view user_agent;
  // A struct containing everything we need.
  std::string_view proxy;
  // This field is only used if the user has authenticated proxies.
  std::optional<std::pair<std::string_view, std::string_view>> proxy_authentication;

  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


  /**
   * Set the value of combo_payload
   * @param value the new value of combo_payload
   */
  void setCombo_payload(std::string_view value)
  {
    combo_payload = value;
  }

  /**
   * Get the value of combo_payload
   * @return the value of combo_payload
   */
  std::string_view getCombo_payload()
  {
    return combo_payload;
  }

  /**
   * Set the value of user_agent
   * @param value the new value of user_agent
   */
  void setUser_agent(std::string_view value)
  {
    user_agent = value;
  }

  /**
   * Get the value of user_agent
   * @return the value of user_agent
   */
  std::string_view getUser_agent()
  {
    return user_agent;
  }

  /**
   * Set the value of proxy
   * A struct containing everything we need.
   * @param value the new value of proxy
   */
  void setProxy(std::string_view value)
  {
    proxy = value;
  }

  /**
   * Get the value of proxy
   * A struct containing everything we need.
   * @return the value of proxy
   */
  std::string_view getProxy()
  {
    return proxy;
  }

  /**
   * Set the value of proxy_authentication
   * This field is only used if the user has authenticated proxies.
   * @param value the new value of proxy_authentication
   */
  void setProxy_authentication(std::optional<std::pair<std::string_view, std::string_view>> value)
  {
    proxy_authentication = value;
  }

  /**
   * Get the value of proxy_authentication
   * This field is only used if the user has authenticated proxies.
   * @return the value of proxy_authentication
   */
  std::optional<std::pair<std::string_view, std::string_view>> getProxy_authentication()
  {
    return proxy_authentication;
  }


  /**
   * Initializes the payload struct which will get passed into request.
   * @param  combo_payload
   * @param  user_agent
   * @param  proxy
   */
   payload_container(std::string_view combo_payload, std::string_view user_agent, std::string_view proxy)
  {
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


  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  void initAttributes();

};

#endif // PAYLOAD_CONTAINER_H
