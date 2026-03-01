# CS-300_DSA-Analysis-and-Design Portfolio Reflection

## What was the problem you were solving in the projects for this course?
In this course, I developed a course planning application that reads course data from a file, stores it in an appropriate data structure, and allows the user to print an alphanumeric list of courses or search for a specific course and display its prerequisites. Project One focused on analyzing the run-time and memory usage of three different data structures (vector, hash table, and binary search tree) to determine which would be most efficient for storing and retrieving course data. Project Two implemented a working solution in C++ that loads course data into a map (which functions as a balanced tree structure), automatically maintains alphanumeric order, and allows efficient searching and printing of course information.

## How did you approach the problem? Consider why data structures are important to understand.
I approached the problem by first breaking it into two parts: data storage and data retrieval. I evaluated three different data structures—vector, hash table, and binary search tree—based on their runtime complexity and memory usage. 

Understanding data structures is critical because they directly impact performance. For example:

- A vector allows simple storage and iteration but requires sorting for ordered output and linear search for lookups.

- A hash table provides fast average lookup time but does not maintain order.

- A binary search tree provides ordered traversal and efficient searching when balanced.

After analyzing the trade-offs, I implemented the final solution using a map in C++, which is typically implemented as a self-balancing binary search tree. This allowed me to automatically maintain sorted order while still achieving efficient search performance. This project reinforced that selecting the correct data structure is just as important as writing correct code.

## How did you overcome any roadblocks you encountered while going through the activities or project?
One of the main challenges was properly parsing the CSV file and handling edge cases such as missing prerequisites or inconsistent capitalization. I resolved this by:

- Validating file input before processing.

- Converting course numbers to uppercase to ensure consistent searching.

- Checking if the data structure was empty before allowing print or search operations.

Another challenge was understanding runtime complexity in both average and worst-case scenarios. Carefully stepping through each pseudocode operation helped me calculate Big-O notation accurately and better understand performance differences. Breaking the problem into smaller functions (load, print list, print single course) also made debugging much easier.

## How has your work on this project expanded your approach to designing software and developing programs?

This project strengthened my understanding of how design decisions affect scalability and performance. Instead of immediately coding a solution, I now think more critically about:

- What operations will be most frequent?

- Does the program require ordered output?

- What is the expected data size?

- What are the time and space trade-offs?

By analyzing runtime before implementation, I gained a deeper appreciation for algorithm efficiency. This project helped shift my mindset from simply “making it work” to “making it efficient and scalable.”

## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

This project improved my programming practices in several ways:

- I separated functionality into clear, single-purpose functions (loading data, printing all courses, printing one course).

- I used meaningful variable and function names to improve readability.

- I implemented input validation and error handling to make the program more robust.

- I structured the menu system clearly so future features could easily be added.

Additionally, understanding data structures has made me more confident in writing adaptable programs. If requirements change (for example, switching to a different storage structure), I now better understand how to refactor the code efficiently. Overall, this project strengthened both my technical understanding of data structures and my ability to design clean, maintainable software solutions.
