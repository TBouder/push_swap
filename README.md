# push_swap

[PDF](https://mega.nz/#!QpYDCZwY!7FJqDjwV06TvWhkwNO9lZveDoDjNrjPZs7EQ_rtMvn4)  

###Gameplay  
>The project goal is to order a stack (A), using another stack (B) and only 11 possible moves. At the beginning B is empty and their is various unique integers in A.  
>The stack has to be ordered decreasingly (left to right || bottom to top)  
> **sa** : swap the top two elements on stack A  
> **sb** : swap the top two elements on stack B  
> **ss** : sa and sb at the same time  
> **pb** : take the top element of A and move it to the top of B  
> **pa** : take the top element of B and move it to the top of A  
> **rra** : move all the elements on A to the top, moving the top element to the bottom  
> **rrb** : move all the elements on B to the top, moving the top element to the bottom  
> **rrr** : rra and rrb at the same time  
> **ra** : move all the elements on A to the bottom, moving the bottom element to the top  
> **rb** : move all the elements on B to the bottom, moving the bottom element to the top  
> **rr** : ra and rb at the same time  

###Bonus :  
- [x] -v for verbose mode   
- [x] -c for color mode    
- [x] -o to display the number of operation at the end  
- [x] -i to display some informations (Starting and ending stack)  
- [x] -a for all previous flags  
- [x] -s to display nothing  
- [x] Possibility to use -vcio instead of -v -c -i -o  
- [x] Custom messages for exit (Success, error, already ordered, only one number)  
- [x] Usage message

###Requirements :  
- [FT_PRINTF](https://bitbucket.org/Tbouder/libft)  
- [LIBFT](https://bitbucket.org/Tbouder/libft)  
- C compiler  
- GNU  

###Installation :  
1. git clone https://bitbucket.org/Tbouder/push_swap && cd push_swap  
1. git clone https://bitbucket.org/Tbouder/ft_printf && cd ft_printf  
2. git clone https://bitbucket.org/Tbouder/libft  
3. cd ..  
4. make  
5. ./push_swap [-vcoia] [n1 n2 ...]  
