# Santa floor

Pretty much the same way one would naively check for parenthesis matching.
Keep a counter and increment on ( and decrement on ).  For star 2, I use the
basement variable as my flag, with 0 being the 'sentinel' value for not having
gone negative yet.

So I explicitly test for both parens.  This was an artifact of me not
knowing about atoms 'feature' of always adding an extra line break. If
you know for sure you have only parens and EOF characters in your file,
then a single if/else will work.  Otherwise, the explicit test for both
is a safe, if not verbose, call.
