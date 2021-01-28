# MOTIVATION
- Objects use other objects' fields/properties/members through inheritance and composition
- Composition lets us make compound objects
  - E.g. a methematical expression composed of single expressions
  - A grouping of shapres that consists of several shapes

- Composite design pattern is used to treat both single (scalar) and composite objects uniformely
  - i.e, Foo and Collection<Foo> have common APIs

# COMPOSITE
A mechanism of threating individual (scalar) objects and compositions of ibjects in a uniform manner

# SUMMURY 
  - Objects can use objects via inheritance / composition
  - Some composed and singular objects need similiar/identical behaviours
  - Composite deisgn patterns lets us treat both types of objects uniformely
  - C++ uses duck typing, expecting enumerable
  types to provide begin()/end()
  - A single object can masquerade as a collection
    - Foo* begin() { return this }
    - Foo* end() { return this + 1 }