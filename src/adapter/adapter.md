# MOTIVATION
  - We need a specific class to give us a specific interface that we require

# ADAPTER 
A construct which adapts an existing interface X to conform to the required interface Y

# SUMMARY
  - Implementing an Adapter is easy
  - Determine the API you have and the API you need
  - Create a component which aggregates (has a reference to, ...) the adaptee
  - Intermediate representations can pile up: use caching and other optimizations