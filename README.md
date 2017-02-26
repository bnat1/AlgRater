# AlgRater
This c++ program goes through large amounts of 3x3 algs to help determine if they are finger-frienldy. It looks at the number of regrips, rotations, rh vs lh ratio, and quarter turn metric (QTM) to give the algs grades out of 100. 

The idea is to input a filename for a file that contains many algorithms or to enter algs via terminal, then the program parses them, grades them, sorts them, and provides the top-x (or all) algs.

AlgRater determines stats for the algs by putting individual moves through a basic hand simulator, then the AlgRater checks the states of the hand objects.

The alg parser supports big moves,small moves, rotations, M moves, and their primes. All other characters are ignored. The hands does do R2' for example when it would make sense to. anything within parens is treated as comments, since cube explorer throws in things in parens after algs. 

Use:
do a make run, then run the executable 
works as everything intuitively should in the menu. To change weights/penalties for grading, edit the #define 's in AlgRater.h

For the future: web interface, allow users to specify and define grading criteria, show pictures of the algs, transform algs and go through different ways of execution, such as inserting wide moves and rotations, to find the one with the best execution.
