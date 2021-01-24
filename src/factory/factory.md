# MOTIVATION
  - Object creating logic becomes too convoluted
  - Constructor is not descriptive
    - Name mandated by name of containing type
    - Cannot overload with same sets of arguments with different names
    - Can turn into 'optional parameter hell'
  - Object creation (non-piecewise, unlike Builder) can be outsourced to
    - A seperate function (Factory method)
    - That may exist in a seperate class (Factory)
    - Can create hierarchy of factories with Abstract Factory

# FACTORY
A component responsible solely for the wholesale (not piecewise)
creation of objects

# SUMMARY
  - A factory method is a static method that creates objects
  - A factory can take care of object creation
  - A factory can be external component or reside inside the object as an inner class
  - Hierarchies of factories can be used to create related objects