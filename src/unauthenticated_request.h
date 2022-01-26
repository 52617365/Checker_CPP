
#ifndef UNAUTHENTICATED_REQUEST_H
#define UNAUTHENTICATED_REQUEST_H


/**
  * class unauthenticated_request
  * 
  */

class unauthenticated_request
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  unauthenticated_request();

  /**
   * Empty Destructor
   */
  virtual ~unauthenticated_request();

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

#endif // UNAUTHENTICATED_REQUEST_H
