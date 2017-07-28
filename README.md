# Phillips_CSCI2270_FinalProject
PROJECT SUMMARY

	My program is a simulation of an online store. It's only a simulation because it isn't online and isn't a REAL store. When it starts, it prompts the user for a filename. This file is a text file containing names of products, prices and categories, and must be arranged exactly how the "FinalProjectTextFile.txt" is. Other than that, it can contain any products, prices and categories the user wants to put in the file. Everything from the text file is passed into a graph. Vertices of the same category are adjacent, and all vertices are adjacent to a single starting vertex that contains nothing. Pointer to all vertices are also stored in hash table. The hashing function uses the sum of the ASCII values in the product name and mods it with the size of the table (701) to generate the hash value. I used 701 because it is a large prime number and works well for the size of the data set I'm using. Once everything is read from the file, the user can search for a specific item (this uses the hash table), print the inventory (prints all vertices adjacent to the starting vertex), add a specific number of items to a shopping cart (this adds vertices to a vector, along with how many of each item is in the cart), and can "checkout", in which case everything in the cart is printed along with the total cost and the cart vector is cleared. 
	
HOW TO RUN

	

DEPENDENCIES
