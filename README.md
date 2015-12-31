# AlgRater
This c++ program go through large amounts of 3x3 algs to help determine if they are finger-frienldy. It looks at the number of regrips, rh vs lh ratio, and quarter turn metric (QTM) to give the algs grades out of 100. 

The idea is to input a filename for a file that contains many algorithms, then the program grades them, sorts them, and provides the top-x algs.

There is no driver yet, but it will prompt for a filename, then ask how many algs to display.
then it gives algs to the AlgRater, tells the algrater to grade the algs, sort the algs, and display the top x algs.

AlgRater determines stats for the algs by putting individual moves through TwoHands, and then AlgRater can check the status of Twohands: if the last move was a regrip, and if the last move was performed by left/right hand
