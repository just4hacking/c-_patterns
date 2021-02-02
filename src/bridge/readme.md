# MOTIVATION 
  - Bridge prevent's 'Cartesian product' complexity explosion
  - Example:
    - Base class ThreadScheduler
    - Can be preemptive or cooperative
    - Can run on Windows or Unix
    - End up with a 2x2 scenario: WindowsPTS, UnixPTS,
      WindowsCTS, UnixCTS
  - bridge pattern avoid the entity explosion

# BRIDGE
A mechanism that decoupls an interface (hierarchy) from
an implementation (hierarchy)

# SUMMARY
- Decouple abstraction from implementation
- Both can exist as hierarchies
- A stronger form of encapsulation