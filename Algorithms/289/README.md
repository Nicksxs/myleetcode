According to the [Wikipedia's article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life): "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."  

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):  

1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.  
2. Any live cell with two or three live neighbors lives on to the next generation.  
3. Any live cell with more than three live neighbors dies, as if by over-population..  
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.  

Write a function to compute the next state (after one update) of the board given its current state.  

**Follow up:**  

1. Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.  
2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?  

**题解**  
这里比较巧妙地使用0,1,2,3来表示状态:
```  
0: 表示当前状态是0，下一状态也是0,  
1: 表示当前状态是1，下一状态是1,  
2: 表示当前状态是1，下一状态是0,
3: 表示当前状态是0，下一状态是1.  
```
这里这样标识是有一个目的，就是做模2运算后下一状态相同的余也相同  
主要的方法就是用4个状态标识符表示前后两次状态   

参考[链接](http://segmentfault.com/a/1190000003819277)

