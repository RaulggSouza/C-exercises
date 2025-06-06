# C-exercises

## All this exercises were made by Raul Souza

### Non recursive Quick Sort
It is well known that sorting is an important operation when we are the the programming context. One of the best ways to sort an array is using the Quick Sort, a sorting method that executes operations in O(N logN), this happens due to its recursive nature.

This activity had the objective to create a Quick Sort program, but instead of using the classic recursion, I was challenged to use a Stack data structure. The first part of this challenge is understanding why the Stack can replace the recursion, the answer is simples, it's because when whe use a recursion the code is executed as Stack underneath the curtains, so to resolve this challenge, I just needed to "bring the Stack to the spotlight". The second part was to create the solution, that is located in "QuickSort_Nao_Recursivo" for you to take a look".

### Prefetential Bank Queue
We all have experienced queues in our lives, and one of the places that have the longest queues are banks, specially because most of them have a "preferential queue" that attends people with preference first, and then attends the people on the general queue.

In this activity I had to simulate a Bank Queue. The rule to attend people is simple: if the preferential queue is empty, the general queue is attended, otherwise, the preferential queue is attended, but if 3 people from the preferential queue were attended, 1 from the general queue is attended. To implement the solution, I used a Queue data structure, specifically an circular queue that solves partially the problem of removing the element from a queue.
