import Data.Char 

type Author = String
type Book = (Author, Int, Double)

mostPopular::[Book] -> (Book -> Double) -> Book
mostPopular list f = g f list (maximum (map f list))
 where
  g :: (Book -> Double) -> [Book] -> Double -> Book
  g f (x:xs) d 
   | ((f x) == d) = x
   | otherwise = g f xs d
  
popularity :: Book -> Double
popularity book = (fromIntegral (sndElem book)+(trdElem book))

sndElem :: Book -> Int
sndElem (_,x,_) = x

trdElem :: Book -> Double
trdElem (_,_,x) = x

{-
type Func = (Double->Double)
maxFunction2 :: [Func] -> Func
maxFunction2 funcList = (\x -> maximum (map (\f -> (f x)) funcList) )
-}

{-
type Func = (Double->Double)
maxDoubleFunction :: [Func] -> (Double->Double-Double)
maxDoubleFunction (x:xs) = map max
-}

{-
stream :: (Double -> Double) -> [Double]
stream f = take 5 (g f 0 0)

g :: (Double -> Double) -> Int -> Int -> [Double]
g f x i 
 | (i `mod` 2 == 0) = (f(fromIntegral x + fromIntegral i/2)) : (g f x (i+1)) 
 | otherwise = (f((fromIntegral i^3) * fromIntegral x)) : (g f x (i+1))


stream :: (Double -> Double) -> (Double ->[Double])
stream f = g f 0.0 

g :: (Double -> Double) -> 
g f x = (\x -> [ p f x i | i<-[0,1..])
p :: (Double -> Double) -> Double -> Int -> (Double -> Double)
p f x i
 | (i `mod ` 2 == 0) = (\x -> f(x+ fromIntegral i/2)
 | otherwise = (\x -> f((fromIntegral i^3)*x)

-}








