problem1 n = sum [x | x <- [1..n-1], mod x 3 == 0 || mod x 5 == 0]
problem2 n = sum [x | x <- getFib n [1, 1], even x]

getFib n l = if last l < n 
	         then getFib n (l++[ head (reverse l) + head (tail (reverse l))])
	         else init l 