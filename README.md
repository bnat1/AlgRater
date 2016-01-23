# AlgRater
This c++ program go through large amounts of 3x3 algs to help determine if they are finger-frienldy. It looks at the number of regrips, rotations, rh vs lh ratio, and quarter turn metric (QTM) to give the algs grades out of 100. 

The idea is to input a filename for a file that contains many algorithms or to enter algs via terminal, then the program parses them, grades them, sorts them, and provides the top-x (or all) algs.

There is no driver yet, but it will prompt for a filename, then ask how many algs to display.
then it gives algs to the AlgRater, tells the algrater to grade the algs, sort the algs, and display the top x algs.

AlgRater determines stats for the algs by putting individual moves through a basic hand simulator, then the AlgRater checks the states of the hand objects.

The alg parser supports big moves,small moves, rotations, M movs. All other characters are ignored. At this point, only standard (not inverted) double moves are supported, but the hands does do R2' for example when it would make sense to. anything within parens is treated as comments, since cube explorer throws in things in parens after algs. 

Use:
works as everything intuitively should in the menu. To change weights, edit the #define 's in AlgRater.h
