-- take 5 ((stream (^2)) 0)

{-
stream :: (Double -> Double) -> (Double -> [Double])
stream f = (\x -> ([ f(p x i) | i<-[0,1..]]))
 where 
 p :: Double -> Int -> Double
 p x i 
	| (i `mod` 2 == 0) = (x + (fromIntegral i/2))
	| otherwise = ((fromIntegral i^3) * x)
-}
type Func = (Double->Double)
maxDoubleFunction :: [Func] -> (Double -> Double -> Double)
maxDoubleFunction list = (\x y -> maximum (map (\f -> (f x) * (f y)) list)) 

	