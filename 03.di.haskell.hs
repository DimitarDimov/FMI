{- 08.09.2010 -}
{-
Задача 2 (5 т.) Да се дефинира на езика Хаскел функцията sumProd, която по даден списък от
списъци от цели числа ll да намира сумата от произведенията на елементите на тези списъци в
ll, които не съдържат отрицателни числа.
-}
sumProd :: [[Integer]] -> Integer
-- вариант 1: list comprehension
sumProd_lc xss = sum [product xs | xs <- xss, all (>0) xs]
-- вариант 2: map & filter
sumProd_map xss = sum (map product (filter (all (>0)) xss))
-- вариант 3: рекурсия без sum/product
sumProd [] = 0
sumProd (xs:xss) = if and [x > 0 | x <- xs] then prod xs else 0 + sumProd xss where 
    prod :: [Integer] -> Integer
    prod [] = 1
    prod (x:xs) = x * prod xs

-- N.B. Дефиниции на sum/product посредством foldr
sum' :: (Num a, Foldable b) => b a -> a
sum' xs = foldr (+) 0 xs

product' :: (Num a, Foldable b) => b a -> a
product' xs = foldr (*) 1 xs

{-
Задача 3 (15 т.) Дадени са следните дефиниции на типове на езика Хаскел, описващи:
Пътуване (Trip) като наредена тройка от крайна дестинация, дължина в километри и цена
Екскурзия (Tour) като списък от пътувания

type Trip = (String, Integer, Float)
type Tour = [Trip]

Да се дефинират функции:
- discount, която по дадена екскурзия намира нова екскурзия, в която цената на всяко
пътуване с дължина над len км е намалена с 10%.

- shortenTour, която по дадена екскурзия намира нова екскурзия, в която всяка
последователност от пътувания, започваща от дестинация from и завършваща в
дестинация to е заменена с единственото пътуване trip. Внимание: последователност,
отговаряща на описанието започва непосредствено след пътуване, чиято крайна
дестинация е from, но не го включва!
-}
type Trip = (String, Integer, Float)
type Tour = [Trip]

discount :: Tour -> Integer -> Tour
discount tour len = [(destination, length, (if length > len then 0.9 else 1) * price) | (destination, length, price) <- tour]

shortenTour :: Tour -> String -> String -> Trip -> Tour
shortenTour [] _ _ _ = []
shortenTour (t@(dst, len, price):ts) from to trip
    | dst == from   = t:shortenTo ts ts from to trip
    | otherwise     = t:shortenTour ts from to trip

shortenTo :: Tour -> Tour -> String -> String -> Trip -> Tour
shortenTo original [] _ _ _ = original
shortenTo original ((dst, len, price):ts) from to trip
    | dst == to = trip : shortenTour ts from to trip
    | otherwise = shortenTo original ts from to trip   


{- 15.07.2014 -}
{-
Задача 3. (10 т.) Задачата да се реши на езика Scheme или Haskell. В началото на вашето
решение посочете кой език сте избрали.

А) Напишете функция totalMin, която за списък от едноместни числови функции връща тази
функция f от списъка, за която f(0) е минимално.

Б) Напишете функция chainMinCompositions, която получава като аргумент едноместна
числова функция f и генерира безкрайния поток (за Хаскел – безкрайния списък) F0, F1, , … ,
където:

 | F0 = id
 | F1 = f
 | Fi = F(i-1) ◦ F(i-2), ако i > 1 и F(i-1) j /= F(i-2) j, за някое цяло число j, в [0 .. i]
 | Fi = totalMin [F0, F1, .. F(i-1)] ако i > 1 и F(i-1) j == F(i-2) j, за всяко цяло число j, в [0 .. i]

Забележка: с id е означена функцията „идентитет”, като id(x) = x за произволно x, а с f ◦ g е
означена композицията на функциите на f и g, като (f ◦ g)(x) = f(g(x)).
-}
totalMin :: (Num a, Ord b) => [(a -> b)] -> (a -> b)
totalMin fs = foldr1 (\f fMin -> if f 0 < fMin 0 then f else fMin) fs

chainMinCompositions :: (Enum a, Num a, Ord a) => (a -> a) -> [(a -> a)]
chainMinCompositions f = [f' i | i <- [0 ..]] where
    f' i
        | i == 0    = id
        | i == 1    = f
        | otherwise = if and [f' (i - 1) j == f' (i - 2) j | j <- [0 .. i]] 
                        then totalMin [f' k | k <- [0 .. i - 1]]
                        else (f' (i - 1)) . (f' (i - 2))


{- 11.09.2014 -}
{-
Задача 3. (10 т.) Задачата да се реши на езика Scheme или Haskell. В началото на вашето
решение посочете кой език сте избрали.
Нека е даден списък L, който може да съдържа елементи от произволен тип. Напишете функция
permutations, която получава такъв списък и връща списък с всички пермутации (възможни
пренареждания) на неговите елементи. Резултатът да се върне като списък от списъци, в който
всеки подсписък представя една пермутация на елементите на L.

Пример (Scheme):
(permutations '(1 2 3)) → ( (1 2 3) (1 3 2) (2 1 3) (2 3 1) (3 1 2) (3 2 1) )

Пример (Haskell):
permutations [1,2,3] → [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
-}
permutations :: [a] -> [[a]]
permutations [] = [[]]
permutations xs = concat [[x:ps | ps <- permutations [y | (j, y) <- ixs, j /= i]] | (i, x) <- ixs] where
    ixs = zip [0..] xs

-- Второ решение:
permutations_2 :: [a] -> [[a]]
permutations_2 [] = [[]]
permutations_2 (x:xs) = concat [x `insertAtEveryPosition` p | p <- permutations_2 xs]

-- x `insertAtEveryPosition` xs: добавя x на всяка възможна позиция в xs.
-- Пример: 1 `insertAtEveryPosition` [2, 3] -> [[1, 2, 3], [2, 1, 3], [2, 3, 1]]
insertAtEveryPosition :: a -> [a] -> [[a]]
e `insertAtEveryPosition` [] = [[e]]
e `insertAtEveryPosition` (x:xs) = (e:x:xs) : map (x:) (e `insertAtEveryPosition` xs)


{- 10.09.2015 -}
merge :: (Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) = if x < y 
                        then x:merge xs (y:ys) 
                        else y:merge (x:xs) ys

evens = \ys -> [y | y <- ys, even y]


-- примерни извиквания и задачи тип "какво ще се случи ..."
main :: IO()
main = do
    putStrLn "08.09.2010: sumProd"
    print $ sumProd [[1..0], [1..1], [1..2], [1..3]]
    putStrLn ""

    putStrLn "11.09.2014: permutations"
    print $ permutations ([] :: [Int])
    print $ permutations [1]
    print $ permutations [1, 2]
    print $ permutations [1, 2, 3]
    putStrLn "permutations_2"
    print $ permutations_2 ([] :: [Int])
    print $ permutations_2 [1]
    print $ permutations_2 [1, 2]
    print $ permutations_2 [1, 2, 3]
    putStrLn ""

    putStrLn "14.07.2015"
    print $ map (head [(\couple -> fst couple + snd couple)]) (foldr1 (++) [[(1,2)],[(3,4)]])
    print $ [zip [x] [x] | x <- [1..5]]
    print $ map (\(x:y:z) -> x:z) [[1,2,3],[2,3,1],[3,1,2]]
    putStrLn ""

    putStrLn "10.09.2015"
    print $ merge [1,3,5,7] [2,2,6,10]
    print $ (\ys -> [y | y <- ys, even y])[1, 2, 3, 4]
    putStrLn ""

    putStrLn "12.07.2016"
    print $ [x : [x] | x <- [[1,2], [3,4]]]
    print $ [map (f 5) [1,2,3] | f <- [(+), (-), (*)]]
    print $ "a" : [['b', 'c'], "d"]
    putStrLn ""

