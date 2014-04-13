My C++ Checklists
-----------------

### New Class Checklist ###

 1. Are all member variables initialized in all constructors? (Item 4) 
 2. Have you abided by the [rule of three (rule of five)][1]?
 3. Are there any compiler generated functions you do not want? (Item 6)
 4. If it is a base class and users may want to hold a pointer to it then have you declared the destructor virtual? (Item 7)
 5. Does the destructor throw any exceptions? (Item 8)
 6. Do you call any virtual functions during construction or destruction? (Item 9)
 7. If you have an assignment operator does it return a reference to *this? (Item 10)
 8. If you have an assignment operator does it handle self assignment? (Item 11)
 9. Does your copy constructor/assignment operator copy all parts of the object? (Item 12)
 10. Are all resources managed by objects? (Item 13)
 11. If this class is a resource managing class can it be copied? (Item 14)
 12. 

### New Function Checklist ###

 1. Should it be const? (Item 3)


  [1]: http://en.wikipedia.org/wiki/Rule_of_three_%28C++_programming%29