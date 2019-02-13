encode' :: String -> [(Char, Int)]
encode' [] = []
encode' (x:xs) = encodeHelper xs x 1
	where
		encodeHelper [] ch n = [(ch, n)]
		encodeHelper (x:xs) ch n
			|x == ch 			= encodeHelper xs ch (n+1)
			|otherwise 			= (ch, n) : (encodeHelper xs x 1)

decode :: [(Char, Integer)] -> String
decode [] = []
decode ((ch, n):xs) = (replicate (fromIntegral n) ch) ++ (decode xs)

reverse :: [a] -> [a]
reverse [] = []
reverse l = (last l) : (reverse (init l))


rotate [] _ = []
rotate l 0 = l
rotate (x:xs) n = rotate (xs ++ [x]) (n-1)


double :: [Double] -> [Double]
double elem = [m*2 | m <- elem]



divider :: [Integer] -> [[Integer]]
divider [] = []
divider elem = (helper (head elem) 1 ) : (divider (tail elem))

helper :: Integer -> Integer -> [Integer]
helper p i
        | i == p 		= i:[]
        | p `mod` i == 0	= i : (helper p (i+1))
        | otherwise 		= helper p (i+1)




allUpper :: String -> String
allUpper str = [myUpper ch | ch <-str]

myUpper :: Char -> Char
myUpper ch 
	| ch >= 'a' && ch <= 'z' 		= chr (ord ch + ord 'A' - ord 'a')
	|otherwise 				= ch


triangles :: Integer -> [(Integer, Integer, Integer)]
triangles n = [(a,b,c) | a <- [1..n], b <- [1..n],  c <- [1..n], a+b > c, a+c > b, c+b > a] 

