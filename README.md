#LSD Radix Sort Algorithm Implementation

Compile the program 

	$ make

Run the program

	$ make run input=f.txt output=g.txt 

Here

* f.txt is the input file 
* g.txt is output file 


Then choose whether to run lsd using pointers or swap 
	
	Please select technique for sorting: 
	1        Using pointer array  
	2        Using Swapping


# Analysis

## Time Complexity

LSD Radix Sort is linear time sorting algorithm. It is a stable sort. I have implemented lsd Radix sort using two different method.

- First Method makes use of pointers to keep track of indices without swapping the values 

- Second Method swaps the values in each cycle

Both the algorithms of lsd Radix sort takes O(n) asymptotic time. 


## LSD Radix Sort Using pointers 

![Image of LSD Sort using Pointers](images/lsd1.png)


## LSD Radix Sort Using Swapping

![Image of LSD Sort using Pointers](images/lsd2.png)

## Author

Tushar Sharma `tushar.sharma1729@gmail.com`

## License

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

