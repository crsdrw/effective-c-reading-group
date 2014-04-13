My C++ Checklists
-----------------

### New Class Checklist ###

 1. Are all member variables initialized in all constructors? (Item 4) 
 2. Have you abided by the [rule of three (rule of five)][1]?
 3. Are there any compiler generated functions that should be disallowed? (Item 6)
 4. If it is a base class and users may want to hold a pointer to it then have you declared the destructor virtual? (Item 7)
 5. Does the destructor throw any exceptions? (Item 8)
 6. Do you call any virtual functions during construction or destruction? (Item 9)
 7. If you have an assignment operator does it return a reference to *this? (Item 10)
 8. If you have an assignment operator does it handle self assignment? (Item 11)
 9. Does your copy constructor/assignment operator copy all parts of the object? (Item 12)
 10. Are all resources managed by objects? (Item 13)
 11. If this class is a resource managing class can it be copied? (Item 14)
 12. If this class is a resource managing class does it manage only one resource?
 13. If this class is a resource managing class does it provide access to the raw resource? (Item 15)
 14. How should this class be created and destroyed? (Item 19)
 15. How should this class be initialized and assigned? (Item 19)
 16. How should this class be copied? (Item 19)
 17. What are the valid states for the class to be in? (Item 19)
 18. Does your class fit into an inheritance graph? (Item 19)
 19. What conversions should be allowed for your class? (Item 19)
 20. What operators and functions should your class have? (Item 19)
 21. Who should have access to the members of your class? (Item 19)
 22. What guarantees should the class make in terms of exception safety? (Item 29)
 23. Should the class be a class template? (Item 19)
 24. Do you need this class? (Item 19)
 25. Are all data members declared private? (Item 22)
 26. Does the class need a non-throwing `swap` (Item 25)

### New Function Checklist ###

 1. Should it be const? (Item 3)
 2. Are the parameters hard to provide incorrectly?, e.g bools, parameter ordering (Item 18) 
 3. Is the return type hard to use incorrectly? e.g const, resource managed object? (Item 18)
 4. Should parameters be passed by reference or value? (Item 20)
 5. Should this funciton return by value or reference? (Item 21)
 6. If this function does not need access to private parts of a class is it a non-member, non-friend function? (Item 23)
 7. If type conversions should apply to all parameters is it a non-member function? (Item 24)
 8. Are all variable definitions postponed for as long as possible? (Item 26)
 9. What guarantees does this function offer in terms of exception safety? (Item 29)


  [1]: http://en.wikipedia.org/wiki/Rule_of_three_%28C++_programming%29
