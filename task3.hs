{- hel::[Int]->[Int]
hel [] = []
hel (y:ys) = ys

change :: [Int] -> [Int]
change [] = []
change (x:xs) = negate x : change (hel xs)
-}


task :: [Double] -> [Double]
task [] = []
task list
	| length list == 1    = negate (head list) : task(tail list)
	| otherwise = d
	where d = negate (head list) : list!!1 : task (drop 2 list)
{-

task :: [Int] -> [Int]
task list
	| length list == 0   = []
	| length list == 1   = negate (head list) : task(tail list)
	| otherwise = negate (head list) : (list!!1) : task (drop 2 list)
-}