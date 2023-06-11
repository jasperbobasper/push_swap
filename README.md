# push_swap - Sorting Two Stacks
The push_swap project challenged me with the task of creating a number-sorting program. The program takes a random assortment of unique positive and/or negative numbers, and assigns them to stack 'a', along with creating an empty stack 'b'. The objective was to sort the numbers in stack 'a' in ascending order using a set of predefined operations. These operations included swapping elements within each stack, pushing elements between stacks, rotating elements within a stack, and reverse rotating elements.

Push_swap was one of the most challenging projects I undertook at 42. It needed careful consideration of the stack operations to devise an efficient sorting algorithm by minimizing the number of operations required. 

Through this project, I deepened my understanding of data structures, algorithm design, and program optimization. While push_swap presented significant challenges, it also improved my skills as a programmer and helped me learn to find my motiovation when faced with what at the time felt like an impossible task. 

## Implementation
<img src="https://github.com/jasperbobasper/push_swap/blob/main/img/2023-06-11_14-59-42_AdobeExpress.gif?raw=true" />
(a graphic visualisation of my project)
  - for stack numbers 5 and less, I made optimised custom algorithms
  - For larger stacks, I started by finding the LIS (longest increasing subsequence). From there, I rotated the stack until the LIS was at the top. 
  - All other elements were pushed to stack b. Both stacks are rotated until the center of the stack is at the top. 
  - From now, we calculate for each number which can be moved to its correct position in the least amount of moves (with rotations or reverse rotations) and save them to an array
  - This was further optimised by implementing the moves where both stacks are rotated at the same time
  - The operation with the least amount of moves required is then carried out
  - This is repeated until stack b is empty, and stack a can be rotated to it's final position.

With this method, I was consistantly able to sort the stacks within the highests 2 levels according to the scoring system in the evaluation of the project. 
(100 values in less than 700 moves, 500 values in less than 7000 moves)

(visualiser found here: https://github.com/o-reo/push_swap_visualizer)

## Usage
  - call `make`
  - run the program like so: `./push_swap <RANDOM NON REPEATING INTEGERS SEPERATED BY SPACES HERE>` eg. `./push_swap 4 1 5 3 2`
