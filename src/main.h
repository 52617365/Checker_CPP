
#ifndef MAIN_H
#define MAIN_H


/**
  * class main
  * // Acts as an entry point to the program.
  */

class main
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  main();

  /**
   * Empty Destructor
   */
  virtual ~main();

  // Static Public attributes
  //  

  // Public attributes
  //  

  // Holds combos.
  combos c;
  // Holds proxies.
  proxies p;
  // Holds user agents.
  user_agents u;
  // Holds the thread pool
  threading thread_pool;
  // Add loop here which iterates the lists.
  // 
  // Inside of the loop we should fill a payload_container and send it to the request class.
  // 
  // (Initialize request object and a payload_container object inside of the loop).
  ADD_LOOP loop;

  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


  /**
   * Set the value of c
   * Holds combos.
   * @param value the new value of c
   */
  void setC(combos value)
  {
    c = value;
  }

  /**
   * Get the value of c
   * Holds combos.
   * @return the value of c
   */
  combos getC()
  {
    return c;
  }

  /**
   * Set the value of p
   * Holds proxies.
   * @param value the new value of p
   */
  void setP(proxies value)
  {
    p = value;
  }

  /**
   * Get the value of p
   * Holds proxies.
   * @return the value of p
   */
  proxies getP()
  {
    return p;
  }

  /**
   * Set the value of u
   * Holds user agents.
   * @param value the new value of u
   */
  void setU(user_agents value)
  {
    u = value;
  }

  /**
   * Get the value of u
   * Holds user agents.
   * @return the value of u
   */
  user_agents getU()
  {
    return u;
  }

  /**
   * Set the value of thread_pool
   * Holds the thread pool
   * @param value the new value of thread_pool
   */
  void setThread_pool(threading value)
  {
    thread_pool = value;
  }

  /**
   * Get the value of thread_pool
   * Holds the thread pool
   * @return the value of thread_pool
   */
  threading getThread_pool()
  {
    return thread_pool;
  }

  /**
   * Set the value of loop
   * Add loop here which iterates the lists.
   * 
   * Inside of the loop we should fill a payload_container and send it to the request
   * class.
   * 
   * (Initialize request object and a payload_container object inside of the loop).
   * @param value the new value of loop
   */
  void setLoop(ADD_LOOP value)
  {
    loop = value;
  }

  /**
   * Get the value of loop
   * Add loop here which iterates the lists.
   * 
   * Inside of the loop we should fill a payload_container and send it to the request
   * class.
   * 
   * (Initialize request object and a payload_container object inside of the loop).
   * @return the value of loop
   */
  ADD_LOOP getLoop()
  {
    return loop;
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

#endif // MAIN_H
