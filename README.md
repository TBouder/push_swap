# push_swap

[PDF](https://mega.nz/#!QpYDCZwY!7FJqDjwV06TvWhkwNO9lZveDoDjNrjPZs7EQ_rtMvn4)  

###Gameplay  
>The project goal is to order a stack (A), using another stack (B) and only 11 possible moves. At the beginning B is empty and their is various unique integers in A.  
>The stack has to be ordered decreasingly (left to right || bottom to top)  
> _sa_ : swap the top two elements on stack A  
> _sb_ : swap the top two elements on stack B  
> _ss_ : sa and sb at the same time  
> _pb_ : take the top element of A and move it to the top of B  
> _pa_ : take the top element of B and move it to the top of A  
> _rra_ : move all the elements on A to the top, moving the top element to the bottom  
> _rrb_ : move all the elements on B to the top, moving the top element to the bottom  
> _rrr_ : rra and rrb at the same time  
> _ra_ : move all the elements on A to the bottom, moving the bottom element to the top  
> _rb_ : move all the elements on B to the bottom, moving the bottom element to the top  
> _rr_ : ra and rb at the same time  

###Bonus :  
- [x] -v for verbose mode   
- [x] -c for color mode    
- [x] -o to display the number of operation at the end  
- [x] -i to display some informations (Starting and ending stack)  
- [x] -a for all flags  
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
