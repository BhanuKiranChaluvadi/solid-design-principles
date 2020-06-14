/*
Dependency Inversion Principle
1. High-level module shoud not depend on low-level modules. Both should depend n
abstraction.
Eg: reporting component(high level component) shoulde not depend on
conosoleLogger (low level module), but can depend on an ILogger

The idea here is essentially we want to replace the concrete dependencies with
some form of abstraction, which are easier to digest, and the critical thing
here is that they are easier to digest. which helps both in test as well as when
you need to change something at runtime, there are lots of uses for that.

2. Abstraction should not depend upon details. Details should depend upon
abstraction. In other words, dependencies on interfaces and supertypes is better
than dependencies on concrete type.

So once again, the idea is that you really want ot have dependencies on
interfaces, and dependencies on super types, rather than concrete types.
Remember if we have a dependency on concrete type, its very difficult to
substitute afterwards, and this takes us back to the other principles, like the
LSP. You really want to subsitute a subtype for a supertype without totally
ruining the behaviour of the application.

###
So in the context of the dependency inversion we have two popular terms.
1. Inversion of control (IoC): The actual process by which we are making these
abstractions and we are using them to replace dependencies.
2. Dependency Injection: use of software framework(Bost.DI) to ensure that a component
dependencies are satified.
*/

