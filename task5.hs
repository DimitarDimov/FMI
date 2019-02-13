{-
com :: Char -> Char -> Bool
com x y 
	| x == y = True
	| otherwise = False

str :: String -> String
str [] = []
str (x:xs)
 | length (x:xs) ==2 = x:xs
 | com x (head xs) = str xs
 | otherwise = x : str xs

	
	
			
com :: Char -> Char -> Bool
com x y 
	| x == y = True
	| otherwise = False
-}
str :: String -> String
str list
 | length list == 0 = ""
 | (head list) == (last list)  = head list : ""
 | head list /= list!!1 = head list : str(tail list)
 | otherwise = str(tail list)
	