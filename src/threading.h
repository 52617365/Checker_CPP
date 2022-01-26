
#ifndef THREADING_H
#define THREADING_H


/**
  * class threading
  * 
  */

class threading
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  threading();

  /**
   * Empty Destructor
   */
  virtual ~threading();

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


  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //

private:
  // Static Private attributes
  //  

  // Private attributes
  //  

  // // This is the class member holding the thread pool implementation.
  pool thread_pool;

  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  /**
   * Set the value of thread_pool
   * // This is the class member holding the thread pool implementation.
   * @param value the new value of thread_pool
   */
  void setThread_pool(pool value)
  {
    thread_pool = value;
  }

  /**
   * Get the value of thread_pool
   * // This is the class member holding the thread pool implementation.
   * @return the value of thread_pool
   */
  pool getThread_pool()
  {
    return thread_pool;
  }

  void initAttributes();

};

#endif // THREADING_H
