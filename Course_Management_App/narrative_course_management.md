## Course Management System

Description:  
The Course Management System is a program developed in C++ to manage course data. It enables users to load, retrieve, and display course details, including prerequisites, using efficient data structures.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Enhancements:  
1. Refactored File Handling:  
   - Introduced a `FileHandler` class to modularize file parsing and data loading.  
   - Improved code reusability and maintainability.  

2. Optimized Data Structures:  
   - Replaced `vector` with `std::set` for storing prerequisites to ensure uniqueness and improve performance.  
   - Utilized `unordered_map` for fast course lookups.  

3. Improved Error Handling:  
   - Added checks for invalid or missing files.  
   - User-friendly error messages improve program usability.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Skills Demonstrated:  
- Software Design and Engineering: Modularized file handling for scalability and readability.  
- Algorithms and Data Structures: Optimized data storage using `unordered_map` and `std::set`.  
- Problem-Solving: Identified inefficiencies and applied enhancements to improve functionality and user experience.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Reflection:  
This artifact demonstrates my ability to improve existing code by focusing on modularity, efficiency, and usability. Refactoring the file handling logic into a separate class required overcoming initial challenges, such as linking errors and managing dependencies. These enhancements strengthened my understanding of **C++**, **STL**, and best practices in software design.
