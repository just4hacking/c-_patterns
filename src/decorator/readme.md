# MOTIVATION
  - Want to augment an object with additional functionality
  - Do not awnt to rewrite or alter existing code (OCP)
  - Want to keep new functionality separate (SRP)
  - Need to be able to interact with existing structures
  - Two options
    - Aggregate the decorated object
    - Injerit from the decorated object

# DECORATOR
Facilitates the addition of behaviors to individual objects

# SUMMARY
- Dynamic decorator keeps the reference to the decorated object(s)
  - ColoredShape{Square{}}
- A static decorator uses mixin inheritance
  - ColoredShape<Square>
- Both approaches allow limitless composition
  - TransparentShape<ColoredShapre<Circle>>