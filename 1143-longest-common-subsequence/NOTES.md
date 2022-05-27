Idea : is to set an index for recursion but here we have to deal with two indpenden strings therefore we have to set 2 indexes. then we compare // do stuff
​
​
stuff that can be done :
1 . if char at both ind in strings are same therefire length of lcs will increase by one
2. if char are not same we have two choices 1. to move ind1 down only 2. to move ind2 down only and we will output the max of both
​
​
Base case :
​
if we gone beyond the start of strings i.e : ind1 or ind2  <0