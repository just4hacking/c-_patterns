# MOTIVATION
- Balancing complexity and presentation/usability
- Typical home 
  - Many subsystem (electrical, sanitation)
  - Complex internal system structure (e.g. floor layers)
  - End user is not exposed to internals
- Same with software!
  - Many systems working to provide flexibility, but...
  - API consumers want it to 'just work'

# FACADE 
Provides a simple, easy to understand/user interface over a large and sophisticated body of code

# SUMMARY
- Build a Facade to provide a simplified over a set of classes
- Many wish to (optionally) expose internals through the facade
- May allow users to 'escalate' to use more complex APIs if they need to