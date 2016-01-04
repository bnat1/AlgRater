# AlgRater
This c++ program go through large amounts of 3x3 algs to help determine if they are finger-frienldy. It looks at the number of regrips, rh vs lh ratio, and quarter turn metric (QTM) to give the algs grades out of 100. 

The idea is to input a filename for a file that contains many algorithms, then the program grades them, sorts them, and provides the top-x algs.

The current driver gives the AlgRater several algorithms, and calls AlgRater's functions to pass them through two hands, grade the algs, sort them, and display them in order from best to worst.

The remaining steps to complete this program are to create a file parser that takes a file with algs and pushes Algs to AlgRater, and create a UI. The first UI will just be c++ command line, but future versions will possibly be online with a cgi script for more accessability.

