tr1 :: Int -> Int -> Bool
tr1 x y
	| x < y = True
	| otherwise = False
 

monup :: [Int] -> Int
monup x
	| length x <= 1 =1
	| tr1 (head x) (x!!1) = monup (tail x)
	| otherwise =0


tr2 :: Int -> Int -> Bool
tr2 x y
	| x > y = True
	| otherwise = False

mondo :: [Int] -> Int
mondo x
	| length x <=1 =1
	| tr2 (head x) (x!!1) = mondo (tail x)
	| otherwise =0

final :: [Int] -> Int
final x
	| monup x == 1 =1
	| mondo x == 1 =(-1)
	| otherwise =0
