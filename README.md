# Phillips_CSCI2270_FinalProject
PROJECT SUMMARY

	My program is a simulation of an online store, such as Amazon. When it starts, it prompts the user for a filename.
	This file is a text file containing names of products, prices and categories, and must be arranged exactly how the
	"FinalProjectTextFile.txt" is. Other than that, it can contain any products, prices and categories the user wants to
	put in the file. Everything from the text file is passed into a graph. Vertices of the same category are adjacent,
	and all vertices are adjacent to a single starting vertex that contains nothing. Pointer to all vertices are also
	stored in hash table. The hashing function uses the sum of the ASCII values in the product name and mods it with the
	size of the table (701) to generate the hash value. I used 701 because it is a large prime number and works well for
	the size of the data set I'm using. Once everything is read from the file, the user can search for a specific item
	(this uses the hash table), print the inventory (prints all vertices adjacent to the starting vertex), add a
	specific number of items to a shopping cart (this adds vertices to a vector,along with how many of each item is in
	the cart), and can "checkout", in which case everything in the cart is printed along with the total cost and the
	cart vector is cleared. 
	
HOW TO RUN
	
	First, download the zip file for the project if you haven't already, and open it. Then, open your terminal and enter
	"cd" followed by the directory of the project folder. Then, enter "g++ -std=c++11 FinalProject.cpp -o FinalProject".
	This will compile the .cpp file and create an executable. Go to the project folder and run the executable.
	One important note: When the program prompts you for the name of the text file to open, you must enter to the file's 
	full directory to ensure that it will open. 
	For example,"/Users/owenphillips/Downloads/Phillips_CSCI2270_FinalProject-master/FinalProjectTextFile.txt"
	After that, the program will bring up a menu. To pick an option, enter the
	option's number. Also, if the program prompts "Add to cart?  [y/n]", y (yes) or n (no) must be entered. When
	searching for an item, just enter the item's name.

DEPENDENCIES

	There must be a text file in the format:
	
	Product, Cost, Category
	Product, Cost, Category
	
	where Product is any number of words, Cost is a whole number, and Category is any number of words. They must be 
	seperated with commas and new lines.
	
SYSTEM REQUIREMENTS

	Operating System: Mac OS or Linux.
	
OPEN ISSUES/BUGS

	One issue is that if the text file is sufficiently large, there will be hash collisions when reading the
	file. The program will still run well, but not everything in the graph will be present in the hash table, meaning
	it will not be possible to search for certain items.
