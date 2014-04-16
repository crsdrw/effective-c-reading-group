My C++ Checklists
-----------------

### New Class Checklist ###
 1. Do you need this class?
 2. Have you abided by the [_rule of three_ (rule of five)][1]?
 3. Are there any compiler generated functions that should be disallowed? (Item 6)
 4. Are all resources managed by objects? (Item 13)
 5. Are all data members declared `private`? (Item 22)
 6. How should this class be created and destroyed? (Item 19)
 7. How should this class be initialized and assigned? (Item 19)
 8. How should this class be copied? (Item 19)
 9. What are the valid states for the class to be in? (Item 19)
 10. Does your class fit into an inheritance graph? (Item 19)
 11. What conversions should be allowed for your class? (Item 19)
 12. What operators and functions should your class have? (Item 19)
 13. Who should have access to the members of your class? (Item 19)
 14. What guarantees should the class make in terms of exception safety? (Item 29)
 15. Should the class be a class template? (Item 19)
 16. Does the class need a non-throwing `swap` (Item 25)
 17. Should the class implementation be hidden using _pimpl idom_ or an interface? (Item 31)

### New Function Checklist ###
 1. Should it be `const`? (Item 3)
 2. Are the parameters hard to provide incorrectly?, e.g bools, parameter ordering (Item 18) 
 3. Is the return type hard to use incorrectly? e.g const, resource managed object? (Item 18)
 4. Should parameters be passed by reference or value? (Item 20)
 5. Should it return by value or reference? (Item 21)
 6. Can it be a non-member non-friend function? (Item 23)
 7. If type conversions should apply to all parameters is it a non-member function? (Item 24)
 8. Are all variable definitions postponed for as long as possible? (Item 26)
 9. Are you returning any handles to internal objects? (Item 28)
 10. What guarantees does this function offer in terms of exception safety? (Item 29)
 
### Constructor Checklist ###
1. Do you call any `virtual` functions?
2. Are all member variables initialized in all constructors? (Item 4)

### Destructor Checklist ###
 1. Does the destructor throw any exceptions? (Item 8)
 2. If it is a base class and users may want to hold a pointer to it
    then have you declared the destructor `virtual`? (Item 7)
 3. Do you call any `virtual` functions?

### Assignment Operator Checklist ###
 7. Does it return a reference to `*this`? (Item 10)
 8. Does it handle self assignment? (Item 11)

### Resource Managing Class ###
 11. What should the copying behaviour be? (Item 14)
 12. Does it manage only one resource?
 13. Does it provide access to the raw resource? (Item 15)

  [1]: http://en.wikipedia.org/wiki/Rule_of_three_%28C++_programming%29
