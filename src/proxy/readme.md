# MOTIVATION
- You are calling foo.bar()
- This assumes that foo is in the same process as bar()
- What if, later on, you want to put all Foo-related operations into a separate process
  - can you avoid changing your code?
- Proxy to the rescue
  - Same interface, entirely different behavior
- this is called a communication proxy
  - Other types: logging, virtual, guarding ...

# PROXY
A class that functions as an interface to a particular resource. That resource may be remote, expensive to construct,
or may require logging or some other added functionality

# EXAMPLE
- Smart pointers
- Proxy servers

# PROXY vs DECORATOR
- Proxy provides an identical interface; decorator provides an echanced interface
- Decorator typically aggregates (or has reference to) what it is decoratingl proxy doesn't have to
- Proxy might not even be working with a materialized object

# SUMMARY
- A proxy has the same interface as the underlying object
- To create a proxy, simply replicate
the existing interface of an object
- Add relevant functionality to the redefined member functions
- Different proxies (communication, logging, caching, etc)
have completely different behaviors