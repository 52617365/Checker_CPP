
#ifndef REQUEST_H
#define REQUEST_H


/**
  * class request
  * 
  */

class request
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  request();

  /**
   * Empty Destructor
   */
  virtual ~request();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //

protected:
  // Static Protected attributes
  //  

  // Protected attributes
  //  

  // The payload container containing everything we need, initialized in the constructor.
  // 
  // Url will be initialized as a constant that is known at compile time.
  payload_container payload;

  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //  


  /**
   * Set the value of payload
   * The payload container containing everything we need, initialized in the
   * constructor.
   * 
   * Url will be initialized as a constant that is known at compile time.
   * @param value the new value of payload
   */
  void setPayload(payload_container value)
  {
    payload = value;
  }

  /**
   * Get the value of payload
   * The payload container containing everything we need, initialized in the
   * constructor.
   * 
   * Url will be initialized as a constant that is known at compile time.
   * @return the value of payload
   */
  payload_container getPayload()
  {
    return payload;
  }


  /**
   * Initializes the request with the needed information.
   * @param  _payload This is the struct holding the required stuff to send the
   * request.
   */
   request(payload_container _payload)
  {
  }


  /**
   * Returns the status code of the request.
   * @return int
   */
  int send_request()
  {
  }

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

#endif // REQUEST_H
