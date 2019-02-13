-- generate f g n(cqlo chislo) -> f . f(x,y) = suma  (i = 0, n) (i*f (x) + g(i*y))
-- f, g : R -> R
-- generate f g n = foldl op null l  // edno izvikvane na foldl


generate :: (Int -> Int) -> (Int -> Int) -> Int ->  (Int -> Int -> Int)
generate f g n = foldl (\f1 f2 -> (\x y -> f1 x y + f2 x y)) (\x y -> 0) (map (\i -> (\x y -> i*(f x) + g(i*y))) [0..n]) 


--curried functions
{-
sum x y = x+y
f = sum 1
f 3 = 4
-}

-- filter (>0) [1,-1,4]
-- 		  ((<)0)
--		  (x -> x>0)

negateAll :: [Int] -> [Int]
negateAll l = map (\x -> (abs x)* (-1)) l -- moje i negateAll = map (\x -> (abs x)* (-1))

-- f.g = h(x) = f(g(x))
-- h(x) = x^2 + 3 , g(x) = x^2 , f(x) = x + 3
 -- ((\x -> x + 3).(\x -> x*x))


negateAll2 :: [Int] -> [Int]
negateAll2 = map ( (*(-1)).abs)

flip' :: (a -> b -> c) -> (b -> a -> c)
flip' f = (\x y -> f y x) -- flip' f x y = f y x 

-- EXTRA

data Point = Point Double Double

getX :: Point -> Double
getX (Point x _) = x

getY :: Point -> Double
getY (Point _ y) = y

data Person = Person
			{ 
				name :: String,
				pin :: String,
				address :: String,
				age :: Integer
			}
--type Person = (String, String, String, Integer)
{-		
name :: Person -> String
name (Person n _ _ _ ) = n
-}

{-
JASON, Java Script Object Notation

-Object
-Number
-String
-Bool
-Array

{ "name": "Miro", "age": 27, "address": ["Sofia", "Plovdiv"], "university:": {} }
-}

rect = Rectangle (Point 0 0) (Point 10 2)
circ = Circle (Point 3 3) 20

--pravougulnik i krug
data Shape =
		Rectangle Point Point|
		Circle Point Double

print' :: Shape -> String
print' (Rectangle (Point tx ty) (Point bx by)) = 
	"[(" ++ (show tx) ++ ", " ++ (show ty) ++ "), (" ++ (show bx) ++ ", " ++ (show by) ++ ")]"
print' (Circle (Point x y) r) = 
	"((" ++ (show x) ++ ", " ++ (show y) ++ ", " ++ (show r) ++ ")"
		

		
width :: Shape -> Double
width (Rectangle tl br) = getX br - getX tl
width (Circle _ r) = 2*r

height :: Shape -> Double
height (Rectangle tl br) = getY br - getY tl
height (Circle _ r) = 2*r
			
area :: Shape -> Double
area (Circle _ r) = pi * r * r
area shape = (width shape) * (height shape)
		
boundingBox :: Shape -> Shape
boundingBox (Rectangle tl br) = Rectangle tl br
boundingBox (Circle (Point x y) r) = 
	Rectangle (Point (x-r) (y-r)) (Point (x+r) (y+r))
	
	
{-
stream f -> [ f0, f1, ...]
fi(x) = { f(x +i/2), i chetno
		  f( i^3x), inache
-}

stream :: (Double -> Double) -> Int -> [Double]
stream f x = take 5 (g f x 0) 
g :: (Double -> Double) -> Int -> [Double]
g f x i
	| i 'mod' 2 == 0 = f(x + fromIntegral i/2) : g f x (i+1)
	| otherwise = f((fromIntegral i^3)*x) : g f x (i+1) 




primes :: [Integer]
primes = sieve [2..]

sieve :: [Integer] -> [Integer]
sieve (x:xs) = x : sieve [y | y <- xs, y `mod` x > 0] 