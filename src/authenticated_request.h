
#ifndef AUTHENTICATED_REQUEST_H
#define AUTHENTICATED_REQUEST_H


/**
  * class authenticated_request
  * This class overrides the send_request with an authenticated proxy.
  */

class authenticated_request
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  authenticated_request();

  /**
   * Empty Destructor
   */
  virtual ~authenticated_request();

  // Static Public attributes
  //  

  // Public attributes
  //  

  using request_request_;

  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


  /**
   * Set the value of request_request_
   * @param value the new value of request_request_
   */
  void setRequest_request_(using value)
  {
    request_request_ = value;
  }

  /**
   * Get the value of request_request_
   * @return the value of request_request_
   */
  using getRequest_request_()
  {
    return request_request_;
  }


  /**
   * Overridden send_request function that uses an authenticated proxy.
   * @return int
   */
  int send_request()
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

#endif // AUTHENTICATED_REQUEST_H
