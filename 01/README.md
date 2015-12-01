# Santa floor

Pretty much the same way one would naively check for parenthesis matching.
Keep a counter and increment on ( and decrement on ).  For star 2, I use the
basement variable as my flag, with 0 being the 'sentinel' value for not having
gone negative yet.
