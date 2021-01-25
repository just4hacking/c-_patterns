# MOTIVATION
  - Complicated objects (e.g cars) aren't designed from scratch
    - They reiterate existing designs
  - An existing (partially or fully consturcted) design a
  Prototype
  - We make a copy (clone) the prototype and customize it
    - Requires 'deep copy' support
  - We make the clonning convinient (e.g. via Factory)

# PROTOTYPE
  - A partially or fully initialized object that you copy (clone) and make use of

# SUMMARY
  - To implement a prototype, partially construct an object and
    store it somewhere
  - Clone the prototype
    - Implement your own deep copy functionality; or 
    - Serialize and deserialize instead of implementing a deep copy functionelity (which might be tedious)