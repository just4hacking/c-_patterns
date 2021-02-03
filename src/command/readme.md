# MOTIVATION
- Ordinary C++ statements are perishable
  - Cannot undo a field/property assignment
  - Cannot directly serialize a sequence of actions (calls)
- Want an object that represents an operation
  - X should change its field Y to the value Z
  - X should do W()
- Uses: GUI commands, multi-level undo/redo, macro recording and more!

# COMMAND
An object which represents an instruction to perform a particular action. Contains all the finformation
necessary for the action to be taken

# COMMAND QUERY SEPARATION
- Command = asking for an action or change (e.g, please set your attack value to 2)
- Query = asking for information (e.g please five me your attack) Don't cause any mutations!
- CQS = having seperate means of sending commands and queries
- In GoF context, both commands and queries are represented with the Command design pattern



